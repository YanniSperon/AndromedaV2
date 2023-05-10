#pragma once

#include <mutex>
#include <string>

namespace Andromeda
{
	using Mutex = std::mutex;
	using String = std::string;
	template <class T, class U>
	using Pair = std::pair<T, U>;
}