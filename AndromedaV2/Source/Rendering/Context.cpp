#include "Context.h"

namespace Andromeda {
	namespace Rendering {
		Context::Context()
			: m_Windows(), m_Renderers(), m_Input(), m_IsInitialized(false)
		{
			m_Input.SetShouldCaptureKeyboardInput(true);
			m_Input.SetShouldCaptureMouseInput(true);
		}

		Context::~Context()
		{
			if (m_IsInitialized)
			{
				Deinitialize();
			}

			for (uint64 i = 0; i < m_Windows.size(); ++i)
			{
				delete m_Windows[i];
			}

			for (uint64 i = 0; i < m_Renderers.size(); ++i)
			{
				delete m_Renderers[i];
			}
		}

		void Context::Initialize()
		{
			Global::GetConsoleInstance().Warning("Initializing Context");

			if (m_IsInitialized)
			{
				Global::GetConsoleInstance().FatalError("Failed context initialization, context is already initialized!");
			}
			m_IsInitialized = true;
		}

		void Context::Deinitialize()
		{
			Global::GetConsoleInstance().Warning("Deinitializing Context");

			if (!m_IsInitialized)
			{
				Global::GetConsoleInstance().FatalError("Failed context deinitialization, context is already deinitialized!");
			}
			m_IsInitialized = false;
		}

		void Context::Update(Duration deltaTime)
		{
			for (uint64 i = 0; i < m_Windows.size(); ++i)
			{
				m_Windows[i]->Update(deltaTime);
			}
			for (uint64 i = 0; i < m_Renderers.size(); ++i)
			{
				m_Renderers[i]->Update(deltaTime);
			}
		}

		Array<Window*>& Context::GetWindows()
		{
			return m_Windows;
		}

		Array<Renderer*>& Context::GetRenderers()
		{
			return m_Renderers;
		}

		void Context::AddWindow(Window* window)
		{
			if (!window->IsInitialized())
			{
				if (m_Windows.size() > 0ull)
				{
					window->Initialize(m_Windows[0ull]);
				}
				else
				{
					window->Initialize();
				}
			}

			m_Windows.push_back(window);
		}

		void Context::PrepareFrame()
		{
			m_Input.Prepare();
		}

		void Context::EndFrame()
		{
			m_Input.Flush();
		}

		void Context::RemoveWindow(Window* window, bool shouldDelete)
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

		void Context::RemoveWindow(uint64 windowIndex, bool shouldDelete)
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

		bool Context::IsInitialized() const
		{
			return m_IsInitialized;
		}
	}
}