#pragma once

#include "Types.h"

namespace Andromeda {
	class Console {
	private:
		DQueue<String> m_Log;
		Mutex m_PrintMutex;
		uint64 m_MaxLogLength;

	public:
		Console(uint64 maxLogLength);

		void Success(const char* fmt, ...);
		void Info(const char* fmt, ...);
		void Warning(const char* fmt, ...);
		void Error(const char* fmt, ...);
		void FatalError(const char* fmt, ...);
		void Assert(bool value, const char* fmt, ...);

	};
}