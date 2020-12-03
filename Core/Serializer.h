#pragma once

#include <string>
#include <unordered_map>
#include <stack>
#include <regex>

#include "Core/World.h"
#include "Core/ECSSystem.h"

class Serializer {
private:
    static const std::regex line_regex;
    static const std::regex list_item_regex;

    enum Type {
        Entity,
        System
    };

    //static std::unordered_map<std::string, 

public:
    static void register_types();

    static void serialize_world(const World& world);
    static std::string deserialize_scene(const std::string& filepath, World& world);

private:
    static std::string demangle_component_name(std::string name);
};
