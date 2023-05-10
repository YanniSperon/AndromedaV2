#include "GLFWWindow.h"
#include "OpenGLContext.h"
#include "glew.h"
#include "glfw3.h"

namespace Andromeda {
	namespace Rendering {
		namespace Platform {
			static void GLAPIENTRY GLDebugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
			{
				switch (severity)
				{
				case GL_DEBUG_SEVERITY_HIGH:
					Global::GetConsoleInstance().FatalError("GL CALLBACK:%s type = 0x%x, severity = 0x%x, message = %s\n", (type == GL_DEBUG_TYPE_ERROR ? " ** GL ERROR **" : ""), type, severity, message);
					break;
				case GL_DEBUG_SEVERITY_MEDIUM:
					Global::GetConsoleInstance().Error("GL CALLBACK:%s type = 0x%x, severity = 0x%x, message = %s\n", (type == GL_DEBUG_TYPE_ERROR ? " ** GL ERROR **" : ""), type, severity, message);
					break;
				case GL_DEBUG_SEVERITY_LOW:
					Global::GetConsoleInstance().Warning("GL CALLBACK:%s type = 0x%x, severity = 0x%x, message = %s\n", (type == GL_DEBUG_TYPE_ERROR ? " ** GL ERROR **" : ""), type, severity, message);
					break;
#ifdef AD_VERBOSE
				case GL_DEBUG_SEVERITY_NOTIFICATION:
					Global::GetConsoleInstance().Info("GL NOTIFICATION:%s type = 0x%x, severity = 0x%x, message = %s\n", (type == GL_DEBUG_TYPE_ERROR ? " ** GL ERROR **" : ""), type, severity, message);
					break;
#endif
				default:
					break;
				}
			}

			GLFWWindow::GLFWWindow(uint32 width, uint32 height, const String& windowTitle)
				: m_WindowHandle(nullptr), Window(width, height, windowTitle)
			{
			}

			GLFWWindow::~GLFWWindow()
			{
				if (m_IsInitialized)
				{
					Deinitialize();
				}
			}

			void GLFWWindow::InternalInitialize(GLFWwindow* parentHandle)
			{
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
				glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
				//////////////////////////////////////////////////////////////////////////////////////////////
				// monitor = glfwGetPrimaryMonitor()
				m_WindowHandle = glfwCreateWindow(m_Width, m_Height, m_WindowTitle.c_str(), NULL, parentHandle);
				Global::GetConsoleInstance().Assert(m_WindowHandle, "Failed Window Creation!");
				glfwMakeContextCurrent(m_WindowHandle);
				//////////////////////////////////////////////////////////////////////////////////////////////
				GLenum err = glewInit();
				Global::GetConsoleInstance().Assert(err == GLEW_OK, "Failed GLEW Initialization - %s", reinterpret_cast<char const*>(glewGetErrorString(err)));
				//////////////////////////////////////////////////////////////////////////////////////////////
				glEnable(GL_DEBUG_OUTPUT);
				glEnable(GL_DEPTH_TEST);
				glDepthFunc(GL_LEQUAL);
				glEnable(GL_CULL_FACE);
				glEnable(GL_BLEND);
				glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glCullFace(GL_CCW);
				//////////////////////////////////////////////////////////////////////////////////////////////
				if (glfwRawMouseMotionSupported())
				{
					glfwSetInputMode(m_WindowHandle, GLFW_RAW_MOUSE_MOTION, 1);
				}
				glfwSwapInterval(0);
				glDebugMessageCallback(GLDebugMessageCallback, 0);
				glfwSetErrorCallback([](int error, const char* description)
					{
						Global::GetConsoleInstance().Error("GLFW Error (%i): \"%s\"", error, description);
					});
				//////////////////////////////////////////////////////////////////////////////////////////////
				glfwSetCursorPosCallback(m_WindowHandle, [](GLFWwindow* glfwWindow, double xPos, double yPos)
					{
						Context* ctx = static_cast<Context*>(glfwGetWindowUserPointer(glfwWindow));

						ctx->m_Input.MoveMouseTo(xPos, yPos);

					});
				glfwSetMouseButtonCallback(m_WindowHandle, [](GLFWwindow* glfwWindow, int button, int action, int mods)
					{
						Context* ctx = static_cast<Context*>(glfwGetWindowUserPointer(glfwWindow));

						switch (action)
						{
						case GLFW_PRESS:
						{
							ctx->m_Input.UpdateMouseButton(button, 1);
							break;
						}
						case GLFW_RELEASE:
						{
							ctx->m_Input.UpdateMouseButton(button, 3);
							break;
						}
						}
					});
				glfwSetKeyCallback(m_WindowHandle, [](GLFWwindow* glfwWindow, int key, int scancode, int action, int mods)
					{
						Context* ctx = static_cast<Context*>(glfwGetWindowUserPointer(glfwWindow));

						switch (action)
						{
						case GLFW_PRESS:
						{
							ctx->m_Input.UpdateKeyboardKey(key, AD_KEY_STATE_PRESSED);
							break;
						}
						case GLFW_RELEASE:
						{
							ctx->m_Input.UpdateKeyboardKey(key, AD_KEY_STATE_RELEASED);
							break;
						}
						}
					});
				glfwSetWindowSizeCallback(m_WindowHandle, [](GLFWwindow* glfwWindow, int width, int height)
					{
						OpenGLContext* ctx = static_cast<OpenGLContext*>(glfwGetWindowUserPointer(glfwWindow));
						Window* window = ctx->GetWindowByGLFWHandle(glfwWindow);

						window->m_Width = width;
						window->m_Height = height;
					});
				glfwSetScrollCallback(m_WindowHandle, [](GLFWwindow* glfwWindow, double xOffset, double yOffset)
					{
						Context* ctx = static_cast<Context*>(glfwGetWindowUserPointer(glfwWindow));

						ctx->m_Input.UpdateAddScrollPosition(xOffset, yOffset);
					});
				glfwSetCursorEnterCallback(m_WindowHandle, [](GLFWwindow* glfwWindow, int entered)
					{
						Context* ctx = static_cast<Context*>(glfwGetWindowUserPointer(glfwWindow));

						ctx->m_Input.SetMouseWasBlocked(true);
					});
				//////////////////////////////////////////////////////////////////////////////////////////////
				glfwSetInputMode(m_WindowHandle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
				//////////////////////////////////////////////////////////////////////////////////////////////
				GLfloat value, max_anisotropy = 8.0f; /* don't exceed this value...*/
				glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &value);
				Global::GetConsoleInstance().Warning("Anisotropy value: %f", value);
				//////////////////////////////////////////////////////////////////////////////////////////////
			}

