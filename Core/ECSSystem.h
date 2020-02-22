#pragma once

#include <cstdio>

#define __ECS_GREEN "\033[0;32m"
#define __ECS_RED "\033[0;31m"
#define __ECS_YELLOW "\033[1;33m"
#define __ECS_RESET "\033[0m"

#define ECS_PRINT_MESSAGE(Fmt, ...) std::fprintf(stdout, __ECS_RESET "[" __ECS_GREEN "ECS" __ECS_RESET "] " Fmt "\n", __VA_ARGS__)
#define ECS_PRINT_WARNING(Fmt, ...) std::fprintf(stderr, __ECS_RESET "[" __ECS_GREEN "ECS" __ECS_RESET "] " __ECS_YELLOW "WARNING: " Fmt __ECS_RESET "\n", __VA_ARGS__)
#define ECS_PRINT_ERROR(Fmt, ...) std::fprintf(stderr, __ECS_RESET "[" __ECS_GREEN "ECS" __ECS_RESET "] " __ECS_RED "ERROR: " Fmt __ECS_RESET "\n", __VA_ARGS__)
