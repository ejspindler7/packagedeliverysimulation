#include "package.h"

namespace csci3081 {

  Package::Package(const picojson::object& object) : EntityBase(object) { 
    if (JsonHelper::GetString(object, "type") != "package") {
      throw "Error: Cannot create requested entity";
    } // if
    destination_ = Vector3D(this->GetPosition());
    weight_ = -1;
    customer_ = nullptr;
  } // Package(const picojson::object& object)

  std::vector<float> Package::GetDestination() {
    return destination_.GetComponents();   
  } // GetDestination()

  void Package::SetDestination(std::vector<float> destination) {
    destination_ = Vector3D(destination);
  } // SetDestination(std::vector<float> destination)

  float Package::GetWeight() const {
    return weight_;
  } // GetWeight()

  void Package::SetWeight(float weight) {
    weight_ = weight;
  } // SetWeight(float weight)

  Customer* Package::GetCustomer() {
    return customer_;
  } // GetCustomer()

  void Package::SetCustomer(Customer* customer) {
    customer_ = customer;
  } // SetCustomer(const Customer* customer)

} // namespace csci3081
