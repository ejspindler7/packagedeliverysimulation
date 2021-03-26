/**
 * @file composite_factory.h
 */

#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "json_helper.h"
#include <EntityProject/entity_factory.h>
#include <vector>

using entity_project::IEntity;
using entity_project::IEntityFactory;

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Composite factory which handles entity creation
   *        using component factories.
   * 
   * Component entity factories are responsible for the creation of their
   * respective entities. Component factories can be added using
   * CompositeFactory::AddFactory(IEntityFactory*).
   * 
   * Calls to CompositeFactory::CreateEntity(const picojson::object&) will
   * return a pointer to a newly created entity if one of the component
   * factories is successful in creating the requested entity.
   */
  class CompositeFactory : public IEntityFactory {
    public:
      /**
       * @brief Constructor.
       *
       * Adds drone, package, and customer factories by default.
       */ 
      CompositeFactory();

      /**
       * @brief Destructor.
       * 
       * Deletes all stored entity factories.
       */ 
      ~CompositeFactory();


      /**
       * @brief Adds an entity factory to component factory instance.
       * 
       * @param factory A pointer to the IEntityFactory that is to be added. 
       * @return Void.
       */ 
      void AddFactory(IEntityFactory* factory);

      /**
       * @brief Creates the specified entity.
       * 
       * Attempts to create the specified enitity by iterating through each
       * contained entity factory until successful or there are no more
       * factories.
       *
       * @param details A picojson object containing requested enitity details. 
       * @return A pointer the created entity, or nullptr if unable to create
       *         the the resquested entity.
       */ 
      IEntity* CreateEntity(const picojson::object& details) override;

    private:
      std::vector<IEntityFactory*> component_factories_;
  };

} // namespace csci3081
#endif // COMPOSITE_FACTORY_H_
