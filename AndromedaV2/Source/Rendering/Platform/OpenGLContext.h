#pragma once

#include "Rendering/Context.h"

namespace Andromeda {
	namespace Graphics {
		class Context {
		public:
			Context(bool deferInitialization = false);
			virtual ~Context();

			virtual void Initialize();
			virtual void PrepareFrame();
			virtual void EndFrame();
			virtual void Deinitialize();
		};
	}
}