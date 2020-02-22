#pragma once

#include <cstdio>

#define __GREEN "\033[0;32m"
#define __RED "\033[0;31m"
#define __MAGENTA "\033[1;35m"
#define __RESET "\033[0m"

#define ECS_PRINT_MESSAGE(Fmt, ...) std::fprintf(stdout, __RESET "[" __GREEN "ECS" __RESET "] " Fmt "\n", __VA_ARGS__)
#define ECS_PRINT_WARNING(Fmt, ...) std::fprintf(stderr, __RESET "[" __GREEN "ECS" __RESET "] " __MAGENTA "WARNING: " Fmt __RESET "\n", __VA_ARGS__)
#define ECS_PRINT_ERROR(Fmt, ...) std::fprintf(stderr, __RESET "[" __GREEN "ECS" __RESET "] " __RED "ERROR: " Fmt __RESET "\n", __VA_ARGS__)
