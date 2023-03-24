#pragma once

#include <vector>
#include <unordered_map>
#include <queue>
#include <deque>
#include <list>

namespace Andromeda
{
	template <class T>
	using Array = std::vector<T>;
	template <class T, class U>
	using HashMap = std::unordered_map<T, U>;
	template <class T>
	using Queue = std::queue<T>;
	template <class T>
	using DQueue = std::deque<T>;
	template <class T>
	using LinkedList = std::list<T>;
}