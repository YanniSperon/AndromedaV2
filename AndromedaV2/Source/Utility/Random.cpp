#include "Random.h"

namespace Andromeda {
	Random32::Random32()
	{
		std::random_device rd;
		m_Seed = rd();
		m_Engine = std::mt19937();
		m_Engine.seed(m_Seed);

		SetFloatBounds(0, 1.0f);
		SetIntBounds(INT32_MIN, INT32_MAX);
		SetUIntBounds(0, UINT32_MAX);
	}

	Random32::Random32(uint32 seed)
	{
		m_Seed = seed;
		m_Engine = std::mt19937();
		m_Engine.seed(m_Seed);

		SetFloatBounds(0, 1.0f);
		SetIntBounds(INT32_MIN, INT32_MAX);
		SetUIntBounds(0, UINT32_MAX);
	}

	void Random32::SetFloatBounds(float low, float high)
	{
		m_FloatDistribution = std::uniform_real_distribution<float>(low, high);
	}

	void Random32::SetIntBounds(int32 low, int32 high)
	{
		m_IntDistribution = std::uniform_int_distribution<int32>(low, high);
	}

	void Random32::SetUIntBounds(uint32 low, uint32 high)
	{
		m_UIntDistribution = std::uniform_int_distribution<uint32>(low, high);
	}
	
	float Random32::Float()
	{
		return m_FloatDistribution(m_Engine);
	}

	int32 Random32::Int32Inclusive()
	{
		return m_IntDistribution(m_Engine);
	}

	uint32 Random32::UInt32Inclusive()
	{
		return m_UIntDistribution(m_Engine);
	}

	uint32 Random32::GetSeed() const
	{
		return m_Seed;
	}

	void Random32::ResetFloatBounds()
	{
		SetFloatBounds(0.0f, 1.0f);
	}

	void Random32::ResetIntBounds()
	{
		SetIntBounds(INT32_MIN, INT32_MAX);
	}

	void Random32::ResetUIntBounds()
	{
		SetUIntBounds(0, UINT32_MAX);
	}

	Random64::Random64()
	{
		std::random_device rd;
		m_Seed = (static_cast<uint64>(rd()) << 32) | rd();
		m_Engine = std::mt19937_64();
		m_Engine.seed(m_Seed);

		SetDoubleBounds(0.0, 1.0);
		SetIntBounds(INT64_MIN, INT64_MAX);
		SetUIntBounds(0, UINT64_MAX);
	}

	Random64::Random64(uint64 seed)
	{
		m_Seed = seed;
		m_Engine = std::mt19937_64();
		m_Engine.seed(m_Seed);

		SetDoubleBounds(0.0, 1.0);
		SetIntBounds(INT64_MIN, INT64_MAX);
		SetUIntBounds(0, UINT64_MAX);
	}

	void Random64::SetDoubleBounds(double low, double high)
	{
		m_DoubleDistribution = std::uniform_real_distribution<double>(low, high);
	}

	void Random64::SetIntBounds(int64 low, int64 high)
	{
		m_IntDistribution = std::uniform_int_distribution<int64>(low, high);
	}

	void Random64::SetUIntBounds(uint64 low, uint64 high)
	{
		m_UIntDistribution = std::uniform_int_distribution<uint64>(low, high);
	}

	double Random64::Double(double low, double high)
	{
		return m_DoubleDistribution(m_Engine);
	}

	int64 Random64::Int64Inclusive()
	{
		return m_IntDistribution(m_Engine);
	}

	uint64 Random64::UInt64Inclusive()
	{
		return m_UIntDistribution(m_Engine);
	}

	uint64 Random64::GetSeed() const
	{
		return m_Seed;
	}

	void Random64::ResetDoubleBounds()
	{
		SetDoubleBounds(-DBL_MAX, DBL_MAX);
	}

	void Random64::ResetIntBounds()
	{
		SetIntBounds(INT64_MIN, INT64_MAX);
	}

	void Random64::ResetUIntBounds()
	{
		SetUIntBounds(0, UINT64_MAX);
	}
}