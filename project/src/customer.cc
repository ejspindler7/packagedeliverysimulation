#include "customer.h"

namespace csci3081 {

   Customer::Customer(const picojson::object& object) : EntityBase(object) {
      if (JsonHelper::GetString(object, "type") != "customer") {
        throw "Error: Cannot create requested entity";
      } // if
   } // Customer(picojson::object&)

} // namespace csci3081