			void GLFWWindow::Initialize()
			{
				Global::GetConsoleInstance().Warning("Initializing GLFWWindow");
				Window::Initialize();
				InternalInitialize(nullptr);
			}

			void GLFWWindow::Initialize(Window* parent)
			{
				Global::GetConsoleInstance().Warning("Initializing GLFWWindow with parent");
				Window::Initialize(parent);
				InternalInitialize(static_cast<GLFWWindow*>(parent)->m_WindowHandle);
			}

			void GLFWWindow::Deinitialize()
			{
				Global::GetConsoleInstance().Warning("Deinitializing GLFWWindow");
				Window::Deinitialize();
				glfwDestroyWindow(m_WindowHandle);
			}

			void GLFWWindow::Update(Duration deltaTime)
			{
				Window::Update(deltaTime);

				OpenGLContext* ctx = static_cast<OpenGLContext*>(glfwGetWindowUserPointer(m_WindowHandle));

				// TODO MOVE THIS INTO A SEPERATE FILE AND NEW WINDOWS SHOULD INHERIT FROM GLFWWINDOW. MAYBE INSTEAD NEW WINDOWS INHERIT FROM A CUSTOMWINDOW CLASS WHICH
				// HAS A MEMBER WHICH IS EITHER GLFWWINDOW OR WHATEVER PLATFORM WINDOW YOU ARE USING.
				if (ctx->m_Input.GetKeyboardKeyPressed(AD_KEY_LEFT_ALT)) {
					SetInputMode(AD_CURSOR, AD_CURSOR_DISABLED);
					ctx->m_Input.SetShouldCaptureMouseInput(true);
					ctx->m_Input.SetMouseWasBlocked(true);
				}
				if (ctx->m_Input.GetKeyboardKeyPressed(AD_KEY_RIGHT_ALT)) {
					SetInputMode(AD_CURSOR, AD_CURSOR_NORMAL);
					ctx->m_Input.SetShouldCaptureMouseInput(false);
				}

				//if (input->GetMousePositionX() != input->GetOldMousePositionX() || input->GetMousePositionY() != input->GetOldMousePositionY()) {
				//	camera.LookAtMouse(mouseSensitivity, input->GetMousePositionX(), input->GetMousePositionY(), input->GetOldMousePositionX(), input->GetOldMousePositionY());
				//}
			}

			void GLFWWindow::Render(Array<Renderer*>& renderers)
			{
				// TODO SAME AS FUNCTION ABOVE
				glfwMakeContextCurrent(m_WindowHandle);
				glClearColor(static_cast<float>(m_ClearColor.r), static_cast<float>(m_ClearColor.g), static_cast<float>(m_ClearColor.b), static_cast<float>(m_ClearColor.a));
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			}

			void GLFWWindow::SetInputMode(int32 mode, int32 value)
			{
				glfwSetInputMode(m_WindowHandle, mode, value);
			}

			bool GLFWWindow::ShouldWindowClose()
			{
				return glfwWindowShouldClose(m_WindowHandle);
			}
		}
	}
}