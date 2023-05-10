#pragma once

#include "IntDefinitions.h"

#include <random>

namespace Andromeda {
	class Random32 {
	private:
		uint32 m_Seed;
		std::mt19937 m_Engine;

		std::uniform_real_distribution<float> m_FloatDistribution;
		std::uniform_int_distribution<int32> m_IntDistribution;
		std::uniform_int_distribution<uint32> m_UIntDistribution;

	public:
		Random32();
		Random32(uint32 seed);

		void SetFloatBounds(float low, float high);
		void SetIntBounds(int32 low, int32 high);
		void SetUIntBounds(uint32 low, uint32 high);

		// A float including the low and high bounds
		float Float();

		// A 32-bit signed integer including the low and high bounds
		int32 Int32Inclusive();
		// A 32-bit unsigned integer including the low and high bounds
		uint32 UInt32Inclusive();

		uint32 GetSeed() const;

		void ResetFloatBounds();
		void ResetIntBounds();
		void ResetUIntBounds();
	};

	class Random64 {
	private:
		uint64 m_Seed;
		std::mt19937_64 m_Engine;

		std::uniform_real_distribution<double> m_DoubleDistribution;
		std::uniform_int_distribution<int64> m_IntDistribution;
		std::uniform_int_distribution<uint64> m_UIntDistribution;

	public:
		Random64();
		Random64(uint64 seed);

		void SetDoubleBounds(double low, double high);
		void SetIntBounds(int64 low, int64 high);
		void SetUIntBounds(uint64 low, uint64 high);

		// A double including the low and high bounds
		double Double(double low, double high);

		// A 64-bit signed integer including the low and high bounds
		int64 Int64Inclusive();
		// A 64-bit unsigned integer including the low and high bounds
		uint64 UInt64Inclusive();

		uint64 GetSeed() const;

		void ResetDoubleBounds();
		void ResetIntBounds();
		void ResetUIntBounds();
	};
}