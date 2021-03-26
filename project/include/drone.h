/**
 * @file drone.h
 */

#ifndef DRONE_H_
#define DRONE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "package.h"
#include "battery.h"
#include <queue>

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Class for storing Drone information
   *
   * Drone's are able to pickup and deliver packages to other
   * entities by following either a smart route or a beeline path.
   */
  class Drone : public csci3081::EntityBase {

    public:

      /**
       * @brief Constructor.
       *  
       * Creates the requested Drone entity. 
       *
       * @param details A picojson object containing requested drone details. 
       */ 
      Drone(const picojson::object& details);

      /**
       * @brief Get the drone's current destination. 
       *
       * @return destination as a vector<float>& of size 3 where elements
       *         0, 1, and 2 correspond to the entity's x, y, and z
       *         coordinates respectively.
       */ 
      std::vector<float> GetDestination() const;

      /**
       * @brief Set the drone's destination using vector<float>. 
       *
       * If destination parameter is not of size 3, the destination gets set to 
       * (0,0,0). Additionally, if Drone::UsingSmartRoute() is true, the
       * smart path to the new destination is obtained.
       *
       * @param destination A vector<float> of size 3 where elements
       *        0, 1, and 2 correspond to the entity's x, y, and z
       *        coordinates respectively.
       * @return void
       */ 
      void SetDestination(std::vector<float> destination);

      /**
       * @brief Get the drone's Speed. 
       *
       * The drone's speed dictates how fast it moves in the simulation.
       *
       * @return drone speed as float. 
       */ 
      float GetSpeed() const;

      /**
       * @brief Set the drone's speed. 
       *
       * @param speed A float.
       * @return void
       */ 
      void SetSpeed(float speed);

      /**
       * @brief Get a reference to the drone's Battery. 
       *
       * Each drone has its own Battery.
       *
       * @return A reference to the drone's Battery. 
       */ 
      Battery& GetBattery();

      /**
       * @brief Get a pointer to the package the drone is tasked with
       *        delivering. 
       *
       * If the drone has not been assigned a package, nullptr will be
       * returned.
       *
       * @return A pointer to a Package or nullptr. 
       */ 
      Package* GetPackage() const;

      /**
       * @brief Assign the drone to pickup and deliver a Package. 
       *
       * The Package contains the delivery destination.
       *
       * @param package A Package* that is to be delivered. 
       * @return void
       */ 
      void SetPackage(Package* package);

      /**
       * @brief Set a pointer to an IGraph object.
       *
       * IGraph* is used in calls to IGraph::GetPath(vector<float>,
       * vector<float>). This should be set when a package is set to 
       * be delivered by the drone if Drone::UsingSmartRoute() is true.
       *
       * @param package A IGraph*.
       * @return void
       */ 
      void SetGraph(const IGraph* graph);

      /**
       * @brief Determine if drone is set to use smart route or beeline path.
       *
       * @return true when smart route should be used. false when beeline
       *         should be used.
       */ 
      bool UsingSmartRoute();

      /**
       * @brief Switch between smart and beeline movement paths.
       *
       * @param smart When true, use smart route in path finding. When false,
                use beeline route in path finding.
       * @return void
       */ 
      void SetSmartRoute(bool smart);

      /**
       * @brief Determine if drone is carrying a package to delivery
       *        destination.
       *
       * @return true when carrying package to delivery destination. false
       *         otherwise. 
       */ 
      bool HasPackage();

      /**
       * @brief Determine if drone is free to be assigned a package for
       *        delivery. 
       *
       * @return true when available for package delivery. false
       *         otherwise. 
       */ 
      bool IsAvailable();

      /**
       * @brief Remove package from visualization and make drone ready
       *        for a new package.
       *
       * @return void. 
       */ 
      void DropoffPackage();

      /**
       * @brief Move drone position towards destination 
       *
       * New position is calculated using 
       * `position = position + direction * speed * dt`.
       * Makes sure that package follows drone while being carried.
       *
       * @param dt A float that is representative of time passed in seconds.
       * @return void
       */
      void UpdatePosition(float dt);

      /**
       * @brief Handle drone movement logic.    
       *
       * Determines when the drone should move, and where the drone should go.
       *
       * @param dt A float that is representative of time passed in seconds.
       * @return void
       */
      void Update(float dt);

    private:
      enum Status {
        kReady,
        kAcquirePackage,
        kDeliverPackage
      };
      Status status_;
      Vector3D destination_;
      std::queue<std::vector<float>> route_;
      float speed_;
      Battery battery_;
      Package* package_;
      bool use_smart_route_;
      const IGraph* graph_;
      float beeline_height_;
  };
} // namespace csci3081
#endif // DRONE_H_
