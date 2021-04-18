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
      /**
       * @brief Returns the Route for the given IRoute instance 
       *
       * @param src Float value representing where the route begins 
       * 
       * @param dest Float value representing where the route ends 
       * 
       * @return a queue of Vector3D points that make up the route 
       */ 
      virtual std::queue<Vector3D> GetRoute(std::vector<float> src,
                                            std::vector<float> dest) = 0;
      /**
       * @brief Destructor: deletes the IRoute pointer
       *
       */
      virtual ~IRoute() { }
  };
} // namespace csci3081
#endif // ROUTE_H_
