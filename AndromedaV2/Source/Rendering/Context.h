#pragma once

#include "Utility/Types.h"

namespace Andromeda {
	namespace Graphics {
		class Context {
		public:
			virtual ~Context();

			virtual void Initialize() = 0;
			virtual void PrepareFrame() = 0;
			virtual void EndFrame() = 0;
			virtual void Deinitialize() = 0;
		};
	}
}