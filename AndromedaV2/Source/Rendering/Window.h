#pragma once

#include "Utility/Types.h"

namespace Andromeda {
	class Window {
	private:
		int32 m_Width;
		int32 m_Height;
	public:
		Window(bool deferInitialization = false);
		~Window();

		void Prepare();
	};
}