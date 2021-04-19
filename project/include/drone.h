/**
 * @file drone.h
 */

#ifndef DRONE_H_
#define DRONE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "courier.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Class for storing Drone information
   *
   * Drone's are able to pickup and deliver packages to other
   * entities by following either a smart route, beeline, or a parabolic path.
   */
  class Drone : public csci3081::Courier {

    public:
      /**
       * @brief Constructor: Creates the requested Drone entity
       *  
       *
       * @param details A picojson object containing requested drone details. 
       */ 
      Drone(const picojson::object& details);
  };

} // namespace csci3081
#endif // DRONE_H_
