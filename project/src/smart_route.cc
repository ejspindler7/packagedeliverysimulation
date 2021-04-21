#include "smart_route.h"
#include <iostream>

namespace csci3081 {

  SmartRoute::SmartRoute(const IGraph* graph) {
    graph_ = graph;
  } // SmartRoute(const IGraph*)

  std::queue<Vector3D> SmartRoute::GetRoute(std::vector<float> src,
                                            std::vector<float> dest) {
    std::queue<Vector3D> route;
    if (graph_) {
      std::vector<std::vector<float>> path = graph_->GetPath(src, dest);
      for (std::vector<float> point : path) { // fill route queue
        route.push(Vector3D(point));
      } // for
    } else {
      std::cerr << "ERROR: Graph not set in smart route strategy instance"
                << std::endl;
    } // else
    return route;
  } // GetRoute(std::vector<float>, std::vector<float>)
} // namespace csci3081
