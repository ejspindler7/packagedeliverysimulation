#include "drone.h"
#include "json_helper.h"

namespace csci3081 {

  Drone::Drone(const picojson::object& details) : Courier(details) {
    if (JsonHelper::GetString(details, "type") != "drone") {
      throw "Error: Cannot create requested entity";
    } // if
    try {
      this->SetPathType(JsonHelper::GetString(details, "path"));
    } catch (...) { }
  } // Drone(const picojson::object&)

} // namespace csci3081
