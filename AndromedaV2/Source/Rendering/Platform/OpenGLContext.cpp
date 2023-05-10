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
			}

			void OpenGLContext::Initialize()
			{
				Context::Initialize();

			}

			void OpenGLContext::Deinitialize()
			{
				Context::Deinitialize();

			}

			void OpenGLContext::AddWindow(Window* window)
			{
				GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(window);
				glfwSetWindowUserPointer(glfwWindow->m_WindowHandle, this);

				m_Windows.push_back(window);
			}

			void OpenGLContext::PrepareFrame()
			{
				Context::PrepareFrame();

				glfwPollEvents();

				glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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

			void OpenGLContext::RemoveWindow(Window* window, bool shouldDelete)
			{
				uint64 windowIndex = UINT64_MAX;
				for (uint64 i = 0; i < m_Windows.size(); ++i)
				{
					if (m_Windows[i] == window)
					{
						windowIndex = i;
						break;
					}
				}

				if (windowIndex != UINT64_MAX)
				{
					if (shouldDelete)
					{
						delete window;
					}

					m_Windows.erase(m_Windows.begin() + windowIndex);
				}
			}

			void OpenGLContext::RemoveWindow(uint64 windowIndex, bool shouldDelete)
			{
				if (windowIndex < m_Windows.size())
				{
					if (shouldDelete)
					{
						delete m_Windows[windowIndex];
					}
					m_Windows.erase(m_Windows.begin() + windowIndex);

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