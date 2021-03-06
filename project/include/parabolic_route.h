/**
 * @file parabolic_route.h
 */

#ifndef PARABOLIC_ROUTE_H_
#define PARABOLIC_ROUTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "route.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Smart route (A*) between source and destination points
   *
   * To be used by couriers in finding routes to packages and customers
   *
   */
  class ParabolicRoute : public IRoute {
    public: 
      /**
       * @brief Constructor: instantiates a ParabolicRoute object 
       *  
       * @param steps An integer value to represent the steps taken in the route 
       *                   Default value of 100.
       * 
       * @param base_height An integer value to represent a base value for the height of the route
       *                    Default value of 300
       * 
       * @param max_height An integer value to represent the maximum height of the route
       *                    Default value of 400
       */ 
      ParabolicRoute(int steps = 100, int base_height = 300, int max_height = 400);
      virtual std::queue<Vector3D> GetRoute(
          std::vector<float> src, std::vector<float> dest) override;

    private:
      int steps_;
      int base_height_;
      int max_height_;
  };
} // namespace csci3081
#endif // PARABOLIC_ROUTE_H_
