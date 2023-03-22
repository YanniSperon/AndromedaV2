#pragma once

#include <cstdint>

#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"

namespace Andromeda {

	using int8 = int8_t;
	using int16 = int16_t;
	using int32 = int32_t;
	using int64 = int64_t;

	using uint8 = uint8_t;
	using uint16 = uint16_t;
	using uint32 = uint32_t;
	using uint64 = uint64_t;

	namespace Math {

		using FVector2D = Vector2D<float>;
		using DVector2D = Vector2D<double>;

		using FVector3D = Vector3D<float>;
		using DVector3D = Vector3D<double>;

		using FVector4D = Vector4D<float>;
		using DVector4D = Vector4D<double>;
	}
}