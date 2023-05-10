#pragma once

#include "Utility/Types.h"
#include "Renderer.h"

namespace Andromeda {
	namespace Rendering {
		namespace Platform {
			class GLFWWindow;
		}
		class Window {
		protected:
			uint32 m_Width;
			uint32 m_Height;
			String m_WindowTitle;
			bool m_IsInitialized;

		public:
			Window(uint32 width, uint32 height, const String& windowTitle);
			virtual ~Window();

			// If overriding, make sure to call
			virtual void Initialize();
			// If overriding, make sure to call
			virtual void Deinitialize();

			virtual void Update(Duration deltaTime);
			virtual void Render(Array<Renderer*>& renderers) = 0;

			virtual void SetInputMode(int32 mode, int32 value) = 0;

			virtual bool ShouldWindowClose() = 0;

			friend class Platform::GLFWWindow;
		};
	}
}