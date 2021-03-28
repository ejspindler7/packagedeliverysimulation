#include "package_factory.h"

namespace csci3081 {

  PackageFactory::PackageFactory() { }

  IEntity* PackageFactory::CreateEntity(const picojson::object& details) {
    IEntity* package;
    try {
      package = new Package(details);
    } catch (...) { // failed to create Package entity
      return nullptr;
    } // catch (...)
    return package;
  } // PackageFactory(picojson::object&)

} // namespace csci3081
