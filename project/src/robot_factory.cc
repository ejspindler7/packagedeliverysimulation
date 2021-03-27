#include "robot_factory.h"

namespace csci3081 {

  RobotFactory::RobotFactory() { }

  IEntity* RobotFactory::CreateEntity(const picojson::object& details) {
    IEntity* robot;
    try {
      robot = new Robot(details);
    } catch (...) { // failed to create Robot entity
      return nullptr;
    } // catch (...)
    return robot;
  } // RobotFactory(picojson::object&)

} // namespace csci3081
