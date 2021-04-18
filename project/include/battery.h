/**
 * @file battery.h
 */

#ifndef BATTERY_H_
#define BATTERY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

namespace csci3081 {

/*******************************************************************************
 * Class Definition
 ******************************************************************************/
  /**
   * @brief Class for storing Battery information and associated methods.
   */
  class Battery {
    public:
      /**
       * @brief Constructor: instantiates a Battery object with a max_charge value 
       *  
       * @param max_charge An integer value that depletes through usage.
       *                   Default value of 10000.
       */ 
      Battery(float max_charge = 10000);

      /**
       * @brief Get the current charge of battery.
       *
       * @return Current battery charge. 
       */ 
      float GetCharge();

      /**
       * @brief Set the current charge of battery.
       *
       * @param charge A float representing the desired value  current
       *               charge. Note should satisfy 0 <= charge <= max_charge_.
       *               Any values outside of this range will be be cast to the
       *               nearest safe value (i.e.  if charge > max_charge_ then
       *               charge is set to max_charge_).
       * @return void.
       */ 
      void SetCharge(float charge);

      /**
       * @brief Checks to see if battery is fully depleted.
       *
       * @return true if current charge is 0, or false otherwise.
       */ 
      bool IsDead();

      /**
       * @brief Depletes the current charge by the amount specified.
       *
       * Has no effect if Battery is already dead or amount to deplete is
       * negative.
       *
       * @param amount Should be a positive float. Charge is depleted 
       *               by the amount specified.
       * @return void.
       */ 
      void Deplete(float amount);

    private:
      static int next_id_;
      int id_;
      float max_charge_;
      float remaining_charge_;
  };

} // namespace csci3081
#endif // BATTERY_H_
