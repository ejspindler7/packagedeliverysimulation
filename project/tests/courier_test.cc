#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/courier.h"
#include "picojson_test_objects.h"

namespace csci3081 {

  class CourierTest : public ::testing::Test {
    public: 
      void SetUp() {
        p_details = PicoJsonObjectPackage("package",
                                   "package2",
                                   "models/cardboardBox.glb",
                                   std::vector<float> {-1.0, -1.0, -1.0},
                                   std::vector<float> {-1.0, -1.0, -1.0},
                                   std::vector<float> {-1.0, -1.0, -1.0},
                                   0.0,
                                   std::vector<float> {0.0, 0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0});
        // initialize all picojson::object for details argument to Drone
        // constructor in tests 
        details_1 = PicoJsonObjectDrone();
        
        details_2 = PicoJsonObjectDrone("drone",
                                   "drone2",
                                   "models/s9drone.glb",
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   std::vector<float> {0.0, 0.0, 0.0});

        details_3 = PicoJsonObjectDrone("drone",
                                   "drone3",
                                   "models/s9drone.glb",
                                   std::vector<float> {3.0, 4.0, 5.0},
                                   std::vector<float> {6.0, 7.0, 8.0},
                                   std::vector<float> {13.0, 14.0, 15.0, 16.0},
                                   std::vector<float> {9.0, 10.0, 11.0},
                                   12.0,
                                   20.0,
                                   21.0,
                                   22.0,
                                   std::vector<float> {17.0, 18.0, 19.0});
      } // SetUp()

      virtual void TearDown() {}

    protected:
      PicoJsonObjectPackage p_details;
      PicoJsonObjectDrone details_1;
      PicoJsonObjectDrone details_2;
      PicoJsonObjectDrone details_3;

  }; // Vector3DTest

  /*******************************************************************************
   * Test Cases
   ******************************************************************************/

  TEST_F(CourierTest, HasPackageTests) {
    Courier d1(details_1.obj);
    Courier d2(details_2.obj);

    Package package(p_details.obj);
    package.SetPosition(d1.GetPosition());

    d1.SetPackage(&package);
    d1.Update(1);
    EXPECT_EQ(d1.HasPackage(), true) << "d1 - HasPackage incorrect";
    EXPECT_EQ(d1.IsAvailable(), false) << "d1 - IsAvailable incorrect";

    EXPECT_EQ(d2.HasPackage(), false) << "d2 - HasPackage incorrect";
  }

  TEST_F(CourierTest, DropoffPackageTests) {
    Courier d1(details_1.obj);
    Package package(p_details.obj);
    package.SetPosition(d1.GetPosition());

    d1.SetPackage(&package);
    d1.Update(1);
    EXPECT_EQ(d1.HasPackage(), true) << "d1 - HasPackage incorrect";
    EXPECT_EQ(d1.IsAvailable(), false) << "d1 - IsAvailable incorrect";

    d1.DropoffPackage();
    EXPECT_EQ(d1.GetPackage(), nullptr) << "d1 - DropoffPackage incorrect";
    EXPECT_EQ(d1.IsAvailable(), true) << "d1 - IsAvailable incorrect";
    EXPECT_EQ(package.GetPosition().at(0), 0) << "d1 - package x coord incorrect";
    EXPECT_EQ(package.GetPosition().at(1), -10000) << "d1 - package y coord incorrect";
    EXPECT_EQ(package.GetPosition().at(2), 0) << "d1 - package z coord incorrect";
  }

}  // namespace csci3081
