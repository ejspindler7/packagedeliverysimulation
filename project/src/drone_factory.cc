#include "drone_factory.h"

namespace csci3081 {

  DroneFactory::DroneFactory() { }

  IEntity* DroneFactory::CreateEntity(const picojson::object& details) {
    IEntity* drone;
    try {
      drone = new Drone(details);
    } catch (...) { // failed to create Drone entity
      return nullptr;
    } // catch (...)
    return drone;
  } // DroneFactory(picojson::object&)

} // namespace csci3081
