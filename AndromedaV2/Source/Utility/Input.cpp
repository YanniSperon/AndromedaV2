#include "Input.h"

namespace Andromeda {
	Input::Input()
		: m_KeyboardKeyStates(512, 0), m_MouseButtonStates(16, 0), m_ShouldCaptureKeyboardInput(false), m_ShouldCaptureMouseInput(false), m_PendingMouseStateChanges(), m_PendingKeyboardStateChanges(), m_CurrentMouseXPos(0.0), m_CurrentMouseYPos(0.0), m_OldMouseXPos(0.0), m_OldMouseYPos(0.0), m_MouseWasBlocked(true), m_CurrentScrollXPos(0.0), m_CurrentScrollYPos(0.0), m_PendingScrollXInput(0.0), m_PendingScrollYInput(0.0)
	{
	}

	Input::~Input()
	{
	}

	InputState Input::GetKeyboardKeyState(uint16 key)
	{
		return static_cast<InputState>(m_KeyboardKeyStates[key]);
	}

	bool Input::GetKeyboardKeyIdle(uint16 key)
	{
		return m_KeyboardKeyStates[key] == 0;
	}

	bool Input::GetKeyboardKeyPressed(uint16 key)
	{
		return m_KeyboardKeyStates[key] == 1;
	}

	bool Input::GetKeyboardKeyHeld(uint16 key)
	{
		return m_KeyboardKeyStates[key] == 2;
	}

	bool Input::GetKeyboardKeyReleased(uint16 key)
	{
		return m_KeyboardKeyStates[key] == 3;
	}

	void Input::UpdateKeyboardKey(uint16 key, uint16 event)
	{
		if (m_ShouldCaptureKeyboardInput) {
			m_PendingKeyboardStateChanges.push_back(InputStateChange(key, event));
		}
	}

	InputState Input::GetMouseButtonState(uint16 button)
	{
		return static_cast<InputState>(m_MouseButtonStates[button]);
	}

	bool Input::GetMouseButtonIdle(uint16 button)
	{
		return m_MouseButtonStates[button] == 0;
	}

	bool Input::GetMouseButtonPressed(uint16 button)
	{
		return m_MouseButtonStates[button] == 1;
	}

	bool Input::GetMouseButtonHeld(uint16 button)
	{
		return m_MouseButtonStates[button] == 2;
	}

	bool Input::GetMouseButtonReleased(uint16 button)
	{
		return m_MouseButtonStates[button] == 3;
	}

	void Input::UpdateMouseButton(uint16 button, uint16 event)
	{
		if (m_ShouldCaptureMouseInput) {
			m_PendingMouseStateChanges.push_back(InputStateChange(button, event));
		}
	}

	void Input::SetOldMousePosition(double x, double y)
	{
		m_OldMouseXPos = x;
		m_OldMouseYPos = y;
	}

	void Input::SetMousePosition(double x, double y)
	{
		m_CurrentMouseXPos = x;
		m_CurrentMouseYPos = y;
	}

	void Input::MoveMouseTo(double x, double y)
	{
		if (m_ShouldCaptureMouseInput) {
			if (m_MouseWasBlocked) {
				m_OldMouseXPos = x;
				m_OldMouseYPos = y;
				m_CurrentMouseXPos = x;
				m_CurrentMouseYPos = y;
				m_MouseWasBlocked = false;
			}
			else {
				m_OldMouseXPos = m_CurrentMouseXPos;
				m_OldMouseYPos = m_CurrentMouseYPos;
				m_CurrentMouseXPos = x;
				m_CurrentMouseYPos = y;
			}
		}
	}

	void Input::UpdateAddScrollPosition(double x, double y)
	{
		if (m_ShouldCaptureMouseInput) {
			m_PendingScrollXInput += x;
			m_PendingScrollYInput += y;
		}
	}

	double Input::GetOldMousePositionX()
	{
		return m_OldMouseXPos;
	}

	double Input::GetOldMousePositionY()
	{
		return m_OldMouseYPos;
	}

	double Input::GetMousePositionX()
	{
		return m_CurrentMouseXPos;
	}

	double Input::GetMousePositionY()
	{
		return m_CurrentMouseYPos;
	}

	double Input::GetScrollPositionX()
	{
		return m_CurrentScrollXPos;
	}

	double Input::GetScrollPositionY()
	{
		return m_CurrentScrollYPos;
	}

	bool Input::GetShouldCaptureMouse()
	{
		return m_ShouldCaptureMouseInput;
	}

	bool Input::GetShouldCaptureKeyboard()
	{
		return m_ShouldCaptureKeyboardInput;
	}

	void Input::Prepare()
	{
		for (int i = 0; i < m_PendingKeyboardStateChanges.size(); i++) {
			m_KeyboardKeyStates[m_PendingKeyboardStateChanges[i].m_Button] = m_PendingKeyboardStateChanges[i].m_Type;
		}
		m_PendingKeyboardStateChanges.clear();
		for (int i = 0; i < m_PendingMouseStateChanges.size(); i++) {
			m_MouseButtonStates[m_PendingMouseStateChanges[i].m_Button] = m_PendingMouseStateChanges[i].m_Type;
		}
		m_PendingMouseStateChanges.clear();
	}

	void Input::Flush()
	{
		for (int i = 0; i < 512; i++) {
			if (m_KeyboardKeyStates[i] == 1) {
				m_KeyboardKeyStates[i] = 2;
			}
			else if (m_KeyboardKeyStates[i] == 3) {
				m_KeyboardKeyStates[i] = 0;
			}
		}
		for (int i = 0; i < 16; i++) {
			if (m_MouseButtonStates[i] == 1) {
				m_MouseButtonStates[i] = 2;
			}
			else if (m_MouseButtonStates[i] == 3) {
				m_MouseButtonStates[i] = 0;
			}
		}
		m_CurrentScrollXPos = 0.0;
		m_CurrentScrollYPos = 0.0;
	}

	void Input::SetShouldCaptureMouseInput(bool shouldCapture)
	{
		if (shouldCapture) {
			m_ShouldCaptureMouseInput = true;
		}
		else {
			m_PendingMouseStateChanges.clear();
			memset(&m_MouseButtonStates[0], 0, m_MouseButtonStates.size() * sizeof m_MouseButtonStates[0]);
			m_OldMouseXPos = 0.0;
			m_OldMouseYPos = 0.0;
			m_CurrentMouseXPos = 0.0;
			m_CurrentMouseYPos = 0.0;
			m_PendingScrollXInput = 0.0;
			m_PendingScrollYInput = 0.0;
			m_CurrentScrollXPos = 0.0;
			m_CurrentScrollYPos = 0.0;
			m_ShouldCaptureMouseInput = false;
		}
	}

	void Input::SetShouldCaptureKeyboardInput(bool shouldCapture)
	{
		if (shouldCapture) {
			m_ShouldCaptureKeyboardInput = true;
		}
		else {
			m_PendingKeyboardStateChanges.clear();
			memset(&m_KeyboardKeyStates[0], 0, m_KeyboardKeyStates.size() * sizeof m_KeyboardKeyStates[0]);
			m_ShouldCaptureKeyboardInput = false;
		}
	}

	void Input::SetMouseWasBlocked(bool mouseWasBlocked)
	{
		m_MouseWasBlocked = mouseWasBlocked;
		m_OldMouseXPos = 0.0;
		m_OldMouseYPos = 0.0;
		m_CurrentMouseXPos = 0.0;
		m_CurrentMouseYPos = 0.0;
	}
}