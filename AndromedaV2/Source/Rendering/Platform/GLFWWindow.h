#pragma once

#include "Rendering/Window.h"
#include "glfw3.h"

namespace Andromeda {
	namespace Rendering {
		namespace Platform {
			class OpenGLContext;

			class GLFWWindow : public Window {
			private:
				GLFWwindow* m_WindowHandle;

				void InternalInitialize(GLFWwindow* parentHandle);
			public:
				GLFWWindow(uint32 width, uint32 height, const String& windowTitle);
				virtual ~GLFWWindow() override;

				virtual void Initialize() override;
				virtual void Initialize(Window* parent) override;
				virtual void Deinitialize() override;

				virtual void Update(Duration deltaTime) override;
				virtual void Render(Array<Renderer*>& renderers) override;

				virtual void SetInputMode(int32 mode, int32 value) override;

				virtual bool ShouldWindowClose() override;

				friend class OpenGLContext;
			};
		}
	}
}