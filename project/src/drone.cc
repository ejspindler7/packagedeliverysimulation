#include "drone.h"
#include "vector_2d.h"

namespace csci3081 {

  Drone::Drone(const picojson::object& details) : EntityBase(details) {
    if (JsonHelper::GetString(details, "type") != "drone") {
      throw "Error: Cannot create requested entity";
    } // if
    destination_ = Vector3D(this->GetPosition());
    speed_ = JsonHelper::GetDouble(details, "speed");
    battery_ = Battery();
    package_ = nullptr; // no package to begin with
    use_smart_route_ = true; // when smart_route is false, use b-line route
    status_ = kReady; // free to use this drone to deliver new package
    dynamic_ = true;
    graph_ = nullptr;
    beeline_height_ = 350; 
  } // Drone(const picojson::object&)

  std::vector<float> Drone::GetDestination() const {
    return destination_.GetComponents();
  } // GetDestination()

  void Drone::SetDestination(std::vector<float> destination) {
    destination_ = Vector3D(destination);
    if (graph_) {
      route_ = std::queue<std::vector<float>>(); // empty route queue
      std::vector<std::vector<float>> path = graph_->GetPath(
          position_.GetComponents(), destination); 
      for (std::vector<float> point : path) { // fill route queue
        route_.push(point);
      } // for
    } // if
  } // SetDestination(std::vector<float>) 

  float Drone::GetSpeed() const {
    return speed_;
  } // GetSpeed()

  void Drone::SetSpeed(float speed) {
    speed_ = speed;
  } // SetSpeed(float)

  Battery& Drone::GetBattery() {
    return battery_;
  } // GetBattery()

  Package* Drone::GetPackage() const {
    return package_;
  } // GetPackage()

  void Drone::SetPackage(Package* package) {
    package_ = package;
    this->SetDestination(package->GetPosition());
    status_ = kAcquirePackage;
  } // SetPackage(Package*)

  void Drone::SetGraph(const IGraph* graph) {
    graph_ = graph;
  } // SetGraph(const IGraph*)

  bool Drone::UsingSmartRoute() {
    return use_smart_route_;
  } // UsingSmartRoute()

  void Drone::SetSmartRoute(bool smart) {
    use_smart_route_ = smart;
  } // SetSmartRoute(bool)

  bool Drone::HasPackage() {
    return package_ != nullptr && status_ == kDeliverPackage;
  } // HasPackage()

  bool Drone::IsAvailable() {
    return status_ == kReady;
  } // HasPackage()

  void Drone::DropoffPackage() {
    // teleport package out of camera view
    package_->SetPosition(Vector3D(0, -10000, 0));
    package_ = nullptr;
    status_ = kReady;
  } // DropoffPackage()

  void Drone::UpdatePosition(float dt) {
    // set direction before changing position
    Vector3D direction;
    if (use_smart_route_) {
      // only loop once if not at current goal point in smart route otherwise
      // get the next target point in smart route and update direction.
      for (int i = 0; i < 2; i++) {
        if (!route_.empty()) {
          direction = Vector3D(route_.front()) - position_;
          if (direction.Magnitude() < this->GetRadius()) {
            route_.pop();
          } else {
            break;
          } // else
        } // if 
      } // for
      this->SetDirection(Vector2D(direction.GetComponents())); 
    } else { // b-line
      Vector3D difference = destination_ - position_;
      // cast to Vector2D to ignore height (y-comp)
      Vector2D difference_2D(difference.GetComponents()); 
      if (difference_2D.Magnitude() < this->GetRadius()) {
        // drone is above destination so should descend
        direction = Vector3D(0,-1,0);
      } else if (position_.GetY() < beeline_height_) {
          direction = Vector3D(0, 1, 0);
      } else {
        direction = Vector2D(difference.GetComponents());
        this->SetDirection(direction); 
      } // else
    } // else
    position_ = position_ + direction.Normalize().Scale(speed_*dt);
    if (this->HasPackage()) { 
    // keep package tethered to drone
      package_->SetPosition(position_); 
    } // if
  } // UpdatePosition()

  void Drone::Update(float dt) {
    if ((position_ - destination_).Magnitude() < this->GetRadius()) {
      switch (status_) {
        case kReady:
          break;
        case kAcquirePackage:
          status_ = kDeliverPackage;
          package_->SetDynamic(true);
          this->SetDestination(package_->GetDestination());
          break;
        case kDeliverPackage:
          this->DropoffPackage();
          break;
        default:
          break;
      } // switch
    } else { // move toward destination
      this->UpdatePosition(dt);
      battery_.Deplete(1);
    } // else
  } // DropoffPackage()

} // namespace csci3081
