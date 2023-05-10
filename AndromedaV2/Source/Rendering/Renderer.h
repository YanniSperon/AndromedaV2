#pragma once

#include "Utility/Types.h"

namespace Andromeda {
	namespace Rendering {
		class Renderer {
		private:
		public:
			Renderer();
			virtual ~Renderer();

			virtual void Update(Duration deltaTime);
		};
	}
}