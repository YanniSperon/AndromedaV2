#include "Global.h"
#include "Utility/Console.h"

static std::vector<std::string> g_ConsoleLog;
static std::chrono::steady_clock::time_point g_SystemStartTime;

void Global::Initialize()
{
	g_ConsoleLog = std::vector<std::string>();
	g_SystemStartTime = std::chrono::high_resolution_clock::now();
}

std::chrono::steady_clock::time_point& Global::GetStartTime()
{
	return g_SystemStartTime;
}

void Global::Update()
{
	//Call singleton instance update
}

void Global::Cleanup()
{
	//Call singleton instance cleanup/deletion
}
