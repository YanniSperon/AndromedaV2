#pragma once

#include "Types.h"
#include "UUID.h"

namespace Andromeda {
	class PointerManager {
	private:
		HashMap<void*, UniquePointer*> m_UniqueMap;
		HashMap<void*, LinkedList<SharedPointer*>> m_SharedMap;
		HashMap<void*, LinkedList<WeakPointer*>> m_WeakMap;
	public:
		void FlagDelete(UniquePointer* pointer);
		void FlagDelete(SharedPointer* pointer);
		void FlagDelete(UniquePointer* pointer);
		void AddUniquePointer(void* pointer);
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