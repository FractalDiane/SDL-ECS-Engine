// Mathf.h

#pragma once

#include <random>
#include <cmath>

namespace {
	std::random_device device{};
	std::default_random_engine rand_engine{device()};
}

namespace Mathf {
	
	constexpr long double Pi = 3.141592653589793238462643383279502884L;
	constexpr inline float deg2rad(float degrees) { return (degrees * Pi) / 180.0f; }
	constexpr inline float rad2deg(float radians) { return (radians * 180.0f) / Pi; }


	constexpr inline float clamp(float value, float min, float max) { return (value < min) ? min : (max < value) ? max : value; }


	constexpr int wrap(int n, int min, int max) {
		int range = max - min + 1;

		if (n < min)
			n += range * ((min - n) / range + 1);

		return min + (n - min) % range;
	}


	constexpr inline int abs(int value) { return value < 0 ? -value : value; }
	constexpr inline float abs(float value) { return value < 0 ? -value : value; }

	inline float lerp(float from, float to, float weight) { return std::fma(weight, to, std::fma(-weight, from, from)); }
	inline float lerp_delta(float from, float to, float weight, float delta) { return lerp(from, to, 1.0f - std::pow(weight, delta)); }


	inline int rand_range(int min, int max) {
		std::uniform_int_distribution<> distr{min, max};
		return distr(rand_engine);
	}


	inline float rand_range(float min, float max) {
		std::uniform_real_distribution<float> distr{min, max};
		return distr(rand_engine);
	}


	template <typename T, typename... Args>
	T choose(T first, Args... args) {
		T array[] = {first, args...};
		std::uniform_int_distribution<> distr{0, sizeof...(Args)};
		return array[distr(rand_engine)];
	}
}
