#pragma once

#include "Utility/StandardCollectionsDefinitions.h"
#include "Utility/TimeDefinitions.h"
#include "Utility/Console.h"
#include "Utility/UUID.h"
#include "Utility/Random.h"

namespace Andromeda {

	namespace Game {
		class ProgramInstance;
	}

	class Global {
	public:
		enum class RenderBackendType : uint8
		{
			None = 0u,
			OpenGL = 1u,
			DirectX11 = 4u,
			DirectX12 = 8u,
			Vulkan = 16u,
			Metal = 32u,
		};

	private:
		static Array<Game::ProgramInstance*> s_ProgramInstances;
		static uint64 s_ProgramInstancesIndex;
		static Console* s_GlobalConsole;
		static TimePoint s_SystemStartTime;
		static RenderBackendType s_RenderBackendType;

	public:
		static void Initialize();
		static void Deinitialize();

		static Console& GetConsoleInstance();
		static const TimePoint& GetStartTime();

		static void AddProgramInstance(Game::ProgramInstance* instance);
		static void RemoveProgramInstance(uint64 index, bool shouldDelete = true);
		static void SetCurrentProgramInstance(uint64 index);
		static void UpdateCurrentProgramInstance(Duration deltaTime);

		static uint64 GetProgramInstancesSize();
		static Game::ProgramInstance* GetCurrentProgramInstance();

		static const RenderBackendType& GetRenderBackendType();
		static void SetRenderBackendType(RenderBackendType renderBackendType); // This can only be called before any windows or contexts have been created

	};
}