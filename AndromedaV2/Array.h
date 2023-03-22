#pragma once

#include "Types.h"

namespace Andromeda {
	namespace Collections {
		template <class T>
		class Array {
		private:
			T* data;
			uint64 count;
		public:
			Array() 
				: data(nullptr), count(0)
			{
			}
		};
	}
}