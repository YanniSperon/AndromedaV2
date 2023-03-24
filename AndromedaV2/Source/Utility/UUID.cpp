#include "UUID.h"

namespace Andromeda {
	UUID::UUID()
		: m_ID(0ull, 0ull, 0ull, 0ull)
	{
	}

	UUID::UUID(Random64& random)
	{
		m_ID = Math::U64Vector4D(random.UInt64Inclusive(), random.UInt64Inclusive(), random.UInt64Inclusive(), random.UInt64Inclusive());
	}

	UUID::UUID(const UUID& other)
		: m_ID(other.m_ID)
	{
	}

	UUID::UUID(uint64 a, uint64 b, uint64 c, uint64 d)
		: m_ID(a, b, c, d)
	{
	}

	UUID::UUID(const Math::U64Vector4D id)
		: m_ID(id)
	{
	}

	bool operator==(const UUID& L, const UUID& R)
	{
		return L.m_ID == R.m_ID;
	}
}