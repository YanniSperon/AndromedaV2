#include "Global.h"
#include "Utility/Console.h"
#include "Utility/Input.h"
#include "Utility/Types.h"
#include "Utility/Random.h"

#include "glew.h"
#include "glfw3.h"

using namespace Andromeda;

extern "C"
{
	__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

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

static double mouseSensitivity = 0.5;

static int windowWidth = 1920;
static int windowHeight = 1080;

int main() {
	Global::Initialize();
	//////////////////////////////////////////////////////////////////////////////////////////////
	Global::GetConsoleInstance().Assert(glfwInit(), "Failed GLFW Initialization!");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	//////////////////////////////////////////////////////////////////////////////////////////////
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "OpenGL", NULL, NULL);
	Input* input = new Input();
	input->SetShouldCaptureKeyboardInput(true);
	input->SetShouldCaptureMouseInput(true);
	Global::GetConsoleInstance().Assert(window, "Failed Window Creation!");
	glfwMakeContextCurrent(window);
	glfwSetWindowUserPointer(window, input);
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
	if (glfwRawMouseMotionSupported()) {
		glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, 1);
	}
	glfwSwapInterval(0);
	glDebugMessageCallback(GLDebugMessageCallback, 0);
	glfwSetErrorCallback([](int error, const char* description)
		{
			Global::GetConsoleInstance().Error("GLFW Error (%i): \"%s\"", error, description);
		});
	//////////////////////////////////////////////////////////////////////////////////////////////
	glfwSetCursorPosCallback(window, [](GLFWwindow* glfwWindow, double xPos, double yPos)
		{
			Input* input = (Input*)glfwGetWindowUserPointer(glfwWindow);

			input->MoveMouseTo(xPos, yPos);

		});
	glfwSetMouseButtonCallback(window, [](GLFWwindow* glfwWindow, int button, int action, int mods)
		{
			Input* input = (Input*)glfwGetWindowUserPointer(glfwWindow);

			switch (action)
			{
			case GLFW_PRESS:
			{
				input->UpdateMouseButton(button, 1);
				break;
			}
			case GLFW_RELEASE:
			{
				input->UpdateMouseButton(button, 3);
				break;
			}
			}
		});
	glfwSetKeyCallback(window, [](GLFWwindow* glfwWindow, int key, int scancode, int action, int mods)
		{
			Input* input = (Input*)glfwGetWindowUserPointer(glfwWindow);

			switch (action)
			{
			case GLFW_PRESS:
			{
				input->UpdateKeyboardKey(key, AD_KEY_STATE_PRESSED);
				break;
			}
			case GLFW_RELEASE:
			{
				input->UpdateKeyboardKey(key, AD_KEY_STATE_RELEASED);
				break;
			}
			}
		});
	glfwSetWindowSizeCallback(window, [](GLFWwindow* glfwWindow, int width, int height)
		{
			Input* input = (Input*)glfwGetWindowUserPointer(glfwWindow);

			windowWidth = width;
			windowHeight = height;
		});
	glfwSetScrollCallback(window, [](GLFWwindow* glfwWindow, double xOffset, double yOffset)
		{
			Input* input = (Input*)glfwGetWindowUserPointer(glfwWindow);

			input->UpdateAddScrollPosition(xOffset, yOffset);
		});
	glfwSetCursorEnterCallback(window, [](GLFWwindow* glfwWindow, int entered)
		{
			Input* input = (Input*)glfwGetWindowUserPointer(glfwWindow);

			input->SetMouseWasBlocked(true);
		});
	//////////////////////////////////////////////////////////////////////////////////////////////
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//////////////////////////////////////////////////////////////////////////////////////////////
	GLfloat value, max_anisotropy = 8.0f; /* don't exceed this value...*/
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &value);
	Global::GetConsoleInstance().Warning("Anisotropy value: %f", value);
	//////////////////////////////////////////////////////////////////////////////////////////////



	double timeConstant = 1.0;
	auto lastTime = std::chrono::high_resolution_clock::now();
	auto currentTime = lastTime;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	while (!glfwWindowShouldClose(window)) {
		currentTime = std::chrono::high_resolution_clock::now();
		auto deltaTimeNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - lastTime);
		lastTime = currentTime;
		double deltaTimeWithoutTimeFactor = deltaTimeNanoseconds.count() / 1000000000.0;
		double deltaTime = deltaTimeWithoutTimeFactor * timeConstant;



		glfwPollEvents();
		input->Prepare();




		if (input->GetKeyboardKeyPressed(AD_KEY_LEFT_ALT)) {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			input->SetShouldCaptureMouseInput(true);
			input->SetMouseWasBlocked(true);
		}
		if (input->GetKeyboardKeyPressed(AD_KEY_RIGHT_ALT)) {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			input->SetShouldCaptureMouseInput(false);
		}
		//if (input->GetMousePositionX() != input->GetOldMousePositionX() || input->GetMousePositionY() != input->GetOldMousePositionY()) {
		//	camera.LookAtMouse(mouseSensitivity, input->GetMousePositionX(), input->GetMousePositionY(), input->GetOldMousePositionX(), input->GetOldMousePositionY());
		//}



		glfwSwapBuffers(window);

		input->Flush();
		Global::Update();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	Global::Cleanup();
}