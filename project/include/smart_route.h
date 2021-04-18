/**
 * @file smart_route.h
 */

#ifndef SMART_ROUTE_H_
#define SMART_ROUTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "route.h"
#include  "delivery_simulation.h"

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
  class SmartRoute : public IRoute {
    public: 
      SmartRoute(const IGraph* graph);
      virtual std::queue<Vector3D> GetRoute(
          std::vector<float> src, std::vector<float> dest) override;

    private: 
      const IGraph* graph_;
  };
} // namespace csci3081
#endif // SMART_ROUTE_H_
