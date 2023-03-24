#include "Global.h"
#include "Utility/Console.h"

namespace Andromeda {

	static std::chrono::steady_clock::time_point S_SystemStartTime;
	static Console* S_GlobalConsole;

	void Global::Initialize()
	{
		S_SystemStartTime = std::chrono::high_resolution_clock::now();
		S_GlobalConsole = new Console(1024);
	}

	Console& Global::GetConsoleInstance()
	{
		return *S_GlobalConsole;
	}

	TimePoint& Global::GetStartTime()
	{
		return S_SystemStartTime;
	}

	void Global::Update()
	{
		//Call singleton instance update
	}

	void Global::Cleanup()
	{
		//Call singleton instance cleanup/deletion
		delete S_GlobalConsole;
	}
}