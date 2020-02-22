#pragma once

#include <cstdio>

#define ECS_PRINT_MESSAGE(Fmt, ...) std::fprintf(stdout, "\033[0m[\033[0;32mECS\033[0m] " Fmt "\n", __VA_ARGS__)
#define ECS_PRINT_WARNING(Fmt, ...) std::fprintf(stderr, "\033[0m[\033[0;32mECS\033[0m]\033[0;35m WARNING: " Fmt "\033[0m\n", __VA_ARGS__)
#define ECS_PRINT_ERROR(Fmt, ...) std::fprintf(stderr, "\033[0m[\033[0;32mECS\033[0m]\033[0;31m ERROR: " Fmt "\033[0m\n", __VA_ARGS__)

namespace ecs {
	
}
