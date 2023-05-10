#include "Global.h"
#include "Utility/Console.h"
#include "Game/ProgramInstance.h"

#include "glfw3.h"

namespace Andromeda {

	Array<Game::ProgramInstance*> Global::s_ProgramInstances = Array<Game::ProgramInstance*>();
	uint64 Global::s_ProgramInstancesIndex = 0ull;
	Console* Global::s_GlobalConsole = new Console(1024);
	TimePoint Global::s_SystemStartTime = std::chrono::high_resolution_clock::now();
	Global::RenderBackendType Global::s_RenderBackendType = Global::RenderBackendType::None;

	void Global::Initialize()
	{
		s_SystemStartTime = std::chrono::high_resolution_clock::now();
	}

	Console& Global::GetConsoleInstance()
	{
		return *s_GlobalConsole;
	}

	const TimePoint& Global::GetStartTime()
	{
		return s_SystemStartTime;
	}

	const Global::RenderBackendType& Global::GetRenderBackendType()
	{
		return s_RenderBackendType;
	}

	void Global::Deinitialize()
	{
		//Call singleton instance cleanup/deletion
		delete s_GlobalConsole;

		SetRenderBackendType(Global::RenderBackendType::None);
	}

	void Global::UpdateCurrentProgramInstance(Duration deltaTime)
	{
		GetCurrentProgramInstance()->Update(deltaTime);
	}

	void Global::AddProgramInstance(Game::ProgramInstance* instance)
	{
		s_ProgramInstances.push_back(instance);
	}

	void Global::RemoveProgramInstance(uint64 index, bool shouldDelete)
	{
		if (shouldDelete) {
			delete s_ProgramInstances[index];
		}
		s_ProgramInstances.erase(s_ProgramInstances.begin() + index);
		s_ProgramInstancesIndex = 0ull;
	}

	uint64 Global::GetProgramInstancesSize()
	{
		return s_ProgramInstances.size();
	}

	Game::ProgramInstance* Global::GetCurrentProgramInstance()
	{
		return s_ProgramInstances[s_ProgramInstancesIndex];
	}

	void Global::SetCurrentProgramInstance(uint64 index)
	{
		s_ProgramInstancesIndex = index;
	}

	void Global::SetRenderBackendType(Global::RenderBackendType renderBackendType)
	{
		if (s_RenderBackendType != renderBackendType)
		{
			switch (s_RenderBackendType)
			{
			case RenderBackendType::OpenGL:
				glfwTerminate();
				break;
			default:
				break;
			}

			switch (renderBackendType)
			{
			case RenderBackendType::OpenGL:
				Global::GetConsoleInstance().Assert(glfwInit(), "Failed GLFW Initialization!");
				break;
			default:
				break;
			}
		}
		s_RenderBackendType = renderBackendType;
	}

}