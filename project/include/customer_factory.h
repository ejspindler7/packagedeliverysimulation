/**
 * @file customer_factory.h
 */

#ifndef CUSTOMER_FACTORY_H_
#define CUSTOMER_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "json_helper.h"
#include "customer.h"
#include <EntityProject/entity_factory.h>

using entity_project::IEntity;
using entity_project::IEntityFactory;

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Factory which handles Customer entity creation.
   */
  class CustomerFactory : public IEntityFactory {
    public:
      /**
       * @brief Default Constructor.
       */ 
      CustomerFactory();

      /**
       * @brief Attempts to create the specified Customer entity.
       * 
       * @param details A picojson object containing the requested Customer
       *                enitity details. 
       * @return A pointer to the created Customer, or nullptr if unable to
       *         create the the requested Customer entity.
       */ 
      IEntity* CreateEntity(const picojson::object& details) override;
  };

} // namespace csci3081
#endif // CUSTOMER_FACTORY_H_
