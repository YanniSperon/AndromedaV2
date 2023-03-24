#pragma once

#include "Types.h"
#include "UUID.h"

namespace Andromeda {
	class PointerManager {
	private:
		HashMap<UUID, void*> m_Map;
	public:
		void FlagDelete(void* pointer);
	};

	class UniquePointer {
	private:

	public:

	};

	class SharedPointer {
	private:

	public:

	};

	class WeakPointer {
	private:

	public:

	};
}