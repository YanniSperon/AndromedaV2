#pragma once

#include "Utility/Input.h"
#include "Utility/Types.h"
#include "Renderer.h"
#include "Window.h"

struct GLFWwindow;

namespace Andromeda {
	namespace Rendering {
		class Context {
		protected:
			Array<Window*> m_Windows;
			Array<Renderer*> m_Renderers;
			bool m_IsInitialized;

		public:
			Input m_Input;

		public:
			Context();
			virtual ~Context();

			virtual void Initialize();
			virtual void Deinitialize();

			virtual void Update(Duration deltaTime);

			Array<Window*>& GetWindows();
			Array<Renderer*>& GetRenderers();

			virtual void AddWindow(Window* window) = 0;
			virtual void PrepareFrame();
			virtual void EndFrame();
			virtual void RemoveWindow(Window* window, bool shouldDelete = true) = 0;
			virtual void RemoveWindow(uint64 windowIndex, bool shouldDelete = true) = 0;

		};
	}
}