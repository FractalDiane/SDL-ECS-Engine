#include "FileParser.h"

#include "Entities/Entity.h"

#include <sstream>
#include <cstdlib>

//#define REGISTER_TYPE(Type) {#Type, typeid(Type)}
#define REGISTER_TYPE(Type) {#Type, FileParser::TypeRegistration{typeid(Type), sizeof(Type)}}

const std::unordered_map<std::string, FileParser::TypeRegistration> FileParser::component_map = {
	REGISTER_TYPE(Transform),
	REGISTER_TYPE(Sprite),
	REGISTER_TYPE(AnimatedSprite),
	REGISTER_TYPE(BoxCollider),
};

#undef REGISTER_TYPE

const std::regex FileParser::string_regex{R"re(^"(.*)"$)re"};
const std::regex FileParser::vector2_regex{R"re(^\(([\d.]+),\s*([\d.]+)\)$)re"};


void FileParser::read_file(const std::string& file_) {
	std::fstream file;
	try {
		file.open(file_);

		std::string line;
		ReadMode mode = ReadMode::Default;
		Entity* current_entity = nullptr;

		while (std::getline(file, line)) {
			//ECS_PRINT_WARNING("%s", line.c_str());
			parse_line(line, current_entity, mode);
		}

		if (file.is_open())
			file.close();
	}
	catch (...) {
		if (file.is_open())
			file.close();
		throw;
	}
}


void FileParser::parse_line(const std::string& line, Entity* current_entity, ReadMode& mode) {
	switch (mode) {
		case ReadMode::Default: {
			if (!line.empty()) {
				mode = ReadMode::Entity;
				current_entity = new Entity{};
				return;
			}
		} break;

		case ReadMode::Entity: {
			if (line.empty()) {
				mode = ReadMode::Default;
				return;
			}

			std::string type = line.substr(1);
			TypeRegistration info = component_map.at(type);
			void* comp = std::malloc(info.typesize);
			//auto ptr = 
			//ECS_PRINT_WARNING("%s", line.substr(1).c_str());
			//Component* comp = new Component{};
			//auto comp_cast = dynamic_cast<component_map[line]>
			//void* comp = std::malloc(sizeof(component_map.at(line)));
		} break;

		case ReadMode::Component: {

		} break;
	}
	
}


bool FileParser::parse_bool(const std::string& line) {
	return line != "0" && line != "false";
}

int FileParser::parse_int(const std::string& line) {
	return std::stoi(line);
}

float FileParser::parse_float(const std::string& line) {
	return std::stof(line);
}

Vector2 FileParser::parse_vector2(const std::string& line) {
	std::smatch match;
	if (std::regex_match(line, match, vector2_regex))
		return Vector2{std::stof(match.str(1)), std::stof(match.str(2))};

	throw std::bad_cast{};
}
