#pragma once

#include <chrono>

namespace Andromeda
{
	using HighResolutionClock = std::chrono::high_resolution_clock;
	using TimePoint = std::chrono::high_resolution_clock::time_point;

	using Duration = double; // Value in seconds as a double

	// Returns the duration in seconds as a double from the std::chrono::nanoseconds
	Duration RichTimeToDuration(std::chrono::nanoseconds n);

	// Returns the duration in seconds as a double from the std::chrono::microseconds
	Duration RichTimeToDuration(std::chrono::microseconds n);

	// Returns the duration in seconds as a double from the std::chrono::milliseconds
	Duration RichTimeToDuration(std::chrono::milliseconds n);

	// Returns the duration in seconds as a double from the std::chrono::seconds
	Duration RichTimeToDuration(std::chrono::seconds n);

	// Returns the duration in seconds as a double from the std::chrono::minutes
	Duration RichTimeToDuration(std::chrono::minutes n);

	// Returns the duration in seconds as a double from the std::chrono::hours
	Duration RichTimeToDuration(std::chrono::hours n);

	// Returns the duration in seconds as a double from the std::chrono::days
	Duration RichTimeToDuration(std::chrono::days n);

	// Returns the duration in seconds as a double from the std::chrono::weeks
	Duration RichTimeToDuration(std::chrono::weeks n);

	// Returns the duration in seconds as a double from the std::chrono::months
	Duration RichTimeToDuration(std::chrono::months n);

	// Returns the duration in seconds as a double from the std::chrono::years
	Duration RichTimeToDuration(std::chrono::years n);
}