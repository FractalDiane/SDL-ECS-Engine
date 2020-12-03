#include "Serializer.h"

#include <typeinfo>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <streambuf>

#include "Components/Transform.h"
#include "Components/Sprite.h"
#include "Components/AnimatedSprite.h"
#include "Components/BoxCollider.h"
#include "Components/PlayerComponent.h"

#include "Entities/Entity.h"
#include "Core/ECSSystem.h"

#include "ThirdParty/json.hpp"

using nlohmann::json;

#define COMPONENT_INFO(_Type) {#_Type, TypeInfo{typeid(_Type), sizeof(_Type)}}

std::unordered_map<std::string, Serializer::TypeInfo> Serializer::component_ids = {
    COMPONENT_INFO(Transform),
    COMPONENT_INFO(Sprite),
    COMPONENT_INFO(AnimatedSprite),
    COMPONENT_INFO(BoxCollider),
    COMPONENT_INFO(PlayerComponent)
};

#undef COMPONENT_INFO


std::string Serializer::deserialize_scene(const std::string& filepath, World& world) {
    std::ifstream file{filepath, std::ios::binary};
    std::string contents{(std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()};
    file.close();

    auto js = json::parse(contents);
    for (auto it = js.begin(); it != js.end(); it++) {
        auto object = *it;
        if (object["type"].get<Type>() == Type::Entity) {
            DEBUG_PRINT("Deserializing entity %s:", it.key().c_str());
            Entity* this_entity = new Entity();
            this_entity->set_id(object["id"].get<unsigned long>());

            for (auto& comp : object["components"]) {
                std::string type = comp["type"].get<std::string>();
                DEBUG_PRINT("Deserializing component %s", type.c_str());

                TypeInfo component_info = component_ids[type];
                void* memory = std::malloc(component_info.size);
                DEBUG_PRINT("Allocating %lu bytes for component %s", component_info.size, type.c_str());
                Component* this_component;
                memory = this_component;

                for (auto memberit = comp["members"].begin(); memberit != comp["members"].end(); memberit++) {
                    DEBUG_PRINT("Member %s", memberit.key().c_str());
                }
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
