#include "courier.h"
#include "smart_route.h"
#include "beeline_route.h"
#include "parabolic_route.h"
#include "vector_2d.h"

namespace csci3081 {
//create methods for observer
  Courier::Courier(const picojson::object& details) : EntityBase(details) {
    destination_ = Vector3D(this->GetPosition());
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
    route_strategy_ = nullptr; 
    graph_ = nullptr;
    numNotify = 0;
  } // Courier(const picojson::object&)

  Courier::~Courier() {
    if (route_strategy_)
      delete route_strategy_;
  } // ~Courier()

  std::vector<float> Courier::GetDestination() const {
    return destination_.GetComponents();
  } // GetDestination()

  std::vector<std::vector<float>> QueueConvert(std::queue<Vector3D> route){
    std::vector<std::vector<float>> to_ret;
    while(!route.empty()){
      to_ret.push_back(route.front().GetComponents());
      route.pop();
    }
    return to_ret;
  } // QueueConvert()

  void Courier::SetDestination(std::vector<float> destination) {
    destination_ = Vector3D(destination);
    this->UpdateRoute();
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

  void Courier::UpdateRoute() {
    if (route_strategy_)
      route_ = route_strategy_->GetRoute(position_.GetComponents(), 
                                         destination_.GetComponents());
  } // UpdateRoute()

  std::vector<std::vector<float>> Courier::GetRoute() const{
    return QueueConvert(route_);
  } // GetRoute()

  void Courier::SetPackage(Package* package) {
    package_ = package;
    this->SetDestination(package->GetPosition());
    status_ = kAcquirePackage;
  } // SetPackage(Package*)

  void Courier::SetGraph(const IGraph* graph) {
    graph_ = graph;
    if (!route_strategy_) {
      route_strategy_ = new SmartRoute(graph_);
    } // if
  } // SetGraph(const IGraph*)

  void Courier::SetPathType(std::string path_type) {
    const IRoute* current = route_strategy_;
    if (path_type == "smart") {
      if (graph_) {
        route_strategy_ = new SmartRoute(graph_);
      } // if
    } else if (path_type == "beeline") {
      route_strategy_ = new BeelineRoute();
    } else if (path_type == "parabolic") {
      route_strategy_ = new ParabolicRoute();
    } else {
      return;
    } // else
    if (current) {
      delete current;
    } // if
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
    package_->SetDelivered(true);
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

  int Courier::GetStatus(){
    return status_;
  } // GetStatus()

  void Courier::setNotification(int num){
    numNotify = num;
  } // setNotification(int)

  int Courier::getNotification(){
    return numNotify;
  } // getNotification()
} // namespace csci3081
