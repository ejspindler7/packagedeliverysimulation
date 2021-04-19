/**
 * @file customer.h
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Class for storing Customer information
   *
   */
  class Customer : public csci3081::EntityBase {
    public:
      /**
       * @brief Constructor: Creates the requested Customer entity
       *  
       *
       * @param details A picojson object containing requested customer details. 
       */ 
      Customer(const picojson::object& object);
  };

} // namespace csci3081

#endif // CUSTOMER_H_
