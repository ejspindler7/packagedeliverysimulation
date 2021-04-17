#include "beeline_route.h"

namespace csci3081 {

  BeelineRoute::BeelineRoute(float beeline_height) {
    beeline_height_ = beeline_height;
  } // BeelineRoute(float beeline_height)

  std::queue<Vector3D> BeelineRoute::GetRoute(std::vector<float> src,
                                              std::vector<float> dest) {
    std::queue<Vector3D> route;
    Vector3D point_1(src);
    Vector3D point_2(src);
    point_2.SetY(beeline_height_);
    Vector3D point_3(dest);
    point_3.SetY(beeline_height_);
    Vector3D point_4(dest);
    route.push(point_1);
    route.push(point_2);
    route.push(point_3);
    route.push(point_4);
    return route;
  } // GetRoute(std::vector<float>, std::vector<float>)
} // namespace csci3081
