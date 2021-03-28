#include "delivery_simulation.h"

namespace csci3081 {

  DeliverySimulation::DeliverySimulation() {}

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

  void DeliverySimulation::ScheduleDelivery(IEntity* package, IEntity* dest) {
    Package* package_ptr = dynamic_cast<Package*>(package); 
    if (package_ptr) {
      package_ptr->SetDestination(dest->GetPosition());
      // find a drone to deliver package
      for (auto entity : entities_) {
        Drone* drone = dynamic_cast<Drone*>(entity);
        if (drone && drone->IsAvailable()) {
          drone->SetGraph(graph_);
          drone->SetPackage(package_ptr);
          return;
        } // if
      } // for
      // no drone available to deliver pacakage at the moment
      package_queue_.push(package_ptr); 
    } else { 
      std::cout << "Failed to schedule delivery: invalid package pointer" << std::endl;
    } // else
  } // ScheduleDelivery(IEntity*, IEntity*)

  void DeliverySimulation::AddObserver(IEntityObserver* observer) {}

  void DeliverySimulation::RemoveObserver(IEntityObserver* observer) {}

  const std::vector<IEntity*>& DeliverySimulation::GetEntities() const {
    return entities_; 
  } // GetEntities()

  void DeliverySimulation::Update(float dt) {
    for (auto entity : entities_) {
      Drone* drone = dynamic_cast<Drone*>(entity);
      if (drone) {
        if (!package_queue_.empty() && drone->IsAvailable()) {
          // assign drone to scheduled package
          drone->SetPackage(package_queue_.front());
          package_queue_.pop();
        } // if
        drone->Update(dt);
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
