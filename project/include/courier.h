/**
 * @file courier.h
 */

#ifndef COURIER_H_
#define COURIER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity_base.h"
#include "package.h"
#include "battery.h"
#include "route.h"
#include <queue>
#include <string>
#include  "delivery_simulation.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Interface for entities that deliver packages
   *
   * Courier's are able to pickup and deliver packages to other
   * entities by following either a smart route, beeline, or parabolic path.
   */
  class Courier : public csci3081::EntityBase {

    public:

      /**
       * @brief Constructor: Creates the requested Courier entity
       *
       *
       * @param details A picojson object containing requested courier details.
       */
      Courier(const picojson::object& details);

      /**
       * @brief Destructor.
       *
       * deletes the route_strategy pointer
       */
      ~Courier();

      /**
       * @brief Get the courier's current destination.
       *
       * @return destination as a vector<float>& of size 3 where elements
       *         0, 1, and 2 correspond to the entity's x, y, and z
       *         coordinates respectively.
       */
      std::vector<float> GetDestination() const;

      /**
       * @brief Set the courier's destination using vector<float>.
       *
       * If destination parameter is not of size 3, the destination gets set to
       * (0,0,0). Additionally, if Courier::UsingSmartRoute() is true, the
       * smart path to the new destination is obtained.
       *
       * @param destination A vector<float> of size 3 where elements
       *        0, 1, and 2 correspond to the entity's x, y, and z
       *        coordinates respectively.
       * @return void
       */
      void SetDestination(std::vector<float> destination);

      /**
       * @brief Get the courier's Speed.
       *
       * The courier's speed dictates how fast it moves in the simulation.
       *
       * @return courier speed as float.
       */
      float GetSpeed() const;

      /**
       * @brief Set the courier's speed.
       *
       * @param speed A float.
       * @return void
       */
      void SetSpeed(float speed);

      /**
       * @brief Get a reference to the courier's Battery.
       *
       * Each courier has its own Battery.
       *
       * @return A reference to the courier's Battery.
       */
      Battery& GetBattery();

      /**
       * @brief Get a pointer to the package the courier is tasked with
       *        delivering.
       *
       * If the courier has not been assigned a package, nullptr will be
       * returned.
       *
       * @return A pointer to a Package or nullptr.
       */
      Package* GetPackage() const;

      /**
       * @brief Update the courier's route.
       * 
       * Uses the current Route strategy to generate a route from
       * the courier's current position to the courier's current
       * destination.
       * 
       */
      void UpdateRoute();

      /**
       * @brief Get the courier's route.
       *
       * @return route
       */
      std::vector<std::vector<float>> GetRoute() const;


      /**
       * @brief Assign the courier to pickup and deliver a Package.
       *
       * The Package contains the delivery destination.
       *
       * @param package A Package* that is to be delivered.
       * @return void
       */
      void SetPackage(Package* package);

      /**
       * @brief Designate the path type the courier should follow
       *
       * valid string arguments are "smart", "beeline", and "parabolic"
       * has no effect if string is not valid
       *
       * @param path_type A string that matches one of the above valid
                          strings
       * @return void
       */
      void SetPathType(std::string path_type);

      /**
       * @brief Set a pointer to an IGraph object.
       *
       * IGraph* is used in calls to IGraph::GetPath(vector<float>,
       * vector<float>) by the smart route strategy. 
       *
       * @param graph A IGraph*.
       * @return void
       */
      void SetGraph(const IGraph* graph);

      /**
       * @brief Determine if courier is carrying a package to delivery
       *        destination.
       *
       * @return true when carrying package to delivery destination. false
       *         otherwise.
       */
      bool HasPackage();

      /**
       * @brief Determine if courier is free to be assigned a package for
       *        delivery.
       *
       * @return true when available for package delivery. false
       *         otherwise.
       */
      bool IsAvailable();

      /**
       * @brief Checks the battery dead status by using the battery class
       *        method IsDead(). This is needed since battery is protected
       *        in courier and can't be directly access in delivery_simulation
       *
       * @return returns true if battery is dead. false
       *         if not.
       */
      bool GetBatteryDeadStatus();

      /**
       * @brief A simple boolean check to see if the observer has been
       *        notified that the courier has stopped moving
       *        so that it doesn't repeat multiple times.
       *
       * @return returns true if observer has been notified once. false
       *         if not.
       */
      bool Is_DeadBattery_Notified();

      /**
       * @brief Change the status after observer has been notified.
       *
       * @param A boolean value depending on if its been notified.
       * @return void
       */
      void DeadBattery_Notified(bool check);

      /**
       * @brief Remove package from visualization and make courier ready
       *        for a new package.
       *
       * @return void.
       */
      void DropoffPackage();

      /**
       * @brief Handle courier movement logic.
       *
       * Determines when the courier should move, and where the courier should go.
       *
       * @param dt A float that is representative of time passed in seconds.
       * @return void
       */
      void Update(float dt);

      /**
       * @brief Move courier position towards destination
       *
       * New position calculated using
       * `position = position + direction * speed * dt`.
       *
       * Makes sure that package follows courier while being carried.
       *
       * @param dt A float that is representative of time passed in seconds.
       * @return void
       */
      void Move(float dt);

      /**
       * @brief This function gets the integer variable associated with the enum status_.
       *
       * @return integer from which the status is (0,1, or 2)
       */
      int GetStatus();

      /**
       * @brief This gets the integer variable numNotify and returns it.
       *
       * @return an integer to keep track of which level of notifications
       *         this entity is on.
       */
      int getNotification();

      /**
       * @brief This functions sets the integer numNotify.
       * Three possible values of numNotify
       * 0 -> Courier is available to deliver a package.
       * 1 -> Package is scheduled, courier is moving towards package.
       * 2 -> Package is aquired, courier is moving towards customer.
       * @param num An integer that is representative of which level notification is okay to send.
       * @return void
       */
      void setNotification(int num);

    protected:
      enum Status {
        kReady,
        kAcquirePackage,
        kDeliverPackage
      };
      Status status_;
      IRoute* route_strategy_;
      float speed_;
      Vector3D destination_;
      Battery battery_;
      Package* package_;
      std::queue<Vector3D> route_;
      const IGraph* graph_;
      int numNotify;
      bool battery_done;
  };
} // namespace csci3081
#endif // COURIER_H_
