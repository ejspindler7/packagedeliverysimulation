/**
 * @file package.h
 */

#ifndef PACKAGE_H_
#define PACKAGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "customer.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Class for storing Package information
   *
   * Package's maintain a record of the delivery destination.
   * Must be delivered by another entity like a Drone.
   */
  class Package : public csci3081::EntityBase {

    public:
      /**
       * @brief Constructor.
       *  
       * Creates the requested Package entity. 
       *
       * @param details A picojson object containing requested package details. 
       */ 
      Package(const picojson::object& object);

      /**
       * @brief Get the package delivery destination. 
       *
       * @return destination as a vector<float>& of size 3 where elements
       *         0, 1, and 2 correspond to the entity's x, y, and z
       *         coordinates respectively.
       */ 
      std::vector<float> GetDestination();

      /**
       * @brief Set the package delivery destination using vector<float>. 
       *
       * If destination parameter is not of size 3, the destination gets set to 
       * (0,0,0). 
       *
       * @param destination A vector<float> of size 3 where elements
       *        0, 1, and 2 correspond to the entity's x, y, and z
       *        coordinates respectively.
       * @return void
       */ 
      void SetDestination(std::vector<float> destination);

      /**
       * @brief Get the package weight. 
       *
       * @return package weight as a float. 
       */ 
      float GetWeight() const;

      /**
       * @brief Set the package weight. 
       *
       * @param weight A float.
       * @return void
       */ 
      void SetWeight(float weight);

      /**
       * @brief Get a pointer to the Customer the package is intended for.
       *
       * @return A pointer to a customer or nullptr. 
       */ 
      Customer* GetCustomer();

      /**
       * @brief Assign the package the Customer it is supposed to be delivered
       *        to. 
       *
       * @param customer A Customer* that is the recipient of the package. 
       * @return void
       */ 
      void SetCustomer(Customer* customer);

    private:
      Vector3D destination_;
      float weight_;
      Customer* customer_;
  };

} // namespace csci3081

#endif // PACKAGE_H_
