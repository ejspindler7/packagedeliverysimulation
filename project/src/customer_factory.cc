#include "customer_factory.h"

namespace csci3081 {

  CustomerFactory::CustomerFactory() { }

  IEntity* CustomerFactory::CreateEntity(const picojson::object& details) {
    IEntity* customer;
    try {
      customer = new Customer(details);
    } catch (...) { // failed to create Customer entity
      return nullptr;
    } // catch (...)
    return customer;
  } // CustomerFactory(picojson::object&)

} // namespace csci3081
