#include "OpenGLContext.h"
#include "Global.h"
#include "GLFWWindow.h"

#include "glew.h"
#include "glfw3.h"

namespace Andromeda {
	namespace Rendering {
		namespace Platform {
			OpenGLContext::OpenGLContext()
				: Context()
			{
			}

			OpenGLContext::~OpenGLContext()
			{
				if (m_IsInitialized)
				{
					Deinitialize();
				}
			}

			void OpenGLContext::Initialize()
			{
				Global::GetConsoleInstance().Warning("Initializing OpenGLContext");
				Context::Initialize();
			}

			void OpenGLContext::Deinitialize()
			{
				Global::GetConsoleInstance().Warning("Deinitializing OpenGLContext");
				Context::Deinitialize();
			}

			void OpenGLContext::AddWindow(Window* window)
			{
				Context::AddWindow(window);

				GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(window);
				glfwSetWindowUserPointer(glfwWindow->m_WindowHandle, this);
			}

			void OpenGLContext::PrepareFrame()
			{
				Context::PrepareFrame();

				glfwPollEvents();
			}

			void OpenGLContext::EndFrame()
			{
				Context::EndFrame();

				for (uint64 i = 0; i < m_Windows.size(); ++i)
				{
					GLFWWindow* window = static_cast<GLFWWindow*>(m_Windows[i]);
					glfwSwapBuffers(window->m_WindowHandle);
				}
			}

			Window* OpenGLContext::GetWindowByGLFWHandle(GLFWwindow* handle)
			{
				for (uint64 i = 0; i < m_Windows.size(); ++i)
				{
					GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(m_Windows[i]);
					if (glfwWindow->m_WindowHandle == handle)
					{
						return m_Windows[i];
					}
				}
				return nullptr;
			}
		}
	}
}