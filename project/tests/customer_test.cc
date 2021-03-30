#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/customer.h"
#include "picojson_test_objects.h"

namespace csci3081 {

  class CustomerTest : public ::testing::Test {
    public: 
      void SetUp() {
        // initialize all picojson::object for details argument to Customer
        // constructor in tests 
        details_1 = PicoJsonObjectCustomer();
        details_2 = PicoJsonObjectCustomer("customer",
                                   "customer2",
                                   "models/RobotExpressive.glb",
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   0.0,
                                   std::vector<float> {0.0, 0.0, 0.0, 0.0});

        details_3 = PicoJsonObjectCustomer("customer",
                                   "customer3",
                                   "models/RobotExpressive.glb",
                                   std::vector<float> {3.0, 4.0, 5.0},
                                   std::vector<float> {6.0, 7.0, 8.0},
                                   std::vector<float> {9.0, 10.0, 11.0},
                                   12.0,
                                   std::vector<float> {13.0, 14.0, 15.0, 16.0});
                                   
      } // SetUp()

      virtual void TearDown() {}

    protected:
      PicoJsonObjectCustomer details_1;
      PicoJsonObjectCustomer details_2;
      PicoJsonObjectCustomer details_3;

  }; // Vector3DTest

  /*******************************************************************************
   * Test Cases
   ******************************************************************************/

  TEST_F(CustomerTest, ConstructorTests) {
    Customer c1(details_1.obj);
    Customer c2(details_2.obj);
    Customer c3(details_3.obj);

    /* Check that details gets set to the picojson object that was used to initialize it */
    EXPECT_EQ(picojson::value(c1.GetDetails()).serialize(), picojson::value(details_1.obj).serialize())
      << "c1 - incorrect details initializaiton";

    EXPECT_EQ(picojson::value(c2.GetDetails()).serialize(), picojson::value(details_2.obj).serialize())
      << "c2 - incorrect details initializaiton";

    EXPECT_EQ(picojson::value(c3.GetDetails()).serialize(), picojson::value(details_3.obj).serialize())
      << "c3 - incorrect details initializaiton";
    
    EXPECT_NE(c1.GetId(), c2.GetId()) << "c1, c2 - incorrect Id initialization";
    EXPECT_NE(c2.GetId(), c3.GetId()) << "c2, c3 - incorrect Id initialization";

    /* Check that name gets set to expected value */
    EXPECT_EQ(c1.GetName(), "customer") << "c1 - incorrect name initialization";
    EXPECT_EQ(c2.GetName(), "customer2") << "c2 - incorrect name initialization";
    EXPECT_EQ(c3.GetName(), "customer3") << "c3 - incorrect name initialization";

    /* Check that position gets set to expected value */
    EXPECT_FLOAT_EQ(c1.GetPosition().at(0), details_1.position.at(0)) 
      << "c1 - incorrect position x initialization";
    EXPECT_FLOAT_EQ(c1.GetPosition().at(1), details_1.position.at(1)) 
      << "c1 - incorrect position y initialization";
    EXPECT_FLOAT_EQ(c1.GetPosition().at(2), details_1.position.at(2)) 
      << "c1 - incorrect position z initialization";

    EXPECT_FLOAT_EQ(c2.GetPosition().at(0), details_2.position.at(0)) 
      << "c2 - incorrect position x initialization";
    EXPECT_FLOAT_EQ(c2.GetPosition().at(1), details_2.position.at(1)) 
      << "c2 - incorrect position y initialization";
    EXPECT_FLOAT_EQ(c2.GetPosition().at(2), details_2.position.at(2)) 
      << "c2 - incorrect position z initialization";
    
    EXPECT_FLOAT_EQ(c3.GetPosition().at(0), details_3.position.at(0)) 
      << "c3 - incorrect position x initialization";
    EXPECT_FLOAT_EQ(c3.GetPosition().at(1), details_3.position.at(1)) 
      << "c3 - incorrect position y initialization";
    EXPECT_FLOAT_EQ(c3.GetPosition().at(2), details_3.position.at(2)) 
      << "c3 - incorrect position z initialization";

    /* Check that direction gets set to expected value */
    EXPECT_FLOAT_EQ(c1.GetDirection().at(0), details_1.direction.at(0)) 
      << "c1 - incorrect direction x initialization";
    EXPECT_FLOAT_EQ(c1.GetDirection().at(1), details_1.direction.at(1)) 
      << "c1 - incorrect direction y initialization";
    EXPECT_FLOAT_EQ(c1.GetDirection().at(2), details_1.direction.at(2)) 
      << "c1 - incorrect direction z initialization";

    EXPECT_FLOAT_EQ(c2.GetDirection().at(0), details_2.direction.at(0)) 
      << "c2 - incorrect direction x initialization";
    EXPECT_FLOAT_EQ(c2.GetDirection().at(1), details_2.direction.at(1)) 
      << "c2 - incorrect direction y initialization";
    EXPECT_FLOAT_EQ(c2.GetDirection().at(2), details_2.direction.at(2)) 
      << "c2 - incorrect direction z initialization";
    
    EXPECT_FLOAT_EQ(c3.GetDirection().at(0), details_3.direction.at(0)) 
      << "c3 - incorrect direction x initialization";
    EXPECT_FLOAT_EQ(c3.GetDirection().at(1), details_3.direction.at(1)) 
      << "c3 - incorrect direction y initialization";
    EXPECT_FLOAT_EQ(c3.GetDirection().at(2), details_3.direction.at(2)) 
      << "c3 - incorrect direction z initialization";

    /* Check that radius gets set to expected value */
    EXPECT_FLOAT_EQ(c1.GetRadius(), details_1.radius) 
      << "c1 - incorrect radius initialization";

    EXPECT_FLOAT_EQ(c2.GetRadius(), details_2.radius) 
      << "c2 - incorrect radius initialization";
    
    EXPECT_FLOAT_EQ(c3.GetRadius(), details_3.radius) 
      << "c3 - incorrect radius initialization";

    /* Check that version gets set to expected value */
    EXPECT_EQ(c1.GetVersion(), 0) 
      << "c1 - incorrect version initialization";

    EXPECT_EQ(c2.GetVersion(), 0) 
      << "c2 - incorrect version initialization";
    
    EXPECT_EQ(c3.GetVersion(), 0) 
      << "c3 - incorrect version initialization";

    /* Check that dynamic gets set to expected value */
    EXPECT_EQ(c1.IsDynamic(), false) 
      << "c1 - incorrect dynamic initialization";

    EXPECT_EQ(c2.IsDynamic(), false) 
      << "c2 - incorrect dynamic initialization";
    
    EXPECT_EQ(c3.IsDynamic(), false) 
      << "c3 - incorrect dynamic initialization";

  } // ConstructorTests

}  // namespace csci3081
