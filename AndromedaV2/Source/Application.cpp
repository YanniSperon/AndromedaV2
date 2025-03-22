#include "Global.h"
#include "Game/ProgramInstance.h"
#include "Utility/Console.h"
#include "Utility/Input.h"
#include "Utility/Types.h"

#include "Rendering/Platform/GLFWWindow.h"
#include "Rendering/Platform/OpenGLContext.h"

using namespace Andromeda;

extern "C"
{
	__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

static double mouseSensitivity = 0.5;

int main() {
	Global::Initialize();
	Global::SetRenderBackendType(Global::RenderBackendType::OpenGL);





	Rendering::Window* wndw = new Rendering::Platform::GLFWWindow(1920, 1080, String("New Title OpenGL"));
	wndw->SetClearColor(Math::DVector4D(1.0, 0.0, 0.0, 1.0));

	Rendering::Window* wndw2 = new Rendering::Platform::GLFWWindow(294, 150, String("Some pop-up"));
	wndw2->SetClearColor(Math::DVector4D(1.0, 0.0, 1.0, 1.0));

	Rendering::Context* ctx = new Rendering::Platform::OpenGLContext();
	ctx->AddWindow(wndw);
	ctx->AddWindow(wndw2);

	Rendering::Window* wndw3 = new Rendering::Platform::GLFWWindow(1280, 720, String("2222"));
	wndw3->SetClearColor(Math::DVector4D(0.0, 1.0, 0.0, 1.0));

	Rendering::Context* ctx2 = new Rendering::Platform::OpenGLContext();
	ctx2->AddWindow(wndw3);

	Game::ProgramInstance* inst = new Game::ProgramInstance();
	inst->AddContext(ctx);
	inst->AddContext(ctx2);

	Global::AddProgramInstance(inst);





	TimePoint lastTime = HighResolutionClock::now();
	TimePoint currentTime = lastTime;
	std::chrono::nanoseconds deltaTimeNanoseconds = std::chrono::nanoseconds();
	Duration deltaTimeWithoutTimeFactor = Duration();
	Duration deltaTime = Duration();
	uint64 currentProgramInstance = 0ull;
	uint64 currentContextIndex = 0ull;
	uint64 currentWindowIndex = 0ull;
	Game::ProgramInstance* currentInstance = nullptr;

	while (Global::GetProgramInstancesSize() > 0ull)
	{
		Global::SetCurrentProgramInstance(currentProgramInstance);
		currentInstance = Global::GetCurrentProgramInstance();
		if (currentInstance->GetContexts().size() > 0ull)
		{
			currentTime = HighResolutionClock::now();
			deltaTimeNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - lastTime);
			lastTime = currentTime;
			deltaTimeWithoutTimeFactor = RichTimeToDuration(deltaTimeNanoseconds);
			deltaTime = deltaTimeWithoutTimeFactor * currentInstance->GetTimeConstant();
	
			Global::UpdateCurrentProgramInstance(deltaTime);
	
			while (currentContextIndex < currentInstance->GetContexts().size()) {
	
				if (currentInstance->GetContexts()[currentContextIndex]->GetWindows().size() > 0ull)
				{
					currentInstance->GetContexts()[currentContextIndex]->PrepareFrame();
					while (currentWindowIndex < currentInstance->GetContexts()[currentContextIndex]->GetWindows().size())
					{
						if (!currentInstance->GetContexts()[currentContextIndex]->GetWindows()[currentWindowIndex]->ShouldWindowClose())
						{
							currentInstance->GetContexts()[currentContextIndex]->GetWindows()[currentWindowIndex]->Render(currentInstance->GetContexts()[currentContextIndex]->GetRenderers());
							++currentWindowIndex;
						}
						else
						{
							currentInstance->GetContexts()[currentContextIndex]->RemoveWindow(currentWindowIndex);
						}
					}
					currentInstance->GetContexts()[currentContextIndex]->EndFrame();
					currentWindowIndex = 0ull;
					++currentContextIndex;
				}
				else
				{
					currentInstance->RemoveContext(currentContextIndex);
				}
			}
			currentContextIndex = 0ull;
			++currentProgramInstance;
			if (currentProgramInstance == Global::GetProgramInstancesSize())
			{
				currentProgramInstance = 0ull;
			}
		}
		else
		{
			Global::RemoveProgramInstance(currentProgramInstance);
		}
	}

	Global::Deinitialize();
}