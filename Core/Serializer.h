#pragma once

#include <string>
#include <unordered_map>
#include <stack>
#include <regex>
#include <typeindex>
#include <cstdlib>

#include "Core/World.h"
#include "Core/ECSSystem.h"

class Serializer {
private:
    static const std::regex line_regex;
    static const std::regex list_item_regex;

    struct TypeInfo {
        std::type_index type;
        std::size_t size;

        TypeInfo() : type{typeid(Component)}, size{sizeof(Component)} {}
        TypeInfo(const std::type_index& _type, std::size_t _size) : type{_type}, size{_size} {}
    };

    static std::unordered_map<std::string, TypeInfo> component_ids;

    enum class Type {
        Entity,
        System
    };

public:
    template <typename C>
    static void register_component(const std::string& name) {
        component_ids[name] = TypeInfo{typeid(C), sizeof(C)};
    }

    static std::string deserialize_scene(const std::string& filepath, World& world);

private:
    template <typename T>
    static void read_type_bytes(Component* target, std::size_t offset, void* source) {
        std::memcpy(target + offset, source, sizeof(T));
    }

    static std::string demangle_component_name(std::string name);
};
