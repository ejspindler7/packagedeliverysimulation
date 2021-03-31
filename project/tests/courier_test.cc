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

  TEST_F(CourierTest, ConstructorTests) {
    Courier d1(details_1.obj);
    Courier d2(details_2.obj);
    Courier d3(details_3.obj);

    /* Check that details gets set to the picojson object that was used to initialize it */
    EXPECT_EQ(picojson::value(d1.GetDetails()).serialize(), picojson::value(details_1.obj).serialize())
      << "d1 - incorrect details initializaiton";

    EXPECT_EQ(picojson::value(d2.GetDetails()).serialize(), picojson::value(details_2.obj).serialize())
      << "d2 - incorrect details initializaiton";

    EXPECT_EQ(picojson::value(d3.GetDetails()).serialize(), picojson::value(details_3.obj).serialize())
      << "d3 - incorrect details initializaiton";
    
    EXPECT_NE(d1.GetId(), d2.GetId()) << "d1, d2 - incorrect Id initialization";
    EXPECT_NE(d2.GetId(), d3.GetId()) << "d2, d3 - incorrect Id initialization";

    /* Check that name gets set to expected value */
    EXPECT_EQ(d1.GetName(), "drone") << "d1 - incorrect name initialization";
    EXPECT_EQ(d2.GetName(), "drone2") << "d2 - incorrect name initialization";
    EXPECT_EQ(d3.GetName(), "drone3") << "d3 - incorrect name initialization";

    /* Check that position gets set to expected value */
    EXPECT_FLOAT_EQ(d1.GetPosition().at(0), details_1.position.at(0)) 
      << "d1 - incorrect position x initialization";
    EXPECT_FLOAT_EQ(d1.GetPosition().at(1), details_1.position.at(1)) 
      << "d1 - incorrect position y initialization";
    EXPECT_FLOAT_EQ(d1.GetPosition().at(2), details_1.position.at(2)) 
      << "d1 - incorrect position z initialization";

    EXPECT_FLOAT_EQ(d2.GetPosition().at(0), details_2.position.at(0)) 
      << "d2 - incorrect position x initialization";
    EXPECT_FLOAT_EQ(d2.GetPosition().at(1), details_2.position.at(1)) 
      << "d2 - incorrect position y initialization";
    EXPECT_FLOAT_EQ(d2.GetPosition().at(2), details_2.position.at(2)) 
      << "d2 - incorrect position z initialization";
    
    EXPECT_FLOAT_EQ(d3.GetPosition().at(0), details_3.position.at(0)) 
      << "d3 - incorrect position x initialization";
    EXPECT_FLOAT_EQ(d3.GetPosition().at(1), details_3.position.at(1)) 
      << "d3 - incorrect position y initialization";
    EXPECT_FLOAT_EQ(d3.GetPosition().at(2), details_3.position.at(2)) 
      << "d3 - incorrect position z initialization";

    /* Check that direction gets set to expected value */
    EXPECT_FLOAT_EQ(d1.GetDirection().at(0), details_1.direction.at(0)) 
      << "d1 - incorrect direction x initialization";
    EXPECT_FLOAT_EQ(d1.GetDirection().at(1), details_1.direction.at(1)) 
      << "d1 - incorrect direction y initialization";
    EXPECT_FLOAT_EQ(d1.GetDirection().at(2), details_1.direction.at(2)) 
      << "d1 - incorrect direction z initialization";

    EXPECT_FLOAT_EQ(d2.GetDirection().at(0), details_2.direction.at(0)) 
      << "d2 - incorrect direction x initialization";
    EXPECT_FLOAT_EQ(d2.GetDirection().at(1), details_2.direction.at(1)) 
      << "d2 - incorrect direction y initialization";
    EXPECT_FLOAT_EQ(d2.GetDirection().at(2), details_2.direction.at(2)) 
      << "d2 - incorrect direction z initialization";
    
    EXPECT_FLOAT_EQ(d3.GetDirection().at(0), details_3.direction.at(0)) 
      << "d3 - incorrect direction x initialization";
    EXPECT_FLOAT_EQ(d3.GetDirection().at(1), details_3.direction.at(1)) 
      << "d3 - incorrect direction y initialization";
    EXPECT_FLOAT_EQ(d3.GetDirection().at(2), details_3.direction.at(2)) 
      << "d3 - incorrect direction z initialization";

    /* Check that radius gets set to expected value */
    EXPECT_FLOAT_EQ(d1.GetRadius(), details_1.radius) 
      << "d1 - incorrect radius initialization";

    EXPECT_FLOAT_EQ(d2.GetRadius(), details_2.radius) 
      << "d2 - incorrect radius initialization";
    
    EXPECT_FLOAT_EQ(d3.GetRadius(), details_3.radius) 
      << "d3 - incorrect radius initialization";

    /* Check that version gets set to expected value */
    EXPECT_EQ(d1.GetVersion(), 0) 
      << "d1 - incorrect version initialization";

    EXPECT_EQ(d2.GetVersion(), 0) 
      << "d2 - incorrect version initialization";
    
    EXPECT_EQ(d3.GetVersion(), 0) 
      << "d3 - incorrect version initialization";

    /* Check that dynamic gets set to expected value */
    EXPECT_EQ(d1.IsDynamic(), true) 
      << "d1 - incorrect dynamic initialization";

    EXPECT_EQ(d2.IsDynamic(), true) 
      << "d2 - incorrect dynamic initialization";
    
    EXPECT_EQ(d3.IsDynamic(), true) 
      << "d3 - incorrect dynamic initialization";

    /* Check that destination gets set to expected value */
    /* Note that the constructor initially sets the destination to the drone's
     * position since there is no Customer assigned to the drone at the time
     * of its creation */
    EXPECT_FLOAT_EQ(d1.GetDestination().at(0), details_1.position.at(0)) 
      << "d1 - incorrect destination x initialization";
    EXPECT_FLOAT_EQ(d1.GetDestination().at(1), details_1.position.at(1)) 
      << "d1 - incorrect destination y initialization";
    EXPECT_FLOAT_EQ(d1.GetDestination().at(2), details_1.position.at(2)) 
      << "d1 - incorrect destination z initialization";

    EXPECT_FLOAT_EQ(d2.GetDestination().at(0), details_2.position.at(0)) 
      << "d2 - incorrect destination x initialization";
    EXPECT_FLOAT_EQ(d2.GetDestination().at(1), details_2.position.at(1)) 
      << "d2 - incorrect destination y initialization";
    EXPECT_FLOAT_EQ(d2.GetDestination().at(2), details_2.position.at(2)) 
      << "d2 - incorrect destination z initialization";
    
    EXPECT_FLOAT_EQ(d3.GetDestination().at(0), details_3.position.at(0)) 
      << "d3 - incorrect position x initialization";
    EXPECT_FLOAT_EQ(d3.GetDestination().at(1), details_3.position.at(1)) 
      << "d3 - incorrect position y initialization";
    EXPECT_FLOAT_EQ(d3.GetDestination().at(2), details_3.position.at(2)) 
      << "d3 - incorrect position z initialization";

    /* Check that speed gets set to expected value */
    EXPECT_FLOAT_EQ(d1.GetSpeed(), details_1.speed) 
      << "d1 - incorrect speed initialization";

    EXPECT_FLOAT_EQ(d2.GetSpeed(), details_2.speed) 
      << "d2 - incorrect speed initialization";
    
    EXPECT_FLOAT_EQ(d3.GetSpeed(), details_3.speed) 
      << "d3 - incorrect speed initialization";

    /* Check that drone battery gets set to expected value */
    EXPECT_EQ(d1.GetBattery().GetCharge(), 10000) 
      << "d1 - incorrect battery initialization";

    EXPECT_EQ(d2.GetBattery().GetCharge(), 10000) 
      << "d2 - incorrect battery initialization";
    
    EXPECT_EQ(d3.GetBattery().GetCharge(), 10000) 
      << "d3 - incorrect battery initialization";

    /* Check that package gets set to expected value */
    /* Note that package is initialized to nullptr when drone is created */
    EXPECT_EQ(d1.GetPackage(), nullptr) 
      << "d1 - incorrect package initialization";

    EXPECT_EQ(d2.GetPackage(), nullptr) 
      << "d2 - incorrect package initialization";
    
    EXPECT_EQ(d3.GetPackage(), nullptr) 
      << "d3 - incorrect package initialization";

    /* Check that status gets set to expected value */
    /* Note that status is initialized to kReady when drone is created */
    EXPECT_EQ(d1.IsAvailable(), true) 
      << "d1 - incorrect status initialization";

    EXPECT_EQ(d2.IsAvailable(), true) 
      << "d2 - incorrect status initialization";
    
    EXPECT_EQ(d3.IsAvailable(), true) 
      << "d3 - incorrect status initialization";
  } // ConstructorTests
  

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
