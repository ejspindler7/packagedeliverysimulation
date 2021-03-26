#include "gtest/gtest.h"
#include "../include/battery.h"

namespace csci3081 {

  class BatteryTest : public ::testing::Test {
    public: 
      void SetUp() {
        b_0 = Battery(0);
        b_1 = Battery(1);
        b_2 = Battery(2);
      } // SetUp()

    protected:
      Battery b_0;
      Battery b_1;
      Battery b_2;
      Battery b_3;
      Battery b_4;
  }; // Vector2DTest

  /*******************************************************************************
   * Test Cases
   ******************************************************************************/

  TEST_F(BatteryTest, ConstructorTests) {
    EXPECT_EQ(b_0.GetCharge(), 0) << "b_0 - incorrect charge init";
    EXPECT_EQ(b_1.GetCharge(), 1) << "b_1 - incorrect charge init";
    EXPECT_EQ(b_2.GetCharge(), 2) << "b_2 - incorrect charge init";
    EXPECT_EQ(b_3.GetCharge(), 10000) << "b_3 - incorrect charge init";
    EXPECT_EQ(b_4.GetCharge(), 10000) << "b_4 - incorrect charge init";
  } // ConstructorTests

  TEST_F(BatteryTest, IsDeadTests) {
    EXPECT_EQ(b_0.IsDead(), true) << "b_0  - IsDead error";
    EXPECT_EQ(b_1.IsDead(), false) << "b_1 - IsDead error";
    EXPECT_EQ(b_2.IsDead(), false) << "b_2 - IsDead error";
    EXPECT_EQ(b_3.IsDead(), false) << "b_3 - IsDead error";
    EXPECT_EQ(b_4.IsDead(), false) << "b_4 - IsDead error";
  } 

  TEST_F(BatteryTest, SetChargeTests) {
    b_0.SetCharge(3);
    EXPECT_EQ(b_0.GetCharge(), 0) << "b_0 - incorrect set charge";

    b_3.SetCharge(3000);
    EXPECT_EQ(b_3.GetCharge(), 3000) << "b_3 - incorrect set charge";

    b_4.SetCharge(-100);
    EXPECT_EQ(b_4.GetCharge(), 0) << "b_4 - incorrect set charge";
  } 

  TEST_F(BatteryTest, DepleteTests) {
    b_0.Deplete(3);
    EXPECT_EQ(b_0.GetCharge(), 0) << "b_0 - incorrect deplete";

    b_2.Deplete(3);
    EXPECT_EQ(b_2.GetCharge(), 0) << "b_2 - incorrect deplete";

    b_3.Deplete(3000);
    EXPECT_EQ(b_3.GetCharge(), 7000) << "b_3 - incorrect deplete";

    b_4.Deplete(-100);
    EXPECT_EQ(b_4.GetCharge(), 10000) << "b_4 - incorrect deplete";
  } 

}  // namespace csci3081
