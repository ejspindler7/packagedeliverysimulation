/**
 * @file beeline_route.h
 */

#ifndef BEELINE_ROUTE_H_
#define BEELINE_ROUTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "route.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Beeline route between source and destination points
   *
   * To be used by couriers in finding routes to packages and customers
   *
   */
  class BeelineRoute : public IRoute {
    public: 
      BeelineRoute(float beeline_height = 400);
      virtual std::queue<Vector3D> GetRoute(
         std::vector<float> src, std::vector<float> dest) override;

    private:
      float beeline_height_;
  };
} // namespace csci3081
#endif // BEELINE_ROUTE_H_
