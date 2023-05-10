#include "Window.h"

namespace Andromeda {
	namespace Rendering {
		Window::Window(uint32 width, uint32 height, const String& windowTitle)
			: m_Width(width), m_Height(height), m_WindowTitle(windowTitle), m_IsInitialized(false)
		{
		}

		Window::~Window()
		{
			if (m_IsInitialized)
			{
				Deinitialize();
			}
		}

		void Window::Initialize()
		{
			if (m_IsInitialized)
			{
				Global::GetConsoleInstance().FatalError("Failed window initialization, window is already initialized!");
			}
			m_IsInitialized = true;
		}

		void Window::Deinitialize()
		{
			if (!m_IsInitialized)
			{
				Global::GetConsoleInstance().FatalError("Failed window deinitialization, window is already deinitialized!");
			}
			m_IsInitialized = false;
		}

		void Window::Update(Duration deltaTime)
		{

		}
	}
}