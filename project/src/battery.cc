#include "battery.h"

namespace csci3081 {

  // initialize static class next_id_ variable
  int Battery::next_id_ = 0;

  Battery::Battery(float max_charge) {
    id_ = ++next_id_;
    max_charge_ = max_charge;
    remaining_charge_ = max_charge; // starts fully charged
  } // Battery()

  float Battery::GetCharge() {
    return remaining_charge_;
  } // GetCharge()

  void Battery::SetCharge(float charge) {
    if (charge > max_charge_) {
      charge = max_charge_;
    } else if (charge < 0) {
      charge = 0;
    } // else if
    remaining_charge_ = charge;
  } // SetCharge(int)

  bool Battery::IsDead() {
    return remaining_charge_ <= 0;
  } // IsDead()

  void Battery::Deplete(float amount) {
    // do nothing if battery is already dead
    if (!this->IsDead() && amount > 0) {
      remaining_charge_ -= amount;
      if (remaining_charge_ < 0) { 
        remaining_charge_ = 0;
      } // if
    } // if
  } // Deplete(int)

} // namespace csci3081
