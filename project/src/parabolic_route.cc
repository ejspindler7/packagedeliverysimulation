#include "parabolic_route.h"
#include <cmath>

namespace csci3081 {

  ParabolicRoute::ParabolicRoute(int steps, int base_height, int max_height) {
    steps_ = steps;
    base_height_ = base_height;
    max_height_ = max_height;
  } // ParabolicRoute(int)

  std::queue<Vector3D> ParabolicRoute::GetRoute(std::vector<float> src,
                                                std::vector<float> dest) {
    Vector3D source(src);
    Vector3D destination(dest);
    // start of parabola
    Vector3D start = source; 
    start.SetY(base_height_);
    // endpoint of parabola
    Vector3D finish = destination; 
    finish.SetY(base_height_);
    Vector3D to_dest = finish - start;
    float dist_dest = to_dest.Magnitude();
    Vector3D mid_point = start + to_dest.Scale(0.5);
    to_dest.Normalize();
    std::queue<Vector3D> route;
    route.push(source);
    // generate points along parabola
    for (int i = 0; i <= steps_ + 1; i++) {
      Vector3D to_dest_copy = to_dest;
      Vector3D target = start + to_dest_copy.Scale((dist_dest / (steps_ + 1)) * i);
      float temp_a = pow((mid_point - target).Magnitude(), 2.0);
      float temp_b = pow((mid_point - start).Magnitude(), 2.0);
      float change_height = (1 - temp_a / temp_b) * (max_height_ - target.GetY());
      target.SetY(target.GetY() + change_height);
      route.push(target);
    } // for
    route.push(destination);
    return route;
  } // GetRoute(std::vector<float>, std::vector<float>)
} // namespace csci3081
