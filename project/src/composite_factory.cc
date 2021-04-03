#include "composite_factory.h"
#include "drone_factory.h"
#include "package_factory.h"
#include "customer_factory.h"

namespace csci3081 {

  CompositeFactory::CompositeFactory() { }

  CompositeFactory::~CompositeFactory() { 
    for (auto factory : component_factories_) {
      delete factory;
    } // for
  } // ~CompositeFactory()

  void CompositeFactory::AddFactory(IEntityFactory* factory) {
    component_factories_.push_back(factory);
  } // CompositeFactory(IEntityFactory)

  IEntity* CompositeFactory::CreateEntity(const picojson::object& details) {
    for (auto factory : component_factories_) {
      IEntity* entity = factory->CreateEntity(details);
      if (entity != nullptr) { // successful entity creation
        return entity;
      } // if
    } // for
    return nullptr;
  } // CompositeFactory(picojson::object&)

} // namespace csci3081
