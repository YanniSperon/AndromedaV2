#pragma once

#include "Rendering/Context.h"

namespace Andromeda {
	namespace Graphics {
		class OpenGLContext : public Context {
		public:
			OpenGLContext(bool deferInitialization = false);
			virtual ~OpenGLContext() override;

			virtual void Initialize() override;
			virtual void PrepareFrame() override;
			virtual void EndFrame() override;
			virtual void Deinitialize() override;
		};
	}
}