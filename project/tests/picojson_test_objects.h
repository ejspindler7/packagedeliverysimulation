  
  #include "gtest/gtest.h"
  #include "json_helper.h"
  
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
                     std::vector<float> offset = std::vector<float> {0, 0.2, 0});

  }; // PicoJsonObjectDrone

  class PicoJsonObjectRobot {
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
      PicoJsonObjectRobot(std::string type = "robot",
                     std::string name = "robot",
                     std::string mesh = "models/robot.glb",
                     std::vector<float> position = std::vector<float> {1.0, 2.0, 3.0},
                     std::vector<float> scale = std::vector<float> {0.25, 0.25, 0.25},
                     std::vector<float> rotation = std::vector<float> {0, 0, 0, 0}, 
                     std::vector<float> direction = std::vector<float> {1.0, 1.0, 1.0},
                     float speed = 30.0,
                     float radius = 1.0,
                     float start = 2.0,
                     float duration = 2.0,
                     std::vector<float> offset = std::vector<float> {0, 0.2, 0});

  }; // PicoJsonObjectRobot

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
                     std::vector<float> offset = std::vector<float> {0, 0.2, 0});
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
                     std::vector<float> rotation = std::vector<float> {0, 0, 0, 0});
  }; // PicoJsonObjectCustomer
}  // namespace csci3081