#include "TimeDefinitions.h"

namespace Andromeda
{
	Duration RichTimeToDuration(std::chrono::nanoseconds n)
	{
		return std::chrono::duration_cast<std::chrono::duration<Duration>>(n).count();
	}

	Duration RichTimeToDuration(std::chrono::microseconds n)
	{
		return std::chrono::duration_cast<std::chrono::duration<Duration>>(n).count();
	}

	Duration RichTimeToDuration(std::chrono::milliseconds n)
	{
		return std::chrono::duration_cast<std::chrono::duration<Duration>>(n).count();
	}

	Duration RichTimeToDuration(std::chrono::seconds n)
	{
		return std::chrono::duration_cast<std::chrono::duration<Duration>>(n).count();
	}

	Duration RichTimeToDuration(std::chrono::minutes n)
	{
		return std::chrono::duration_cast<std::chrono::duration<Duration>>(n).count();
	}

	Duration RichTimeToDuration(std::chrono::hours n)
	{
		return std::chrono::duration_cast<std::chrono::duration<Duration>>(n).count();
	}

	Duration RichTimeToDuration(std::chrono::days n)
	{
		return std::chrono::duration_cast<std::chrono::duration<Duration>>(n).count();
	}

	Duration RichTimeToDuration(std::chrono::weeks n)
	{
		return std::chrono::duration_cast<std::chrono::duration<Duration>>(n).count();
	}

	Duration RichTimeToDuration(std::chrono::months n)
	{
		return std::chrono::duration_cast<std::chrono::duration<Duration>>(n).count();
	}

	Duration RichTimeToDuration(std::chrono::years n)
	{
		return std::chrono::duration_cast<std::chrono::duration<Duration>>(n).count();
	}
}