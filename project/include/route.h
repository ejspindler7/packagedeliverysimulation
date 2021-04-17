/**
 * @file route.h
 */

#ifndef ROUTE_H_
#define ROUTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <queue>
#include <string>
#include "vector_3d.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Interface for route strategies
   *
   * To be used by couriers in finding routes to packages and customers
   *
   */
  class IRoute {
    public: 
      virtual std::queue<Vector3D> GetRoute(std::vector<float> src,
                                            std::vector<float> dest) = 0;
      virtual ~IRoute() { }
  };
} // namespace csci3081
#endif // ROUTE_H_
