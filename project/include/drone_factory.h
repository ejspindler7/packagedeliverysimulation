/**
 * @file drone_factory.h
 */

#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "json_helper.h"
#include "drone.h"
#include <EntityProject/entity_factory.h>

using entity_project::IEntity;
using entity_project::IEntityFactory;

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Factory which handles Drone entity creation.
   */
  class DroneFactory : public IEntityFactory {
    public:
      /**
       * @brief Default Constructor: Instantiates a Drone Factory object 
       */ 
      DroneFactory();

      /**
       * @brief Attempts to create the specified Drone entity.
       *
       * @param details A picojson object containing the requested Drone
       *                enitity details. 
       * @return A pointer to the created Drone, or nullptr if unable to create
       *         the the requested Drone entity.
       */ 
      IEntity* CreateEntity(const picojson::object& details) override;
  };

} // namespace csci3081
#endif // DRONE_FACTORY_H_
