#pragma once

#include <random>
#include <cmath>

namespace {
	std::random_device device{};
	std::mt19937 rand_engine{device()};
}

class Math {
private:
	static std::random_device device;
	static std::mt19937 random_engine;

public:
	static constexpr long double Pi = 3.141592653589793238462643383279502884L;
	static constexpr inline float deg2rad(float degrees) { return (degrees * Pi) / 180.0f; }
	static constexpr inline float rad2deg(float radians) { return (radians * 180.0f) / Pi; }


	static constexpr inline float clamp(float value, float min, float max) { return (value < min) ? min : (max < value) ? max : value; }


	static constexpr int wrap(int value, int min, int max) {
		int64_t range = max - min;
		return range == 0 ? min : min + ((((value - min) % range) + range) % range);
	}


	static constexpr inline int abs(int value) { return value < 0 ? -value : value; }
	static constexpr inline float abs(float value) { return value < 0.0f ? -value : value; }

	static inline float lerp(float from, float to, float weight) { return from + (to - from) * weight; }
	static inline float lerp_delta(float from, float to, float weight, float delta) { return lerp(from, to, 1.0f - std::pow(weight, delta)); }


	static inline int rand_range(int min, int max) {
		std::uniform_int_distribution<> distr{min, max};
		return distr(random_engine);
	}


	static inline float rand_range(float min, float max) {
		std::uniform_real_distribution<float> distr{min, max};
		return distr(random_engine);
	}


	template <typename T, typename... Args>
	static T choose(T first, Args... args) {
		T array[] = {first, args...};
		std::uniform_int_distribution<> distr{0, sizeof...(Args)};
		return array[distr(random_engine)];
	}
};
