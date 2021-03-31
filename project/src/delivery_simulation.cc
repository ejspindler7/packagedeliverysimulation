#include "delivery_simulation.h"
#include "drone_factory.h"
#include "customer_factory.h"
#include "robot_factory.h"
#include "package_factory.h"

namespace csci3081 {

  DeliverySimulation::DeliverySimulation() {
    composite_factory_.AddFactory(new DroneFactory());
    composite_factory_.AddFactory(new RobotFactory());
    composite_factory_.AddFactory(new PackageFactory());
    composite_factory_.AddFactory(new CustomerFactory());
  } // DeliverySimulation()

  DeliverySimulation::~DeliverySimulation() {
    for (auto entity : entities_) {
      delete entity;
    } // for
  } // ~DeliverySimulation()

  IEntity* DeliverySimulation::CreateEntity(const picojson::object& val) {
    return composite_factory_.CreateEntity(val);
  } // CreateEntity()

  void DeliverySimulation::AddFactory(IEntityFactory* factory) {
    composite_factory_.AddFactory(factory);
  } // AddFactory(IEntityFactory*)

  void DeliverySimulation::AddEntity(IEntity* entity) { 
    entities_.push_back(entity); 

  } // AddEntity()

  void DeliverySimulation::SetGraph(const IGraph* graph) {
    graph_ = graph;
  } // SetGraph(IGraph*)

  Courier* ClosestAvailCourier(const std::vector<IEntity*> entities,
                               const Package* package) {
      Courier* closest_courier = nullptr;
      float distance = -1.0;
      for (auto entity : entities) {
        Courier* temp_courier = dynamic_cast<Courier*>(entity);
        if (temp_courier && temp_courier->IsAvailable()) {
            Vector3D package_pos(package->GetPosition());
            Vector3D courier_pos(temp_courier->GetPosition());
            float distance_to_pkg = (package_pos - courier_pos).Magnitude();
            if (!closest_courier || distance_to_pkg < distance) {
              closest_courier = temp_courier;
              distance = distance_to_pkg;
            } // if !closest_courier
        } // if temp_courier
      } // for
      return closest_courier;
  } // FindClosestAvailableCourier(Package*)

  void DeliverySimulation::ScheduleDelivery(IEntity* package, IEntity* dest) {
    Package* package_ptr = dynamic_cast<Package*>(package); 
    //creating notification for package
    picojson::object notifications = JsonHelper::CreateJsonNotification();
    JsonHelper::AddStringToJsonObject(notifications,"value", "scheduled");
    if (package_ptr) {
      package_ptr->SetDestination(dest->GetPosition());
      // find a courier to deliver package
      Courier* courier = ClosestAvailCourier(entities_, package_ptr);
      if (courier) { 
        courier->SetGraph(graph_);
        courier->SetPackage(package_ptr);
        notifyObserver(notifications, package);
        courier->setNotification(1);
      } else {
        // no courier available to deliver package at the moment
        package_queue_.push(package_ptr); 
      } // else
    } else { 
      std::cout << "Failed to schedule delivery: invalid package pointer" 
                << std::endl;
    } // else
  } // ScheduleDelivery(IEntity*, IEntity*)

  void DeliverySimulation::AddObserver(IEntityObserver* observer) {
    observers_.push_back(observer);
  }

  void DeliverySimulation::RemoveObserver(IEntityObserver* observer) {
    observers_.pop_back();
  }
  
  void DeliverySimulation::notifyObserver(picojson::object& event, IEntity* entity){
      picojson::value notificationsVal = JsonHelper::ConvertPicojsonObjectToValue(event);
      for (int i = 0; i < observers_.size(); i++) {
        observers_[i]->OnEvent(notificationsVal, *entity);
      }
  }

  const std::vector<IEntity*>& DeliverySimulation::GetEntities() const {
    return entities_; 
  } // GetEntities()

