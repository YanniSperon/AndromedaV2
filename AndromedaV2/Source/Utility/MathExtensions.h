#pragma once

// TODO
#include <algorithm>

namespace Andromeda {
	namespace Math {
		template <class T>
		static const T& Min(const T& a, const T& b)
		{
			return std::min(a, b);
		}
	}
}