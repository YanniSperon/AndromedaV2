#pragma once

#include <chrono>

namespace Andromeda
{
	using TimePoint = std::chrono::high_resolution_clock::time_point;
	using HighResolutionClock = std::chrono::high_resolution_clock;
}