/**
 * @file robot_factory.h
 */

#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "json_helper.h"
#include "robot.h"
#include <EntityProject/entity_factory.h>

using entity_project::IEntity;
using entity_project::IEntityFactory;

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Factory which handles Robot entity creation.
   */
  class RobotFactory : public IEntityFactory {
    public:
      /**
       * @brief Default Constructor: Instantiates a RobotFactory object
       */ 
      RobotFactory();

      /**
       * @brief Attempts to create the specified Robot entity.
       *
       * @param details A picojson object containing the requested Robot
       *                enitity details. 
       * @return A pointer to the created Robot, or nullptr if unable to create
       *         the the requested Robot entity.
       */ 
      IEntity* CreateEntity(const picojson::object& details) override;
  };

} // namespace csci3081
#endif // ROBOT_FACTORY_H_
