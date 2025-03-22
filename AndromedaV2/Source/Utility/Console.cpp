#include "Console.h"
#include "Global.h"

#include <cstdio>
#include <cstdarg>
#include <chrono>

#include "MathDefinitions.h"
#include "TimeDefinitions.h"

#if defined(AD_EDITOR) && defined(AD_WIN64)
#include <Windows.h>
#endif

namespace Andromeda {

	Console::Console(uint64 maxLogLength, uint64 defaultBufferSize)
		: m_Log(), m_PrintMutex(), m_MaxLogLength(maxLogLength), m_DefaultBufferSize(defaultBufferSize), m_OutputFile()
	{
	}

	void Console::SetOutputFile(const String& filePath)
	{
		if (filePath != "") {
			if (m_OutputFile.is_open()) {
				m_OutputFile.close();
			}
			m_OutputFile.open(filePath);
		}
		else {
			m_OutputFile.close();
		}
	}

	void Console::Success(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		SuccessWithSize(m_DefaultBufferSize, fmt, args);
		va_end(args);
	}

	void Console::Info(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		InfoWithSize(m_DefaultBufferSize, fmt, args);
		va_end(args);
	}

	void Console::Warning(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		WarningWithSize(m_DefaultBufferSize, fmt, args);
		va_end(args);
	}

	void Console::Error(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		ErrorWithSize(m_DefaultBufferSize, fmt, args);
		va_end(args);
	}

	void Console::FatalError(const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		FatalErrorWithSize(m_DefaultBufferSize, fmt, args);
		va_end(args);
	}

	void Console::Assert(bool value, const char* fmt, ...)
	{
#ifdef AD_DEBUG
		if (!value) {
			va_list args;
			va_start(args, fmt);
			FatalErrorWithSize(m_DefaultBufferSize, fmt, args);
			va_end(args);
		}
#endif
	}

	void Console::SuccessWithSize(uint64 bufferSize, const char* fmt, ...)
	{
#ifdef AD_DEBUG
		va_list args;
		va_start(args, fmt);
		auto currentTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - Global::GetStartTime());
		auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
		auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration - hours);
		auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration - hours - minutes);
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration - hours - minutes - seconds);
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration - hours - minutes - seconds - milliseconds);
		m_PrintMutex.lock();
#if defined(AD_EDITOR) && defined(AD_WIN64)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
#endif
		char* timestamp = new char[256];
		snprintf(timestamp, 256, "%02ld:%02ld:%02lld.%03lld%03lld --    SUCCESS:    ", hours.count(), minutes.count(), seconds.count(), milliseconds.count(), microseconds.count());
		char* message = new char[bufferSize];
		vsnprintf(message, bufferSize, fmt, args);
		std::string returnValue = std::string(timestamp) + std::string(message);
		printf("%s\n", returnValue.c_str());
		m_Log.push_back(returnValue);
		if (m_Log.size() > m_MaxLogLength) {
			m_Log.pop_front();
		}
		m_PrintMutex.unlock();
		va_end(args);
		delete[] timestamp;
		delete[] message;
		if (m_OutputFile.is_open()) {
			m_OutputFile << returnValue;
			m_OutputFile.flush();
		}
#endif
	}

	void Console::InfoWithSize(uint64 bufferSize, const char* fmt, ...)
	{
#ifdef AD_DEBUG
		va_list args;
		va_start(args, fmt);
		TimePoint currentTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - Global::GetStartTime());
		auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
		auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration - hours);
		auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration - hours - minutes);
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration - hours - minutes - seconds);
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration - hours - minutes - seconds - milliseconds);
		m_PrintMutex.lock();
#if defined(AD_EDITOR) && defined(AD_WIN64)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
#endif
		char* timestamp = new char[256];
		snprintf(timestamp, 256, "%02ld:%02ld:%02lld.%03lld%03lld --      INFO:     ", hours.count(), minutes.count(), seconds.count(), milliseconds.count(), microseconds.count());
		char* message = new char[bufferSize];
		vsnprintf(message, bufferSize, fmt, args);
		std::string returnValue = std::string(timestamp) + std::string(message);
		printf("%s\n", returnValue.c_str());
		m_Log.push_back(returnValue);
		if (m_Log.size() > m_MaxLogLength) {
			m_Log.pop_front();
		}
		m_PrintMutex.unlock();
		va_end(args);
		delete[] timestamp;
		delete[] message;
		if (m_OutputFile.is_open()) {
			m_OutputFile << returnValue;
			m_OutputFile.flush();
		}
