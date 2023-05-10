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

	Rendering::Window* wndw = new Rendering::Platform::GLFWWindow(1920, 1080, std::string("New Title OpenGL"));
	wndw->Initialize();

	Rendering::Context* ctx = new Rendering::Platform::OpenGLContext();
	ctx->Initialize();
	ctx->SetClearColor(Math::FVector4D(1.0f, 0.0f, 0.0f, 0.0f));
	ctx->AddWindow(wndw);

	Rendering::Window* wndw2 = new Rendering::Platform::GLFWWindow(1280, 720, std::string("2222"));
	wndw2->Initialize();

	Rendering::Context* ctx2 = new Rendering::Platform::OpenGLContext();
	ctx2->Initialize();
	ctx2->SetClearColor(Math::FVector4D(0.0f, 1.0f, 0.0f, 0.0f));
	ctx2->AddWindow(wndw2);

	Game::ProgramInstance* inst = new Game::ProgramInstance();
	inst->AddContext(ctx);
	inst->AddContext(ctx2);

	Global::AddProgramInstance(inst);

	TimePoint lastTime = std::chrono::high_resolution_clock::now();
	TimePoint currentTime = lastTime;
	uint64 currentProgramInstance = 0ull;
	uint64 currentContextIndex = 0ull;
	uint64 currentWindowIndex = 0ull;

	while (Global::GetProgramInstancesSize() > 0ull)
	{
		Global::SetCurrentProgramInstance(currentProgramInstance);
		Game::ProgramInstance* currentInstance = Global::GetCurrentProgramInstance();
		if (currentInstance->GetContexts().size() > 0ull)
		{
			currentTime = std::chrono::high_resolution_clock::now();
			DurationNanoseconds deltaTimeNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - lastTime);
			lastTime = currentTime;
			Duration deltaTimeWithoutTimeFactor = deltaTimeNanoseconds.count() / 1000000000.0;
			Duration deltaTime = deltaTimeWithoutTimeFactor * currentInstance->GetTimeConstant();
	
			Global::UpdateCurrentProgramInstance(deltaTime);
	
			while (currentContextIndex < currentInstance->GetContexts().size()) {
	
				if (currentInstance->GetContexts()[currentContextIndex]->GetWindows().size() > 0ull)
				{
					currentInstance->GetContexts()[currentContextIndex]->PrepareFrame();
					while (currentWindowIndex < currentInstance->GetContexts()[currentContextIndex]->GetWindows().size())
					{
						if (!currentInstance->GetContexts()[currentContextIndex]->GetWindows()[currentWindowIndex]->ShouldWindowClose())
						{
							currentInstance->GetContexts()[currentContextIndex]->GetWindows()[currentContextIndex]->Render(currentInstance->GetContexts()[currentContextIndex]->GetRenderers());
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

	delete inst;

	Global::Deinitialize();
}