  void DeliverySimulation::Update(float dt) {  
    if (!package_queue_.empty()) { // assign closest available courier to package
      Courier* free_courier = ClosestAvailCourier(entities_,
                                                  package_queue_.front());
      if (free_courier) {
        free_courier->SetGraph(graph_);
        free_courier->SetPackage(package_queue_.front());
        package_queue_.pop();
        picojson::object notifications = JsonHelper::CreateJsonNotification();
        JsonHelper::AddStringToJsonObject(notifications,"value", "moving");
        notifyObserver(notifications, free_courier);

      } // if courier
    } // if !package_queue_.empty()
    for (auto entity : entities_) { // update each courier
      Courier* courier = dynamic_cast<Courier*>(entity);
      if (courier) {
        //when package is picked up notify observers
        if ((courier->GetStatus() == 2) && (courier->getNotification() == 1)){
            picojson::object notifications = JsonHelper::CreateJsonNotification();
            JsonHelper::AddStringToJsonObject(notifications,"value", "en route");
            notifyObserver(notifications, courier);
            courier->setNotification(2);

        }//when package is delivered notify observers
        else if ((courier->GetStatus() == 0) && (courier->getNotification() == 2)){
            picojson::object notifications = JsonHelper::CreateJsonNotification();
            JsonHelper::AddStringToJsonObject(notifications,"value", "delivered");
            notifyObserver(notifications, courier);
            courier->setNotification(0);
        } //trying to check if notifications is idle
        else if (courier->IsDynamic() == false){
          picojson::object notifications = JsonHelper::CreateJsonNotification();
          JsonHelper::AddStringToJsonObject(notifications,"value", "idle");
          notifyObserver(notifications, courier);
        }

        courier->Update(dt);
      } // if
    } // for
  } // Update(float);

  // DO NOT MODIFY THE FOLLOWING UNLESS YOU REALLY KNOW WHAT YOU ARE DOING
  void DeliverySimulation::RunScript(const picojson::array& script, IEntitySystem* system) const {
    JsonHelper::PrintArray(script);
    IDeliverySystem* deliverySystem = dynamic_cast<IDeliverySystem*>(system);
    if (deliverySystem) {

      // To store the unadded entities_
      std::vector<IEntity*> created_entities;

      for (unsigned int i=0; i < script.size(); i++) {
        const picojson::object& object = script[i].get<picojson::object>();
        const std::string cmd = object.find("command")->second.get<std::string>();
        const picojson::object& params = object.find("params")->second.get<picojson::object>();
        // May want to replace the next few if-statements with an enum
        if (cmd == "createEntity") {
          IEntity* entity = NULL;
          entity = deliverySystem->CreateEntity(params);
          if (entity) {
            created_entities.push_back(entity);
          } else {
            std::cout << "Null entity" << std::endl;
          } // else
        } else if (cmd == "addEntity") {
          int ent_index = static_cast<int>(params.find("index")->second.get<double>());
          if (ent_index >= 0 && ent_index < created_entities.size()) {
            deliverySystem->AddEntity(created_entities[ent_index]);
          } // if
        } else if (cmd == "scheduleDelivery" ) {
          int pkg_index = static_cast<int>(params.find("pkg_index")->second.get<double>());
          int dest_index = static_cast<int>(params.find("dest_index")->second.get<double>());
          if (pkg_index >= 0 && pkg_index < system->GetEntities().size()) {
            IEntity* pkg = deliverySystem->GetEntities()[pkg_index];
            if (dest_index >= 0 && pkg_index < system->GetEntities().size()) {
              IEntity* cst = system->GetEntities()[dest_index];
              if (pkg && cst) {
                deliverySystem->ScheduleDelivery(pkg, cst);
              } // if pkg
            } // if dest_index
          } else {
            std::cout << "Failed to schedule delivery: invalid indexes" << std::endl;
          } // else
        } // else if 
      } // for
    } // if
  } // RunScript(const picojson::array&, IEntitySystem*)

} // namespace csci3081 
