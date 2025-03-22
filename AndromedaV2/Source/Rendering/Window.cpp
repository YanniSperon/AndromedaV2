#include "Window.h"

namespace Andromeda {
	namespace Rendering {
		Window::Window(uint32 width, uint32 height, const String& windowTitle)
			: m_Width(width), m_Height(height), m_WindowTitle(windowTitle), m_IsInitialized(false), m_ClearColor(0.0, 0.0, 0.0, 0.0)
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
			Global::GetGlobalConsole().Warning("Initializing Window");
			if (m_IsInitialized)
			{
				Global::GetGlobalConsole().FatalError("Failed window initialization, window is already initialized!");
			}
			m_IsInitialized = true;
		}

		void Window::Initialize(Window* parentWindow)
		{
			Global::GetGlobalConsole().Warning("Initializing Window with parent");
			if (m_IsInitialized)
			{
				Global::GetGlobalConsole().FatalError("Failed window initialization, window is already initialized!");
			}
			m_IsInitialized = true;
		}

		void Window::Deinitialize()
		{
			Global::GetGlobalConsole().Warning("Deinitializing Window");

			if (!m_IsInitialized)
			{
				Global::GetGlobalConsole().FatalError("Failed window deinitialization, window is already deinitialized!");
			}
			m_IsInitialized = false;
		}

		void Window::Update(Duration deltaTime)
		{

		}

		void Window::SetClearColor(const Math::DVector4D& clearColor)
		{
			m_ClearColor = clearColor;
		}

		const Math::DVector4D& Window::GetClearColor()
		{
			return m_ClearColor;
		}

		bool Window::IsInitialized() const
		{
			return m_IsInitialized;
		}
	}
}