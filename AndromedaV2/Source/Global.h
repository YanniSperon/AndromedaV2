#pragma once

#include <vector>
#include <string>
#include <chrono>

class Global {
public:
	static void Initialize(/*uint64 instanceID*/);
	static std::chrono::steady_clock::time_point& GetStartTime();
	static std::vector<std::string>& GetConsoleLog();
	static void Update();
	static void Cleanup();
};
