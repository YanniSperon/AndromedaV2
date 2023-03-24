#pragma once

#include "Utility/TimeDefinitions.h"
#include "Utility/Console.h"

//TODO

namespace Andromeda {
	class Global {
	public:
		static void Initialize(/*uint64 instanceID*/);
		static Console& GetConsoleInstance();
		static TimePoint& GetStartTime();
		static void Update();
		static void Cleanup();
	};
}