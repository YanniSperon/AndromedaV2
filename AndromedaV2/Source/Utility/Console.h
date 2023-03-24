#pragma once

#include "IntDefinitions.h"
#include "StandardDefinitions.h"
#include "StandardCollectionsDefinitions.h"

namespace Andromeda {
	class Console {
	private:
		DQueue<String> m_Log;
		Mutex m_PrintMutex;
		uint64 m_MaxLogLength;
		uint64 m_DefaultBufferSize;

	public:
		Console(uint64 maxLogLength, uint64 defaultBufferSize = 1024ull);

		void Success(const char* fmt, ...);
		void Info(const char* fmt, ...);
		void Warning(const char* fmt, ...);
		void Error(const char* fmt, ...);
		void FatalError(const char* fmt, ...);
		void Assert(bool value, const char* fmt, ...);

		void Success(uint64 bufferSize, const char* fmt, ...);
		void Info(uint64 bufferSize, const char* fmt, ...);
		void Warning(uint64 bufferSize, const char* fmt, ...);
		void Error(uint64 bufferSize, const char* fmt, ...);
		void FatalError(uint64 bufferSize, const char* fmt, ...);

	};
}