#endif
	}

	void Console::WarningWithSize(uint64 bufferSize, const char* fmt, ...)
	{
#ifdef AD_DEBUG
		va_list args;
		va_start(args, fmt);
		auto currentTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - Global::GetStartTime());
		auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
		auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration - hours);
		auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration - hours - minutes);
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration - hours - minutes - seconds);
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration - hours - minutes - seconds - milliseconds);
		m_PrintMutex.lock();
#if defined(AD_EDITOR) && defined(AD_WIN64)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
#endif
		char* timestamp = new char[256];
		snprintf(timestamp, 256, "%02ld:%02ld:%02lld.%03lld%03lld --    WARNING:    ", hours.count(), minutes.count(), seconds.count(), milliseconds.count(), microseconds.count());
		char* message = new char[bufferSize];
		vsnprintf(message, bufferSize, fmt, args);
		std::string returnValue = std::string(timestamp) + std::string(message);
		printf("%s\n", returnValue.c_str());
		m_Log.push_back(returnValue);
		if (m_Log.size() > m_MaxLogLength) {
			m_Log.pop_front();
		}
		m_PrintMutex.unlock();
		va_end(args);
		delete[] timestamp;
		delete[] message;
		if (m_OutputFile.is_open()) {
			m_OutputFile << returnValue;
			m_OutputFile.flush();
		}
#endif
	}

	void Console::ErrorWithSize(uint64 bufferSize, const char* fmt, ...)
	{
#ifdef AD_DEBUG
		va_list args;
		va_start(args, fmt);
		auto currentTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - Global::GetStartTime());
		auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
		auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration - hours);
		auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration - hours - minutes);
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration - hours - minutes - seconds);
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration - hours - minutes - seconds - milliseconds);
		m_PrintMutex.lock();
#if defined(AD_EDITOR) && defined(AD_WIN64)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
#endif
		char* timestamp = new char[256];
		snprintf(timestamp, 256, "%02ld:%02ld:%02lld.%03lld%03lld --     ERROR:     ", hours.count(), minutes.count(), seconds.count(), milliseconds.count(), microseconds.count());
		char* message = new char[bufferSize];
		vsnprintf(message, bufferSize, fmt, args);
		std::string returnValue = std::string(timestamp) + std::string(message);
		printf("%s\n", returnValue.c_str());
		m_Log.push_back(returnValue);
		if (m_Log.size() > m_MaxLogLength) {
			m_Log.pop_front();
		}
		m_PrintMutex.unlock();
		va_end(args);
		delete[] timestamp;
		delete[] message;
		if (m_OutputFile.is_open()) {
			m_OutputFile << returnValue;
			m_OutputFile.flush();
		}
#endif
	}

	void Console::FatalErrorWithSize(uint64 bufferSize, const char* fmt, ...)
	{
#ifdef AD_DEBUG
		va_list args;
		va_start(args, fmt);
		auto currentTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - Global::GetStartTime());
		auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
		auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration - hours);
		auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration - hours - minutes);
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration - hours - minutes - seconds);
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration - hours - minutes - seconds - milliseconds);
		m_PrintMutex.lock();
#if defined(AD_EDITOR) && defined(AD_WIN64)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
#endif
		char* timestamp = new char[256];
		snprintf(timestamp, 256, "%02ld:%02ld:%02lld.%03lld%03lld --  FATAL ERROR:  ", hours.count(), minutes.count(), seconds.count(), milliseconds.count(), microseconds.count());
		char* message = new char[bufferSize];
		vsnprintf(message, bufferSize, fmt, args);
		std::string returnValue = std::string(timestamp) + std::string(message);
		printf("%s\n", returnValue.c_str());
		m_Log.push_back(returnValue);
		if (m_Log.size() > m_MaxLogLength) {
			m_Log.pop_front();
		}
		m_PrintMutex.unlock();
		va_end(args);
		delete[] timestamp;
		delete[] message;
		if (m_OutputFile.is_open()) {
			m_OutputFile << returnValue;
			m_OutputFile.flush();
		}
#endif
	}

	void Console::AssertWithSize(uint64 bufferSize, bool value, const char* fmt, ...)
	{
#ifdef AD_DEBUG
		if (!value) {
			va_list args;
			va_start(args, fmt);
			FatalErrorWithSize(bufferSize, fmt, args);
			va_end(args);
		}
#endif
	}
}