#include "robot.h"
#include "json_helper.h"

namespace csci3081 {

  Robot::Robot(const picojson::object& details) : Courier(details) {
    if (JsonHelper::GetString(details, "type") != "robot") {
      throw "Error: Cannot create requested entity";
    } // if
  } // Robot(const picojson::object&)

} // namespace csci3081
