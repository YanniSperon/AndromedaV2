#pragma once

#include "Rendering/Context.h"
#include "glfw3.h"

namespace Andromeda {
	namespace Rendering {
		namespace Platform {
			class OpenGLContext : public Context {
			public:
				OpenGLContext();
				virtual ~OpenGLContext() override;

				virtual void Initialize() override;
				virtual void Deinitialize() override;

				virtual void AddWindow(Window* window) override;
				virtual void PrepareFrame() override;
				virtual void EndFrame() override;
				virtual void RemoveWindow(Window* window, bool shouldDelete = true) override;
				virtual void RemoveWindow(uint64 windowIndex, bool shouldDelete = true) override;

				Window* GetWindowByGLFWHandle(GLFWwindow* handle);
			};
		}
	}
}