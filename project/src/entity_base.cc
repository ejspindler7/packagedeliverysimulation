#include "entity_base.h"

namespace csci3081 {

  // initialize static class next_id_ variable
  int EntityBase::next_id_ = 0; 

  EntityBase::EntityBase(const picojson::object& details) {
    id_ = ++next_id_;
    name_ = JsonHelper::GetString(details, "name");
    position_ = Vector3D(JsonHelper::GetStdFloatVector(details, "position"));
    direction_ = Vector3D(JsonHelper::GetStdFloatVector(details, "direction"));
    radius_ = JsonHelper::GetDouble(details, "radius");
    details_ = details;
    version_ = 0;
    dynamic_ = false;
  } // EnitityBase()

  EntityBase::~EntityBase() {}

  int EntityBase::GetId() const {
    return id_;
  } // GetId()

  const std::string& EntityBase::GetName() {
    return name_;
  } // GetName() 

  const std::vector<float>& EntityBase::GetPosition() const {
    return position_.GetComponents();
  } // GetPosition()

  void EntityBase::SetPosition(std::vector<float> position) {
    position_ = Vector3D(position);
  } // SetPosition(std::vector<float>)

  void EntityBase::SetPosition(Vector3D position) {
    position_ = position;
  } // SetPosition(Vector3D)

  const std::vector<float>& EntityBase::GetDirection() const {
    return direction_.GetComponents();
  } // GetDirection();

  void EntityBase::SetDirection(const Vector3D& direction) {
    direction_ = direction;
  } // SetDirection(const Vector3D&)

  float EntityBase::GetRadius() const {
    return radius_;
  } // GetRadius()

  const picojson::object& EntityBase::GetDetails() {
    return details_;
  } // GetDetails()

  int EntityBase::GetVersion() const {
    return version_;
  } // GetVersion()

  bool EntityBase::IsDynamic() const {
    return dynamic_; 
  } // IsDynamic()

  void EntityBase::SetDynamic(bool dynamic) {
    if (dynamic_ != dynamic) {
      dynamic_ = dynamic;
      version_++;
    } // if
  } // SetDynamic(bool)

} // namespace csci3081
