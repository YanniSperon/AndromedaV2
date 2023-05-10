#include "Context.h"

namespace Andromeda {
	namespace Rendering {
		Context::Context()
			: m_Windows(), m_Renderers(), m_ClearColor(0.0f, 0.0f, 0.0f, 0.0f), m_Input(), m_IsInitialized(false)
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
			if (m_IsInitialized)
			{
				Global::GetConsoleInstance().FatalError("Failed context initialization, context is already initialized!");
			}
			m_IsInitialized = true;
		}

		void Context::Deinitialize()
		{
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

		void Context::PrepareFrame()
		{
			m_Input.Prepare();
		}

		void Context::EndFrame()
		{
			m_Input.Flush();
		}
		void Context::SetClearColor(Math::FVector4D& clearColor)
		{
			m_ClearColor = clearColor;
		}
		const Math::FVector4D& Context::GetClearColor()
		{
			return m_ClearColor;
		}
	}
}