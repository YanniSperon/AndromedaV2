#pragma once

#include "MathDefinitions.h"
#include "IntDefinitions.h"
#include "Random.h"

namespace Andromeda {
	class UUID {
	private:
		Math::U64Vector4D m_ID;
	public:
		// Creates an empty UUID (with all 0 values)
		UUID();
		// Creates a UUID (from all randomly generated values)
		// Make sure to set the bounds of the UInt generator
		UUID(Random64& random);
		// Copies the values of an existing UUID
		UUID(const UUID& other);

		// Creates a UUID (from passed in values)
		UUID(uint64 a, uint64 b, uint64 c, uint64 d);
		// Creates a UUID (from passed in vector values)
		UUID(const Math::U64Vector4D id);

		friend bool operator==(const UUID& L, const UUID& R);
	};

	bool operator==(const UUID& L, const UUID& R);
}