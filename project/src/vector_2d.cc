#include "vector_2d.h"

namespace csci3081 {

  Vector2D::Vector2D(float x, float z) : Vector3D(x, 0.0, z) { }
  Vector2D::Vector2D(const std::vector<float>& vec) {
    // initializes to zero vector if vec size is not 2 or 3
    this->SetComponents(vec);
  } // Vector2D(const vector<float>&)

  void Vector2D::SetComponents(float x, float z) {
    this->SetX(x);
    this->SetZ(z);
  } // SetComponents(float, float)

  void Vector2D::SetComponents(float x, float y, float z) {
    this->Vector3D::SetComponents(x, 0.0, z);
  } // SetComponents(float, float, float)

  void Vector2D::SetComponents(const std::vector<float>& vec) {
    switch (vec.size()) {
      case 2:
        this->SetComponents(vec.at(0), vec.at(1));
        break;
      case 3:
        this->SetComponents(vec.at(0), 0.0, vec.at(2));
        break;
      default:
        break;
    } // switch
  } // SetComponents(const vector<float>)
  
} // namespace csci3081
