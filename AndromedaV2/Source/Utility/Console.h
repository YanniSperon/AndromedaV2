#pragma once

#include "IntDefinitions.h"
#include "StandardDefinitions.h"
#include "StandardCollectionsDefinitions.h"

#include <fstream>

namespace Andromeda {
	class Console {
	private:
		DQueue<String> m_Log;
		Mutex m_PrintMutex;
		uint64 m_MaxLogLength;
		uint64 m_DefaultBufferSize;
		std::ofstream m_OutputFile;

	public:
		Console(uint64 maxLogLength, uint64 defaultBufferSize = 1024ull);

		void SetOutputFile(const String& filePath);

		void Success(const char* fmt, ...);
		void Info(const char* fmt, ...);
		void Warning(const char* fmt, ...);
		void Error(const char* fmt, ...);
		void FatalError(const char* fmt, ...);
		void Assert(bool value, const char* fmt, ...);

		void SuccessWithSize(uint64 bufferSize, const char* fmt, ...);
		void InfoWithSize(uint64 bufferSize, const char* fmt, ...);
		void WarningWithSize(uint64 bufferSize, const char* fmt, ...);
		void ErrorWithSize(uint64 bufferSize, const char* fmt, ...);
		void FatalErrorWithSize(uint64 bufferSize, const char* fmt, ...);
		void AssertWithSize(uint64 bufferSize, bool value, const char* fmt, ...);

	};
}