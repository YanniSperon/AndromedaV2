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
			Math::DVector4D m_ClearColor;

		public:
			Window(uint32 width, uint32 height, const String& windowTitle);
			virtual ~Window();

			virtual void Initialize(); // Make sure to call if overwriting function
			virtual void Initialize(Window* parentWindow); // Make sure to call if overwriting function
			virtual void Deinitialize(); // Make sure to call if overwriting function

			virtual void Update(Duration deltaTime); // Make sure to call if overwriting function
			virtual void Render(Array<Renderer*>& renderers) = 0;

			virtual void SetInputMode(int32 mode, int32 value) = 0;

			virtual bool ShouldWindowClose() = 0;

			void SetClearColor(Math::DVector4D& clearColor);
			const Math::DVector4D& GetClearColor();

			bool IsInitialized() const;

			friend class Platform::GLFWWindow;
		};
	}
}