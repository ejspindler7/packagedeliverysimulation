#include "gtest/gtest.h"  
#include "picojson_test_objects.h"

namespace csci3081 {

    PicoJsonObjectDrone::PicoJsonObjectDrone(std::string type,
                     std::string name,
                     std::string mesh,
                     std::vector<float> position,
                     std::vector<float> scale,
                     std::vector<float> rotation, 
                     std::vector<float> direction,
                     float speed,
                     float radius,
                     float start,
                     float duration,
                     std::vector<float> offset) {
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
        this->obj = JsonHelper::CreateJsonObject();
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

    PicoJsonObjectPackage::PicoJsonObjectPackage(std::string type,
                     std::string name,
                     std::string mesh,
                     std::vector<float> position,
                     std::vector<float> scale,
                     std::vector<float> direction,
                     float radius,
                     std::vector<float> rotation, 
                     std::vector<float> offset) {
        this->type = type;
        this->name = name;
        this->mesh = mesh;
        this->position = position;
        this->scale = scale;
        this->direction = direction;
        this->radius = radius;
        this->rotation = rotation;
        this->offset = offset;
        this->obj = JsonHelper::CreateJsonObject();
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

    PicoJsonObjectCustomer::PicoJsonObjectCustomer(std::string type,
                     std::string name,
                     std::string mesh,
                     std::vector<float> position,
                     std::vector<float> scale,
                     std::vector<float> direction,
                     float radius,
                     std::vector<float> rotation) {
        this->type = type;
        this->name = name;
        this->mesh = mesh;
        this->position = position;
        this->scale = scale;
        this->direction = direction;
        this->radius = radius;
        this->rotation = rotation;
        this->obj = JsonHelper::CreateJsonObject();
        JsonHelper::AddStringToJsonObject(obj, "type", this->type);
        JsonHelper::AddStringToJsonObject(obj, "name", this->name);
        JsonHelper::AddStringToJsonObject(obj, "mesh", this->mesh);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "position", this->position);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "scale", this->scale);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "direction", this->direction);
        JsonHelper::AddFloatToJsonObject(obj, "radius", this->radius);
        JsonHelper::AddStdFloatVectorToJsonObject(obj, "rotation", this->rotation);
    } // PicoJsonObjectCustomer()
} //namespace csci3081