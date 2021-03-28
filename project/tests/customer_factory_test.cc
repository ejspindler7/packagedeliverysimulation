#include "gtest/gtest.h"
#include "../include/customer_factory.h"

namespace csci3081 {

  class PicoJsonObjectDrone {
    public:
      // attributes
      std::string type;
      std::string name;
      std::string mesh;
      std::vector<float> position;
      std::vector<float> scale;
      std::vector<float> rotation;
      std::vector<float> direction;
      float speed;
      float radius;
      float start;
      float duration;
      std::vector<float> offset;
      picojson::object obj;
      // constructor
      PicoJsonObjectDrone(std::string type = "drone",
                     std::string name = "drone",
                     std::string mesh = "models/s9drone.glb",
                     std::vector<float> position = std::vector<float> {1.0, 2.0, 3.0},
                     std::vector<float> scale = std::vector<float> {0.25, 0.25, 0.25},
                     std::vector<float> rotation = std::vector<float> {0, 0, 0, 0}, 
                     std::vector<float> direction = std::vector<float> {1.0, 1.0, 1.0},
                     float speed = 30.0,
                     float radius = 1.0,
                     float start = 2.0,
                     float duration = 2.0,
                     std::vector<float> offset = std::vector<float> {0, 0.2, 0}) {
        this->type = type;
        this->name = name;
        this->mesh = mesh;
        this->position = position;
        this->scale = scale;
        this->rotation = rotation;
        this->direction = direction;
        this->speed = speed;
        this->radius = radius;
        this->start = start;
        this->duration = duration;
        this->offset = offset;
        obj = JsonHelper::CreateJsonObject();
        JsonHelper::AddStringToJsonObject(obj, "type", this->type);
        JsonHelper::AddStringToJsonObject(obj, "name", this->name);
        JsonHelper::AddStringToJsonObject(obj, "mesh", this->mesh);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", this->position);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "scale", this->scale);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "rotation", this->rotation);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", this->direction);
        JsonHelper::AddFloatToJsonObject(obj, "speed", this->speed);
        JsonHelper::AddFloatToJsonObject(obj, "radius", this->radius);
        JsonHelper::AddFloatToJsonObject(obj, "start", this->start);
        JsonHelper::AddFloatToJsonObject(obj, "duration", this->duration);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "offset", this->offset);
        // print out the built PicoJson object
        /* JsonHelper::PrintEntityDetails(obj); */
      } // PicoJsonObjectDrone()
  }; // PicoJsonObjectDrone

  class PicoJsonObjectPackage {
    public:
      // attributes
      std::string type;
      std::string name;
      std::string mesh;
      std::vector<float> position;
      std::vector<float> scale;
      std::vector<float> direction;
      float radius;
      std::vector<float> rotation;
      std::vector<float> offset;
      picojson::object obj;
      // constructor
      PicoJsonObjectPackage(std::string type = "package",
                     std::string name = "package",
                     std::string mesh = "models/cardboardBox.glb",
                     std::vector<float> position = std::vector<float> {1.0, 2.0, 3.0},
                     std::vector<float> scale = std::vector<float> {0.25, 0.25, 0.25},
                     std::vector<float> direction = std::vector<float> {1.0, 1.0, 1.0},
                     float radius = 1.0,
                     std::vector<float> rotation = std::vector<float> {0, 0, 0, 0}, 
                     std::vector<float> offset = std::vector<float> {0, 0.2, 0}) {
        this->type = type;
        this->name = name;
        this->mesh = mesh;
        this->position = position;
        this->scale = scale;
        this->direction = direction;
        this->radius = radius;
        this->rotation = rotation;
        this->offset = offset;
        obj = JsonHelper::CreateJsonObject();
        JsonHelper::AddStringToJsonObject(obj, "type", this->type);
        JsonHelper::AddStringToJsonObject(obj, "name", this->name);
        JsonHelper::AddStringToJsonObject(obj, "mesh", this->mesh);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", this->position);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "scale", this->scale);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", this->direction);
        JsonHelper::AddFloatToJsonObject(obj, "radius", this->radius);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "rotation", this->rotation);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "offset", this->offset);
        // print out the built PicoJson object
        /* JsonHelper::PrintEntityDetails(obj); */
      } // PicoJsonObjectPackage()
  }; // PicoJsonObjectPackage

  class PicoJsonObjectCustomer {
    public:
      // attributes
      std::string type;
      std::string name;
      std::string mesh;
      std::vector<float> position;
      std::vector<float> scale;
      std::vector<float> direction;
      float radius;
      std::vector<float> rotation;
      picojson::object obj;
      // constructor
      PicoJsonObjectCustomer(std::string type = "customer",
                     std::string name = "customer",
                     std::string mesh = "models/RobotExpressive.glb",
                     std::vector<float> position = std::vector<float> {1.0, 2.0, 3.0},
                     std::vector<float> scale = std::vector<float> {0.25, 0.25, 0.25},
                     std::vector<float> direction = std::vector<float> {1.0, 1.0, 1.0},
                     float radius = 1.0,
                     std::vector<float> rotation = std::vector<float> {0, 0, 0, 0}) {
        this->type = type;
        this->name = name;
        this->mesh = mesh;
        this->position = position;
        this->scale = scale;
        this->direction = direction;
        this->radius = radius;
        this->rotation = rotation;
        obj = JsonHelper::CreateJsonObject();
        JsonHelper::AddStringToJsonObject(obj, "type", this->type);
        JsonHelper::AddStringToJsonObject(obj, "name", this->name);
        JsonHelper::AddStringToJsonObject(obj, "mesh", this->mesh);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", this->position);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "scale", this->scale);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", this->direction);
        JsonHelper::AddFloatToJsonObject(obj, "radius", this->radius);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "rotation", this->rotation);
        // print out the built PicoJson object
        /* JsonHelper::PrintEntityDetails(obj); */
      } // PicoJsonObjectCustomer()
  }; // PicoJsonObjectCustomer

  class CustomerFactoryTest : public ::testing::Test {
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
      CustomerFactory cf;
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

  TEST_F(CustomerFactoryTest, CreateEntityTests) {
    IEntity* entity = cf.CreateEntity(c_details_1.obj);
    EXPECT_NE(entity, nullptr) << "Create entity customer error";

    entity = cf.CreateEntity(c_details_2.obj);
    EXPECT_NE(entity, nullptr) << "Create entity customer error";

    entity = cf.CreateEntity(details_1.obj);
    EXPECT_EQ(entity, nullptr) << "Create entity drone error";

    entity = cf.CreateEntity(details_2.obj);
    EXPECT_EQ(entity, nullptr) << "Create entity drone error";

    entity = cf.CreateEntity(p_details_1.obj);
    EXPECT_EQ(entity, nullptr) << "Create entity package error";

    entity = cf.CreateEntity(p_details_2.obj);
    EXPECT_EQ(entity, nullptr) << "Create entity package error";
  }

}  // namespace csci3081
