#include <fstream>
#include <regex>
#include <unordered_map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "Components/Transform.h"
#include "Components/Sprite.h"
#include "Components/AnimatedSprite.h"
#include "Components/BoxCollider.h"



class FileParser {
private:
	struct TypeRegistration {
		std::type_index typeindex;
		std::size_t typesize;
	};

	enum class MemberType {
		Bool,
		Int,
		Float,
		String,
		Vector2
	};

	struct MemberInfo {
		
	};

	static const std::regex string_regex;
	static const std::regex vector2_regex;

	static const std::unordered_map<std::string, TypeRegistration> component_map;

public:
	static void read_file(const std::string& file);

private:
	enum class ReadMode { Default, Entity, Component };
	static void parse_line(const std::string& line, Entity* current_entity, ReadMode& mode);

	static bool parse_bool(const std::string& line);
	static int parse_int(const std::string& line);
	static float parse_float(const std::string& line);
	static Vector2 parse_vector2(const std::string& line);
};
