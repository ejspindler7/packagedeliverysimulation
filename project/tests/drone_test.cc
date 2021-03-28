#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/drone.h"
#include "../include/package.h"

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
      } // PicoJsonObjectPackage()
  }; // PicoJsonObjectPackage

  class DroneTest : public ::testing::Test {
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

  TEST_F(DroneTest, ConstructorTests) {
    Drone d1(details_1.obj);
    Drone d2(details_2.obj);
    Drone d3(details_3.obj);

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

    /* Check that use_smart_route gets set to expected value */
    /* Note that use_smart_route is initialized to true when drone is created */
    EXPECT_EQ(d1.UsingSmartRoute(), true) 
      << "d1 - incorrect use_smart_route initialization";

    EXPECT_EQ(d2.UsingSmartRoute(), true) 
      << "d2 - incorrect use_smart_route initialization";
    
    EXPECT_EQ(d3.UsingSmartRoute(), true) 
      << "d3 - incorrect use_smart_route initialization";

    /* Check that status gets set to expected value */
    /* Note that status is initialized to kReady when drone is created */
    EXPECT_EQ(d1.IsAvailable(), true) 
      << "d1 - incorrect status initialization";

    EXPECT_EQ(d2.IsAvailable(), true) 
      << "d2 - incorrect status initialization";
    
    EXPECT_EQ(d3.IsAvailable(), true) 
      << "d3 - incorrect status initialization";
  } // ConstructorTests
  

  TEST_F(DroneTest, HasPackageTests) {
    Drone d1(details_1.obj);
    Drone d2(details_2.obj);

    Package package(p_details.obj);
    package.SetPosition(d1.GetPosition());

    d1.SetPackage(&package);
    d1.Update(1);
    EXPECT_EQ(d1.HasPackage(), true) << "d1 - HasPackage incorrect";
    EXPECT_EQ(d1.IsAvailable(), false) << "d1 - IsAvailable incorrect";

    EXPECT_EQ(d2.HasPackage(), false) << "d2 - HasPackage incorrect";
  }

  TEST_F(DroneTest, DropoffPackageTests) {
    Drone d1(details_1.obj);
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
