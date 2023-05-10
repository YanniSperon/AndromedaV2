#pragma once

// TODO
#include <algorithm>

#include "Vendor/glm/glm.hpp"

namespace Andromeda {
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

		template <class T>
		static const T& Min(const T& a, const T& b)
		{
			return std::min(a, b);
		}
	}
}