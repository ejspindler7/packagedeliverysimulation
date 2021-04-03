#include "vector_3d.h"
#include <cmath>

namespace csci3081 {

  Vector3D::Vector3D(float x, float y, float z) {
    xyz_components_ = std::vector<float> {x, y, z};
  } // Vector3D(float, float, float)

  Vector3D::Vector3D(const std::vector<float>& vec) : Vector3D() {
    // initializes to default values if vec size is not 3
    if (vec.size() == 3) {
      xyz_components_ = vec;
    } // if
  } // Vector3D(float, float, float)

  float Vector3D::GetX() const {
    return xyz_components_.at(0);
  } // GetX()

  void Vector3D::SetX(float x) {
    xyz_components_.at(0) = x;
  } // SetX()

  float Vector3D::GetY() const {
    return xyz_components_.at(1);
  } // GetY()

  void Vector3D::SetY(float y) {
    xyz_components_.at(1) = y;
  } // SetY()

  float Vector3D::GetZ() const {
    return xyz_components_.at(2);
  } // GetZ()

  void Vector3D::SetZ(float z) {
    xyz_components_.at(2) = z;
  } // SetZ()

  const std::vector<float>& Vector3D::GetComponents() const {
    return xyz_components_;
  } // GetComponents()

  void Vector3D::SetComponents(float x, float y, float z) {
    this->SetX(x);
    this->SetY(y);
    this->SetZ(z);
  } // SetComponents(float, float, float)

  void Vector3D::SetComponents(const std::vector<float>& vec) {
    // has no effect if vec is not of length 3
    if (vec.size() == 3) { 
      xyz_components_ = vec;
    } // if
  } // SetComponents(const vector<float>)

  Vector3D& Vector3D::Normalize() {
    // zero vector cannot be normalized
    // x = x/norm
    // y = y/norm
    // z = z/norm
    float normalizing_factor = this->Magnitude();
    if (normalizing_factor != 0.0) {
      for (int i = 0; i < xyz_components_.size(); i++) {
        xyz_components_.at(i) /= normalizing_factor;
      } // for
    } // if
    return *this;
  } // Normalize()

  Vector3D& Vector3D::Scale(float k) {
    for (int i = 0; i < xyz_components_.size(); i++) {
      xyz_components_.at(i) *= k;
    } // for
    return *this;
  } // Scale(float)

  float Vector3D::Magnitude(){
    // (x^2 + y^2 + z^2)^(1/2)
    float norm = 0.0;
    for (int i = 0; i < xyz_components_.size(); i++) {
      norm += std::pow(xyz_components_.at(i), 2.0); 
    } // for
    return std::sqrt(norm);
  } // Magnitude()

  Vector3D& Vector3D::ReverseDirection() {
    return this->Scale(-1);
  } // ReverseDirection()

  float Vector3D::DotProduct(const Vector3D& vec) {
    // (this.x * vec.x) + (this.z * vec.y) + (this.z * vec.z)
    float dot_product = 0.0; 
    for (int i = 0; i < xyz_components_.size(); i++) {
      dot_product += this->xyz_components_.at(i) * vec.xyz_components_.at(i); 
    } // for
    return dot_product;
  } // DotProduct(Vector3D&)

  Vector3D Vector3D::CrossProduct(const Vector3D& vec) {
    // x = a2b3 - a3b2
    // y = a3b1 - a1b3
    // z = a1b2 - a2b1
    std::vector<float> cross_product = {
      this->GetY() * vec.GetZ() - this->GetZ() * vec.GetY(),   
      this->GetZ() * vec.GetX() - this->GetX() * vec.GetZ(),
      this->GetX() * vec.GetY() - this->GetY() * vec.GetX()};
    Vector3D vector3d_cross_product(cross_product);
    return vector3d_cross_product;
  } // CrossProduct(const Vector3D&)

  Vector3D Vector3D::operator+(const Vector3D& rhs) {
    // x = a1 + b1
    // y = a2 + b2
    // z = a3 + b3
    std::vector<float> vector_sum = {
      this->GetX() + rhs.GetX(),   
      this->GetY() + rhs.GetY(),   
      this->GetZ() + rhs.GetZ()};
    Vector3D vector3d_sum(vector_sum);
    return vector3d_sum;
  } // operator+(const Vector3D&)

  Vector3D Vector3D::operator-(const Vector3D& rhs) {
    // x = a1 - b1
    // y = a2 - b2
    // z = a3 - b3
    Vector3D rhs_copy = rhs;
    rhs_copy.ReverseDirection();
    return *this + rhs_copy;
  } // operator-(const Vector3D&)

  bool Vector3D::operator==(const Vector3D& rhs) {
    float epsilon = 0.0001;
    if (std::fabs(this->GetX() - rhs.GetX()) < epsilon) {
      if (std::fabs(this->GetY() - rhs.GetY()) < epsilon) {   
        if (std::fabs(this->GetZ() - rhs.GetZ()) < epsilon) {
          return true;
        } // if z
      } // if y
    } // if x
    return false;
  } // operator==(const Vector3D&)

} // namespace csci3081
