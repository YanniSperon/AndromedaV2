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

			virtual void Initialize(); // Make sure to call if overwriting function
			virtual void Deinitialize(); // Make sure to call if overwriting function

			virtual void Update(Duration deltaTime);

			Array<Window*>& GetWindows();
			Array<Renderer*>& GetRenderers();

			virtual void AddWindow(Window* window); // Make sure to call if overwriting function
			virtual void PrepareFrame();
			virtual void EndFrame();
			virtual void RemoveWindow(Window* window, bool shouldDelete = true);
			virtual void RemoveWindow(uint64 windowIndex, bool shouldDelete = true);

			bool IsInitialized() const;

		};
	}
}