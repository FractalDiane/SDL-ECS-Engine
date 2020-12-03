#include "Math.h"

std::random_device Math::device{};
std::mt19937 Math::random_engine{Math::device()};
