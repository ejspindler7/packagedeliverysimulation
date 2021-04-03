#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/package.h"
#include "picojson_test_objects.h"

namespace csci3081 {

  class PackageTest : public ::testing::Test {
    public: 
      void SetUp() {
        // initialize all picojson::object for details argument to Package
        // constructor in tests 
        details_1 = PicoJsonObjectPackage();
        
        details_2 = PicoJsonObjectPackage("package",
                                   "package2",
                                   "models/cardboardBox.glb",
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   0.0,
                                   std::vector<float> {0.0, 0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0});

        details_3 = PicoJsonObjectPackage("package",
                                   "package3",
                                   "models/cardboardBox.glb",
                                   std::vector<float> {3.0, 4.0, 5.0},
                                   std::vector<float> {6.0, 7.0, 8.0},
                                   std::vector<float> {9.0, 10.0, 11.0},
                                   12.0,
                                   std::vector<float> {13.0, 14.0, 15.0, 16.0},
                                   std::vector<float> {17.0, 18.0, 19.0});
                                   
      } // SetUp()

      virtual void TearDown() {}

    protected:
      PicoJsonObjectPackage details_1;
      PicoJsonObjectPackage details_2;
      PicoJsonObjectPackage details_3;

  }; // Vector3DTest

  /*******************************************************************************
   * Test Cases
   ******************************************************************************/

