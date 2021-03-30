#include "courier.h"
#include "vector_2d.h"

namespace csci3081 {

  Courier::Courier(const picojson::object& details) : EntityBase(details) {
    destination_ = Vector3D(this->GetPosition());
    path_type_ = kSmart; // default value of path_type_
    speed_ = JsonHelper::GetDouble(details, "speed");
    int battery_capacity = -1; 
    try {
      battery_capacity = (int) JsonHelper::GetDouble(details, "battery_capacity");
      battery_ = Battery(battery_capacity);
    } catch (...) { // use default battery capacity
    } // catch
    package_ = nullptr; // no package to begin with
    status_ = kReady; // free to use this courier to deliver new package
    dynamic_ = true;
    graph_ = nullptr;
    beeline_height_ = 450; 
  } // Courier(const picojson::object&)

  std::vector<float> Courier::GetDestination() const {
    return destination_.GetComponents();
  } // GetDestination()

  void Courier::SetDestination(std::vector<float> destination) {
    destination_ = Vector3D(destination);
    route_ = std::queue<Vector3D>();
    Vector3D point_2, point_3; // used when path_type_ == kBeeline
    switch (path_type_) {
      case kSmart:
        if (graph_) {
          std::vector<std::vector<float>> path = graph_->GetPath(
              position_.GetComponents(), destination); 
          for (std::vector<float> point : path) { // fill route queue
            route_.push(Vector3D(point));
          } // for
        } 
        break;
      case kBeeline:
        point_2 = position_;
        point_3 = destination_;
        point_2.SetY(beeline_height_);
        point_3.SetY(beeline_height_);
        route_.push(position_);
        route_.push(point_2);
        route_.push(point_3);
        route_.push(destination_);
        break;
      case kParabolic:
        std::cerr << "Error: parabolic not yet implemented" << std::endl;
        break;
      default:
        break;
    } // switch
  } // SetDestination(std::vector<float>) 

  float Courier::GetSpeed() const {
    return speed_;
  } // GetSpeed()

  void Courier::SetSpeed(float speed) {
    speed_ = speed;
  } // SetSpeed(float)

  Battery& Courier::GetBattery() {
    return battery_;
  } // GetBattery()

  Package* Courier::GetPackage() const {
    return package_;
  } // GetPackage()

  void Courier::SetPackage(Package* package) {
    package_ = package;
    this->SetDestination(package->GetPosition());
    status_ = kAcquirePackage;
  } // SetPackage(Package*)

  void Courier::SetGraph(const IGraph* graph) {
    graph_ = graph;
  } // SetGraph(const IGraph*)

  void Courier::SetPathType(std::string path_type) {
      if (path_type == "smart") {
        path_type_ = kSmart;
      } else if (path_type == "beeline") {
        path_type_ = kBeeline;
      } else if (path_type == "parabolic") {
        path_type_ = kParabolic;
      } // else if 
  } // SetPathType(Path)

  bool Courier::HasPackage() {
    return package_ != nullptr && status_ == kDeliverPackage;
  } // HasPackage()

  bool Courier::IsAvailable() {
    return status_ == kReady;
  } // HasPackage()

  void Courier::DropoffPackage() {
    // teleport package out of camera view
    package_->SetPosition(Vector3D(0, -10000, 0));
    package_ = nullptr;
    status_ = kReady;
  } // DropoffPackage()

  void Courier::Move(float dt) {
    Vector3D direction;
    // only loop once if not at current goal point in smart route otherwise
    // get the next target point in route and update direction.
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
    Vector2D direction_2d(direction.GetComponents());
    if (direction_2d.Magnitude() > this->GetRadius()) {
      this->SetDirection(direction_2d);
    } // if
    position_ = position_ + direction.Normalize().Scale(speed_*dt);
    if (this->HasPackage()) { 
    // keep package tethered to courier
      package_->SetPosition(position_); 
    } // if
  } // Move()

  void Courier::Update(float dt) {
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
      if (battery_.IsDead()) {
        std::cerr << "Battery is dead" << std::endl;
      } else {
        this->Move(dt);
        battery_.Deplete(dt);
      } // else battery
    } // else
  } // Update(float) 

} // namespace csci3081
