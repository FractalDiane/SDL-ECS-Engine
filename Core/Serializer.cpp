#include "Serializer.h"

#include <typeinfo>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <streambuf>

#include "Core/ECSSystem.h"

#include "ThirdParty/json.hpp"

using nlohmann::json;

void Serializer::register_types() {
    
}


void Serializer::serialize_world(const World& world) {
    for (auto& entity : world.get_entity_list()) {
        ECS_PRINT("Entity %lu", entity->get_id());
        for (auto& pair : entity->get_components()) {
            ECS_PRINT("Component %s", demangle_component_name(typeid(*pair.second).name()).c_str());
        }
    }
}

std::string Serializer::deserialize_scene(const std::string& filepath, World& world) {
    std::ifstream file{filepath, std::ios::binary};
    std::string contents{(std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()};
    file.close();

    auto js = json::parse(contents);
    for (auto it = js.begin(); it != js.end(); it++) {
        auto object = *it;
        if (object["type"].get<Type>() == Type::Entity) {
            DEBUG_PRINT("Deserializing entity %s:", it.key().c_str());
            for (auto& comp : object["components"]) {
                std::string type = comp["type"].get<std::string>();
                DEBUG_PRINT("Deserializing component %s", type.c_str());
            }
        }
        else {
            DEBUG_PRINT("Deserializing system %s", object["system"].get<std::string>().c_str());
        }
    }

    return contents;
}

std::string Serializer::demangle_component_name(std::string name) {
    name.erase(std::remove_if(name.begin(), name.end(), [](const char& c) { return std::isdigit(c); }), name.end());
    return name;
}