  TEST_F(PackageTest, ConstructorTests) {
    Package p1(details_1.obj);
    Package p2(details_2.obj);
    Package p3(details_3.obj);

    /* Check that details gets set to the picojson object that was used to initialize it */
    EXPECT_EQ(picojson::value(p1.GetDetails()).serialize(), picojson::value(details_1.obj).serialize())
      << "p1 - incorrect details initializaiton";

    EXPECT_EQ(picojson::value(p2.GetDetails()).serialize(), picojson::value(details_2.obj).serialize())
      << "p2 - incorrect details initializaiton";

    EXPECT_EQ(picojson::value(p3.GetDetails()).serialize(), picojson::value(details_3.obj).serialize())
      << "p3 - incorrect details initializaiton";
      
    EXPECT_NE(p1.GetId(), p2.GetId()) << "p1, p2 - incorrect Id initialization";
    EXPECT_NE(p2.GetId(), p3.GetId()) << "p2, p3 - incorrect Id initialization";

    /* Check that name gets set to expected value */
    EXPECT_EQ(p1.GetName(), "package") << "p1 - incorrect name initialization";
    EXPECT_EQ(p2.GetName(), "package2") << "p2 - incorrect name initialization";
    EXPECT_EQ(p3.GetName(), "package3") << "p3 - incorrect name initialization";

    /* Check that position gets set to expected value */
    EXPECT_FLOAT_EQ(p1.GetPosition().at(0), details_1.position.at(0)) 
      << "p1 - incorrect position x initialization";
    EXPECT_FLOAT_EQ(p1.GetPosition().at(1), details_1.position.at(1)) 
      << "p1 - incorrect position y initialization";
    EXPECT_FLOAT_EQ(p1.GetPosition().at(2), details_1.position.at(2)) 
      << "p1 - incorrect position z initialization";

    EXPECT_FLOAT_EQ(p2.GetPosition().at(0), details_2.position.at(0)) 
      << "p2 - incorrect position x initialization";
    EXPECT_FLOAT_EQ(p2.GetPosition().at(1), details_2.position.at(1)) 
      << "p2 - incorrect position y initialization";
    EXPECT_FLOAT_EQ(p2.GetPosition().at(2), details_2.position.at(2)) 
      << "p2 - incorrect position z initialization";
    
    EXPECT_FLOAT_EQ(p3.GetPosition().at(0), details_3.position.at(0)) 
      << "p3 - incorrect position x initialization";
    EXPECT_FLOAT_EQ(p3.GetPosition().at(1), details_3.position.at(1)) 
      << "p3 - incorrect position y initialization";
    EXPECT_FLOAT_EQ(p3.GetPosition().at(2), details_3.position.at(2)) 
      << "p3 - incorrect position z initialization";

    /* Check that direction gets set to expected value */
    EXPECT_FLOAT_EQ(p1.GetDirection().at(0), details_1.direction.at(0)) 
      << "p1 - incorrect direction x initialization";
    EXPECT_FLOAT_EQ(p1.GetDirection().at(1), details_1.direction.at(1)) 
      << "p1 - incorrect direction y initialization";
    EXPECT_FLOAT_EQ(p1.GetDirection().at(2), details_1.direction.at(2)) 
      << "p1 - incorrect direction z initialization";

    EXPECT_FLOAT_EQ(p2.GetDirection().at(0), details_2.direction.at(0)) 
      << "p2 - incorrect direction x initialization";
    EXPECT_FLOAT_EQ(p2.GetDirection().at(1), details_2.direction.at(1)) 
      << "p2 - incorrect direction y initialization";
    EXPECT_FLOAT_EQ(p2.GetDirection().at(2), details_2.direction.at(2)) 
      << "p2 - incorrect direction z initialization";
    
    EXPECT_FLOAT_EQ(p3.GetDirection().at(0), details_3.direction.at(0)) 
      << "p3 - incorrect direction x initialization";
    EXPECT_FLOAT_EQ(p3.GetDirection().at(1), details_3.direction.at(1)) 
      << "p3 - incorrect direction y initialization";
    EXPECT_FLOAT_EQ(p3.GetDirection().at(2), details_3.direction.at(2)) 
      << "p3 - incorrect direction z initialization";

    /* Check that radius gets set to expected value */
    EXPECT_FLOAT_EQ(p1.GetRadius(), details_1.radius) 
      << "p1 - incorrect radius initialization";

    EXPECT_FLOAT_EQ(p2.GetRadius(), details_2.radius) 
      << "p2 - incorrect radius initialization";
    
    EXPECT_FLOAT_EQ(p3.GetRadius(), details_3.radius) 
      << "p3 - incorrect radius initialization";

    /* Check that version gets set to expected value */
    EXPECT_EQ(p1.GetVersion(), 0) 
      << "p1 - incorrect version initialization";

    EXPECT_EQ(p2.GetVersion(), 0) 
      << "p2 - incorrect version initialization";
    
    EXPECT_EQ(p3.GetVersion(), 0) 
      << "p3 - incorrect version initialization";

    /* Check that dynamic gets set to expected value */
    EXPECT_EQ(p1.IsDynamic(), false) 
      << "p1 - incorrect dynamic initialization";

    EXPECT_EQ(p2.IsDynamic(), false) 
      << "p2 - incorrect dynamic initialization";
    
    EXPECT_EQ(p3.IsDynamic(), false) 
      << "p3 - incorrect dynamic initialization";

    /* Check that destination gets set to expected value */
    /* Note that the constructor initially sets the destination to the drone's
     * position since there is no Customer assigned to the package at the time
     * of its creation */
    EXPECT_FLOAT_EQ(p1.GetDestination().at(0), details_1.position.at(0)) 
      << "p1 - incorrect destination x initialization";
    EXPECT_FLOAT_EQ(p1.GetDestination().at(1), details_1.position.at(1)) 
      << "p1 - incorrect destination y initialization";
    EXPECT_FLOAT_EQ(p1.GetDestination().at(2), details_1.position.at(2)) 
      << "p1 - incorrect destination z initialization";

    EXPECT_FLOAT_EQ(p2.GetDestination().at(0), details_2.position.at(0)) 
      << "p2 - incorrect destination x initialization";
    EXPECT_FLOAT_EQ(p2.GetDestination().at(1), details_2.position.at(1)) 
      << "p2 - incorrect destination y initialization";
    EXPECT_FLOAT_EQ(p2.GetDestination().at(2), details_2.position.at(2)) 
      << "p2 - incorrect destination z initialization";
    
    EXPECT_FLOAT_EQ(p3.GetDestination().at(0), details_3.position.at(0)) 
      << "p3 - incorrect position x initialization";
    EXPECT_FLOAT_EQ(p3.GetDestination().at(1), details_3.position.at(1)) 
      << "p3 - incorrect position y initialization";
    EXPECT_FLOAT_EQ(p3.GetDestination().at(2), details_3.position.at(2)) 
      << "p3 - incorrect position z initialization";

    /* Check that weight gets set to expected value */
    /* For now weight is initialized to -1 by the constuctor indicating that it
     * has yet to be set */
    EXPECT_FLOAT_EQ(p1.GetWeight(), -1.0) 
      << "p1 - incorrect weight initialization";

    EXPECT_FLOAT_EQ(p2.GetWeight(), -1.0) 
      << "p2 - incorrect weight initialization";
    
    EXPECT_FLOAT_EQ(p3.GetWeight(), -1.0) 
      << "p3 - incorrect weight initialization";

    /* Check that customer gets set to expected value */
    /* For now customer is initialized to nullptr by the constuctor indicating
     * that it has yet to be set */
    EXPECT_EQ(p1.GetCustomer(), nullptr) 
      << "p1 - incorrect customer initialization";

    EXPECT_EQ(p2.GetCustomer(), nullptr) 
      << "p2 - incorrect customer initialization";
    
    EXPECT_EQ(p3.GetCustomer(), nullptr) 
      << "p3 - incorrect customer initialization";

  } // ConstructorTests

}  // namespace csci3081
