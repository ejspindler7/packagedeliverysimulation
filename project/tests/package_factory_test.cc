#include "gtest/gtest.h"
#include "../include/package_factory.h"
#include "picojson_test_objects.h"

namespace csci3081 {
  
  class PackageFactoryTest : public ::testing::Test {
    public: 
      void SetUp() {
        details_1 = PicoJsonObjectDrone("drone",
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

        details_2 = PicoJsonObjectDrone("drone",
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
        p_details_1 = PicoJsonObjectPackage("package",
                                   "package2",
                                   "models/cardboardBox.glb",
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   0.0,
                                   std::vector<float> {0.0, 0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0});

        p_details_2 = PicoJsonObjectPackage("package",
                                   "package3",
                                   "models/cardboardBox.glb",
                                   std::vector<float> {3.0, 4.0, 5.0},
                                   std::vector<float> {6.0, 7.0, 8.0},
                                   std::vector<float> {9.0, 10.0, 11.0},
                                   12.0,
                                   std::vector<float> {13.0, 14.0, 15.0, 16.0},
                                   std::vector<float> {17.0, 18.0, 19.0});

        c_details_1 = PicoJsonObjectCustomer("customer",
                                   "customer2",
                                   "models/RobotExpressive.glb",
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   std::vector<float> {0.0, 0.0, 0.0},
                                   0.0,
                                   std::vector<float> {0.0, 0.0, 0.0, 0.0});

        c_details_2 = PicoJsonObjectCustomer("customer",
                                   "customer3",
                                   "models/RobotExpressive.glb",
                                   std::vector<float> {3.0, 4.0, 5.0},
                                   std::vector<float> {6.0, 7.0, 8.0},
                                   std::vector<float> {9.0, 10.0, 11.0},
                                   12.0,
                                   std::vector<float> {13.0, 14.0, 15.0, 16.0});
      } // SetUp()

    protected:
      PackageFactory pf;
      PicoJsonObjectDrone details_1;
      PicoJsonObjectDrone details_2;
      PicoJsonObjectPackage p_details_1;
      PicoJsonObjectPackage p_details_2;
      PicoJsonObjectCustomer c_details_1;
      PicoJsonObjectCustomer c_details_2;
  }; 

  /*******************************************************************************
   * Test Cases
   ******************************************************************************/

  TEST_F(PackageFactoryTest, CreateEntityTests) {
    IEntity* entity = pf.CreateEntity(p_details_1.obj);
    EXPECT_NE(entity, nullptr) << "Create entity package error";

    entity = pf.CreateEntity(p_details_2.obj);
    EXPECT_NE(entity, nullptr) << "Create entity package error";

    entity = pf.CreateEntity(details_1.obj);
    EXPECT_EQ(entity, nullptr) << "Create entity drone error";

    entity = pf.CreateEntity(details_2.obj);
    EXPECT_EQ(entity, nullptr) << "Create entity drone error";

    entity = pf.CreateEntity(c_details_1.obj);
    EXPECT_EQ(entity, nullptr) << "Create entity customer error";

    entity = pf.CreateEntity(c_details_2.obj);
    EXPECT_EQ(entity, nullptr) << "Create entity customer error";
  }

}  // namespace csci3081
