/**
 * @file package_factory.h
 */

#ifndef PACKAGE_FACTORY_H_
#define PACKAGE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "json_helper.h"
#include "package.h"
#include <EntityProject/entity_factory.h>

using entity_project::IEntity;
using entity_project::IEntityFactory;

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Factory which handles Package entity creation.
   */
  class PackageFactory : public IEntityFactory {
    public:
      /**
       * @brief Default Constructor.
       */ 
      PackageFactory();

      /**
       * @brief Attempts to create the specified Package entity.
       * 
       * @param details A picojson object containing the requested Package
       *                enitity details. 
       * @return A pointer to the created Package, or nullptr if unable to
       *         create the the requested Package entity.
       */ 
      IEntity* CreateEntity(const picojson::object& details) override;
  };

} // namespace csci3081
#endif // PACKAGE_FACTORY_H_
