#pragma once

#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <mutex>
#include <unordered_map>

#include "IntTypes.h"
#include "Vendor/glm/glm.hpp"

namespace Andromeda {

	using int8 = int8_t;
	using int16 = int16_t;
	using int32 = int32_t;
	using int64 = int64_t;

	using uint8 = uint8_t;
	using uint16 = uint16_t;
	using uint32 = uint32_t;
	using uint64 = uint64_t;

	template <class T>
	using Array = std::vector<T>;

	template <class T, class U>
	using HashMap = std::unordered_map<T, U>;

	template <class T>
	using Queue = std::queue<T>;

	template <class T>
	using DQueue = std::deque<T>;

	using String = std::string;

	using Mutex = std::mutex;

	namespace Math {

		using FVector2D = glm::vec2;
		using DVector2D = glm::dvec2;

		using BVector2D = glm::bvec2;

		using I8Vector2D = glm::i8vec2;
		using U8Vector2D = glm::u8vec2;
		using I16Vector2D = glm::i16vec2;
		using U16Vector2D = glm::u16vec2;
		using I32Vector2D = glm::i32vec2;
		using U32Vector2D = glm::u32vec2;
		using I64Vector2D = glm::i64vec2;
		using U64Vector2D = glm::u64vec2;



		using FVector3D = glm::vec3;
		using DVector3D = glm::dvec3;

		using BVector3D = glm::bvec3;

		using I8Vector3D = glm::i8vec3;
		using U8Vector3D = glm::u8vec3;
		using I16Vector3D = glm::i16vec3;
		using U16Vector3D = glm::u16vec3;
		using I32Vector3D = glm::i32vec3;
		using U32Vector3D = glm::u32vec3;
		using I64Vector3D = glm::i64vec3;
		using U64Vector3D = glm::u64vec3;



		using FVector4D = glm::vec4;
		using DVector4D = glm::dvec4;

		using BVector4D = glm::bvec4;

		using I8Vector4D = glm::i8vec4;
		using U8Vector4D = glm::u8vec4;
		using I16Vector4D = glm::i16vec4;
		using U16Vector4D = glm::u16vec4;
		using I32Vector4D = glm::i32vec4;
		using U32Vector4D = glm::u32vec4;
		using I64Vector4D = glm::i64vec4;
		using U64Vector4D = glm::u64vec4;



		using FMatrix2x2 = glm::mat2;
		using DMatrix2x2 = glm::dmat2;

		using FMatrix3x3 = glm::mat3;
		using DMatrix3x3 = glm::dmat3;

		using FMatrix4x4 = glm::mat4;
		using DMatrix4x4 = glm::dmat4;

	}
}