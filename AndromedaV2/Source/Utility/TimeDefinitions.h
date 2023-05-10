#pragma once

#include <chrono>

namespace Andromeda
{
	using Duration = double; // Duration in seconds
	using TimePoint = std::chrono::high_resolution_clock::time_point;
	using DurationNanoseconds = std::chrono::duration<long long, std::nano>;
	using HighResolutionClock = std::chrono::high_resolution_clock;
}