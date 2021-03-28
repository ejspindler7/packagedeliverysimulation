/**
 * @file robot.h
 */

#ifndef ROBOT_H_
#define ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "courier.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Class for storing Robot information
   *
   * Robot's are able to pickup and deliver packages to other
   * entities by following a smart route 
   */
  class Robot : public csci3081::Courier {

    public:
      /**
       * @brief Constructor.
       *  
       * Creates the requested Robot entity. 
       *
       * @param details A picojson object containing requested robot details. 
       */ 
      Robot(const picojson::object& details);
  };

} // namespace csci3081
#endif // ROBOT_H_
