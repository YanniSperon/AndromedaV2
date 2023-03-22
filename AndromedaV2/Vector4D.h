#pragma once

namespace Andromeda {
	namespace Math {
		template <class>
		struct Vector2D;
		template <class>
		struct Vector3D;

		template <class DataType>
		struct Vector4D {
			union {
				struct {
					DataType X;
					DataType Y;
					DataType Z;
					DataType W;
				};
				struct {
					DataType X;
					DataType Y;
					DataType Z;
					DataType T;
				};
				struct {
					DataType R;
					DataType G;
					DataType B;
					DataType A;
				};
				struct {
					DataType C;
					DataType M;
					DataType Y;
					DataType K;
				};
				struct {
					DataType Values[4];
				};
			};



			Vector4D(const DataType& val1)
				: X(val1), Y(val1), Z(val1), W(val1)
			{
			}
			Vector4D(const DataType& val1, const DataType& val2)
				: X(val1), Y(val2), Z(), W()
			{
			}
			Vector4D(const DataType& val1, const DataType& val2, const DataType& val3)
				: X(val1), Y(val2), Z(val3), W()
			{
			}
			Vector4D(const DataType& val1, const DataType& val2, const DataType& val3, const DataType& val4)
				: X(val1), Y(val2), Z(val3), W(val4)
			{
			}



			Vector4D(const Vector2D<DataType>& other)
				: X(other.X), Y(other.Y), Z(), W()
			{
			}
			Vector4D(const Vector3D<DataType>& other)
				: X(other.X), Y(other.Y), Z(other.Z), W()
			{
			}
			Vector4D(const Vector4D<DataType>& other)
				: X(other.X), Y(other.Y), Z(other.Z), W(other.W)
			{
			}



			Vector4D(const Vector2D<DataType>& otherXY, const DataType& otherZ, const DataType& otherW)
				: X(otherXY.X), Y(otherXY.Y), Z(otherZ), W(otherW)
			{
			}
			Vector4D(const DataType& otherX, const Vector2D<DataType>& otherYZ, const DataType& otherW)
				: X(otherX), Y(otherYZ.X), Z(otherYZ.Y), W(otherW)
			{
			}
			Vector4D(const DataType& otherX, const DataType& otherY, const Vector2D<DataType>& otherZW)
				: X(otherX), Y(otherY), Z(otherZW.X), W(otherZW.Y)
			{
			}
			Vector4D(const Vector2D<DataType>& otherXY, const Vector2D<DataType>& otherZW)
				: X(otherXY.X), Y(otherXY.Y), Z(otherZW.Z), W(otherZW.W)
			{
			}
			Vector4D(const Vector3D<DataType>& otherXYZ, const DataType& otherW)
				: X(otherXYZ.X), Y(otherXYZ.Y), Z(otherXYZ.Z), W(otherW)
			{
			}
			Vector4D(const DataType& otherX, const Vector3D<DataType>& otherYZW)
				: X(otherX), Y(otherYZW.X), Z(otherYZW.Y), W(otherYZW.Z)
			{
			}



			template <class OtherDataType>
			Vector4D<DataType>& operator=(const Vector4D<OtherDataType>& other)
			{
				this->X = other.X;
				this->Y = other.Y;
				this->Z = other.Z;
				this->W = other.W;
				return *this;
			}



			template <class OtherDataType>
			DataType& operator[](uint64 i)
			{
				return this->Values[i];
			}



			DataType GetMagnitude()
			{
				return std::sqrt((this->X * this->X) + (this->Y * this->Y) + (this->Z * this->Z) + (this->W * this->W));
			}
			DataType GetMagnitudeSquared()
			{
				return (this->X * this->X) + (this->Y * this->Y) + (this->Z * this->Z) + (this->W * this->W);
			}
			Vector4D<DataType>& Normalize()
			{
				DataType& invMag = DataType(1) / GetMagnitude();
				this->X *= invMag;
				this->Y *= invMag;
				this->Z *= invMag;
				this->W *= invMag;
				return *this;
			}
			Vector4D<DataType>& Power(const DataType& exp)
			{
				this->X = std::pow(this->X, exp);
				this->Y = std::pow(this->Y, exp);
				this->Z = std::pow(this->Z, exp);
				this->W = std::pow(this->W, exp);
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& Power(const Vector4D<DataType>& exp)
			{
				this->X = std::pow(this->X, exp.X);
				this->Y = std::pow(this->Y, exp.Y);
				this->Z = std::pow(this->Z, exp.Z);
				this->W = std::pow(this->W, exp.W);
				return *this;
			}



			template <class OtherDataType>
			Vector4D<DataType>& operator+=(const OtherDataType& other)
			{
				this->X += other;
				this->Y += other;
				this->Z += other;
				this->W += other;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator+=(const Vector4D<OtherDataType>& other)
			{
				this->X += other.X;
				this->Y += other.Y;
				this->Z += other.Z;
				this->W += other.W;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator-=(const OtherDataType& other)
			{
				this->X -= other;
				this->Y -= other;
				this->Z -= other;
				this->W -= other;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator-=(const Vector4D<OtherDataType>& other)
			{
				this->X -= other.X;
				this->Y -= other.Y;
				this->Z -= other.Z;
				this->W -= other.W;
				return *this;
			}



			template <class OtherDataType>
			Vector4D<DataType>& operator*=(const OtherDataType& other)
			{
				this->X *= other;
				this->Y *= other;
				this->Z *= other;
				this->W *= other;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator*=(const Vector4D<OtherDataType>& other)
			{
				this->X *= other.X;
				this->Y *= other.Y;
				this->Z *= other.Z;
				this->W *= other.W;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator/=(const OtherDataType& other)
			{
				this->X /= other;
				this->Y /= other;
				this->Z /= other;
				this->W /= other;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator/=(const Vector4D<OtherDataType>& other)
			{
				this->X /= other.X;
				this->Y /= other.Y;
				this->Z /= other.Z;
				this->W /= other.W;
				return *this;
			}



			Vector4D<DataType>& operator++()
			{
				this->X++;
				this->Y++;
				this->Z++;
				this->W++;
				return *this;
			}
			Vector4D<DataType>& operator--()
			{
				this->X--;
				this->Y--;
				this->Z--;
				this->W--;
				return *this;
			}



			template <class OtherDataType>
			Vector4D<DataType>& operator%=(const OtherDataType& other)
			{
				this->X %= other;
				this->Y %= other;
				this->Z %= other;
				this->W %= other;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator%=(const Vector4D<OtherDataType>& other)
			{
				this->X %= other.X;
				this->Y %= other.Y;
				this->Z %= other.Z;
				this->W %= other.W;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator&=(const OtherDataType& other)
			{
				this->X &= other;
				this->Y &= other;
				this->Z &= other;
				this->W &= other;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator&=(const Vector4D<OtherDataType>& other)
			{
				this->X &= other.X;
				this->Y &= other.Y;
				this->Z &= other.Z;
				this->W &= other.W;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator|=(const OtherDataType& other)
			{
				this->X |= other;
				this->Y |= other;
				this->Z |= other;
				this->W |= other;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator|=(const Vector4D<OtherDataType>& other)
			{
				this->X |= other.X;
				this->Y |= other.Y;
				this->Z |= other.Z;
				this->W |= other.W;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator^=(const OtherDataType& other)
			{
				this->X ^= other;
				this->Y ^= other;
				this->Z ^= other;
				this->W ^= other;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator^=(const Vector4D<OtherDataType>& other)
			{
				this->X ^= other.X;
				this->Y ^= other.Y;
				this->Z ^= other.Z;
				this->W ^= other.W;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator<<=(const OtherDataType& other)
			{
				this->X <<= other;
				this->Y <<= other;
				this->Z <<= other;
				this->W <<= other;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator<<=(const Vector4D<OtherDataType>& other)
			{
				this->X <<= other.X;
				this->Y <<= other.Y;
				this->Z <<= other.Z;
				this->W <<= other.W;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator>>=(const OtherDataType& other)
			{
				this->X >>= other;
				this->Y >>= other;
				this->Z >>= other;
				this->W >>= other;
				return *this;
			}
			template <class OtherDataType>
			Vector4D<DataType>& operator>>=(const Vector4D<OtherDataType>& other)
			{
				this->X >>= other.X;
				this->Y >>= other.Y;
				this->Z >>= other.Z;
				this->W >>= other.W;
				return *this;
			}
		};



		template <class DataType>
		Vector4D<DataType> operator+(const Vector4D<DataType>& value)
		{
			return value;
		}
		template <class DataType>
		Vector4D<DataType> operator-(const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(-value.X, -value.Y, -value.Z, -value.W);
		}



		template <class DataType>
		Vector4D<DataType> operator+(const Vector4D<DataType>& value, const DataType& scalar)
		{
			return Vector4D<DataType>(value.X + scalar, value.Y + scalar, value.Z + scalar, value.W + scalar);
		}
		template <class DataType>
		Vector4D<DataType> operator+(const DataType& scalar, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(scalar + value.X, scalar + value.Y, scalar + value.Z, scalar + value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator+(const Vector4D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector4D<DataType>(value.X + other.X, value.Y + other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator+(const Vector2D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(value.X + other.X, value.Y + other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator+(const Vector4D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector4D<DataType>(value.X + other.X, value.Y + other.Y, value.Z + other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator+(const Vector3D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(value.X + other.X, value.Y + other.Y, value.Z + other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator+(const Vector4D<DataType>& value, const Vector4D<DataType>& other)
		{
			return Vector4D<DataType>(value.X + other.X, value.Y + other.Y, value.Z + other.Z, value.W + other.W);
		}



		template <class DataType>
		Vector4D<DataType> operator-(const Vector4D<DataType>& value, const DataType& scalar)
		{
			return Vector4D<DataType>(value.X - scalar, value.Y - scalar, value.Z - scalar, value.W - scalar);
		}
		template <class DataType>
		Vector4D<DataType> operator-(const DataType& scalar, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(scalar - value.X, scalar - value.Y, scalar - value.Z, scalar - value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator-(const Vector4D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector4D<DataType>(value.X - other.X, value.Y - other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator-(const Vector2D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X - value.X, other.Y - value.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator-(const Vector4D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector4D<DataType>(value.X - other.X, value.Y - other.Y, value.Z - other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator-(const Vector3D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X - value.X, other.Y - value.Y, other.Z - value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator-(const Vector4D<DataType>& value, const Vector4D<DataType>& other)
		{
			return Vector4D<DataType>(value.X - other.X, value.Y - other.Y, value.Z - other.Z, value.W - other.W);
		}



		template <class DataType>
		Vector4D<DataType> operator*(const Vector4D<DataType>& value, const DataType& scalar)
		{
			return Vector4D<DataType>(value.X * scalar, value.Y * scalar, value.Z * scalar, value.W * scalar);
		}
		template <class DataType>
		Vector4D<DataType> operator*(const DataType& scalar, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(scalar * value.X, scalar * value.Y, scalar * value.Z, scalar * value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator*(const Vector4D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector4D<DataType>(value.X * other.X, value.Y * other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator*(const Vector2D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(value.X * other.X, value.Y * other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator*(const Vector4D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector4D<DataType>(value.X * other.X, value.Y * other.Y, value.Z * other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator*(const Vector3D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(value.X * other.X, value.Y * other.Y, value.Z * other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator*(const Vector4D<DataType>& value, const Vector4D<DataType>& other)
		{
			return Vector4D<DataType>(value.X * other.X, value.Y * other.Y, value.Z * other.Z, value.W * other.W);
		}



		template <class DataType>
		Vector4D<DataType> operator/(const Vector4D<DataType>& value, const DataType& scalar)
		{
			return Vector4D<DataType>(value.X / scalar, value.Y / scalar, value.Z / scalar, value.W / scalar);
		}
		template <class DataType>
		Vector4D<DataType> operator/(const DataType& scalar, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(scalar / value.X, scalar / value.Y, scalar / value.Z, scalar / value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator/(const Vector4D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector4D<DataType>(value.X / other.X, value.Y / other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator/(const Vector2D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X / value.X, other.Y / value.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator/(const Vector4D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector4D<DataType>(value.X / other.X, value.Y / other.Y, value.Z / other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator/(const Vector3D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X / value.X, other.Y / value.Y, other.Z / value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator/(const Vector4D<DataType>& value, const Vector4D<DataType>& other)
		{
			return Vector4D<DataType>(value.X / other.X, value.Y / other.Y, value.Z / other.Z, value.W / other.W);
		}



		template <class DataType>
		Vector4D<DataType> operator%(const Vector4D<DataType>& value, const DataType& scalar)
		{
			return Vector4D<DataType>(value.X % scalar, value.Y % scalar, value.Z % scalar, value.W & scalar);
		}
		template <class DataType>
		Vector4D<DataType> operator%(const DataType& scalar, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(scalar % value.X, scalar % value.Y, scalar % value.Z, scalar % value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator%(const Vector4D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector4D<DataType>(value.X % other.X, value.Y % other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator%(const Vector2D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X % value.X, other.Y % value.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator%(const Vector4D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector4D<DataType>(value.X % other.X, value.Y % other.Y, value.Z % other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator%(const Vector3D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X % value.X, other.Y % value.Y, other.Z % value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator%(const Vector4D<DataType>& value, const Vector4D<DataType>& other)
		{
			return Vector4D<DataType>(value.X % other.X, value.Y % other.Y, value.Z % other.Z, value.W & other.W);
		}



		template <class DataType>
		Vector4D<DataType> operator&(const Vector4D<DataType>& value, const DataType& scalar)
		{
			return Vector4D<DataType>(value.X & scalar, value.Y & scalar, value.Z & scalar, value.W & scalar);
		}
		template <class DataType>
		Vector4D<DataType> operator&(const DataType& scalar, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(scalar & value.X, scalar & value.Y, scalar & value.Z, scalar & value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator&(const Vector4D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector4D<DataType>(value.X & other.X, value.Y & other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator&(const Vector2D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X & value.X, other.Y & value.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator&(const Vector4D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector4D<DataType>(value.X & other.X, value.Y & other.Y, value.Z & other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator&(const Vector3D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X & value.X, other.Y & value.Y, other.Z & value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator&(const Vector4D<DataType>& value, const Vector4D<DataType>& other)
		{
			return Vector4D<DataType>(value.X & other.X, value.Y & other.Y, value.Z & other.Z, value.W & other.W);
		}



		template <class DataType>
		Vector4D<DataType> operator|(const Vector4D<DataType>& value, const DataType& scalar)
		{
			return Vector4D<DataType>(value.X | scalar, value.Y | scalar, value.Z | scalar, value.W | scalar);
		}
		template <class DataType>
		Vector4D<DataType> operator|(const DataType& scalar, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(scalar | value.X, scalar | value.Y, scalar | value.Z, scalar | value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator|(const Vector4D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector4D<DataType>(value.X | other.X, value.Y | other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator|(const Vector2D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X | value.X, other.Y | value.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator|(const Vector4D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector4D<DataType>(value.X | other.X, value.Y | other.Y, value.Z | other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator|(const Vector3D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X | value.X, other.Y | value.Y, other.Z | value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator|(const Vector4D<DataType>& value, const Vector4D<DataType>& other)
		{
			return Vector4D<DataType>(value.X | other.X, value.Y | other.Y, value.Z | other.Z, value.W | other.W);
		}



		template <class DataType>
		Vector4D<DataType> operator^(const Vector4D<DataType>& value, const DataType& scalar)
		{
			return Vector4D<DataType>(value.X ^ scalar, value.Y ^ scalar, value.Z ^ scalar, value.W ^ scalar);
		}
		template <class DataType>
		Vector4D<DataType> operator^(const DataType& scalar, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(scalar ^ value.X, scalar ^ value.Y, scalar ^ value.Z, scalar ^ value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator^(const Vector4D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector4D<DataType>(value.X ^ other.X, value.Y ^ other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator^(const Vector2D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X ^ value.X, other.Y ^ value.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator^(const Vector4D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector4D<DataType>(value.X ^ other.X, value.Y ^ other.Y, value.Z ^ other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator^(const Vector3D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X ^ value.X, other.Y ^ value.Y, other.Z ^ value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator^(const Vector4D<DataType>& value, const Vector4D<DataType>& other)
		{
			return Vector4D<DataType>(value.X ^ other.X, value.Y ^ other.Y, value.Z ^ other.Z, value.W ^ other.W);
		}



		template <class DataType>
		Vector4D<DataType> operator<<(const Vector4D<DataType>& value, const DataType& scalar)
		{
			return Vector4D<DataType>(value.X << scalar, value.Y << scalar, value.Z << scalar, value.W << scalar);
		}
		template <class DataType>
		Vector4D<DataType> operator<<(const DataType& scalar, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(scalar << value.X, scalar << value.Y, scalar << value.Z, scalar << value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator<<(const Vector4D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector4D<DataType>(value.X << other.X, value.Y << other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator<<(const Vector2D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X << value.X, other.Y << value.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator<<(const Vector4D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector4D<DataType>(value.X << other.X, value.Y << other.Y, value.Z << other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator<<(const Vector3D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X << value.X, other.Y << value.Y, other.Z << value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator<<(const Vector4D<DataType>& value, const Vector4D<DataType>& other)
		{
			return Vector4D<DataType>(value.X << other.X, value.Y << other.Y, value.Z << other.Z, value.W << other.W);
		}



		template <class DataType>
		Vector4D<DataType> operator>>(const Vector4D<DataType>& value, const DataType& scalar)
		{
			return Vector4D<DataType>(value.X >> scalar, value.Y >> scalar, value.Z >> scalar, value.W >> scalar);
		}
		template <class DataType>
		Vector4D<DataType> operator>>(const DataType& scalar, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(scalar >> value.X, scalar >> value.Y, scalar >> value.Z, scalar >> value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator>>(const Vector4D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector4D<DataType>(value.X >> other.X, value.Y >> other.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator>>(const Vector2D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X >> value.X, other.Y >> value.Y, value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator>>(const Vector4D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector4D<DataType>(value.X >> other.X, value.Y >> other.Y, value.Z >> other.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator>>(const Vector3D<DataType>& other, const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(other.X >> value.X, other.Y >> value.Y, other.Z >> value.Z, value.W);
		}
		template <class DataType>
		Vector4D<DataType> operator>>(const Vector4D<DataType>& value, const Vector4D<DataType>& other)
		{
			return Vector4D<DataType>(value.X >> other.X, value.Y >> other.Y, value.Z >> other.Z, value.W >> other.W);
		}



		template <class DataType>
		Vector4D<DataType> operator~(const Vector4D<DataType>& value)
		{
			return Vector4D<DataType>(~value.X, ~value.Y, ~value.Z, ~value.W);
		}



		template <class DataType>
		bool operator==(const Vector4D<DataType>& value1, const Vector4D<DataType>& value2)
		{
			return value1.X == value2.X && value1.Y == value2.Y && value1.Z == value2.Z && value1.W == value2.W;
		}
		template <class DataType>
		bool operator!=(const Vector4D<DataType>& value1, const Vector4D<DataType>& value2)
		{
			return value1.X != value2.X || value1.Y != value2.Y || value1.Z != value2.Z || value1.W != value2.W;
		}



		template <class DataType>
		bool operator<(const Vector4D<DataType>& value1, const Vector4D<DataType>& value2)
		{
			return value1.X < value2.X && value1.Y < value2.Y && value1.Z < value2.Z && value1.W < value2.W;
		}
		template <class DataType>
		bool operator<=(const Vector4D<DataType>& value1, const Vector4D<DataType>& value2)
		{
			return value1.X <= value2.X && value1.Y <= value2.Y && value1.Z <= value2.Z && value1.W <= value2.W;
		}
		template <class DataType>
		bool operator>(const Vector4D<DataType>& value1, const Vector4D<DataType>& value2)
		{
			return value1.X > value2.X && value1.Y > value2.Y && value1.Z > value2.Z && value1.W > value2.W;
		}
		template <class DataType>
		bool operator>=(const Vector4D<DataType>& value1, const Vector4D<DataType>& value2)
		{
			return value1.X >= value2.X && value1.Y >= value2.Y && value1.Z >= value2.Z && value1.W >= value2.W;
		}



		template <class DataType>
		Vector4D<DataType> operator&&(const Vector4D<DataType>& value1, const Vector4D<DataType>& value2)
		{
			return Vector4D<DataType>(value1.X && value2.X, value1.Y && value2.Y, value1.Z && value2.Z, value1.W && value2.W);
		}
		template <class DataType>
		Vector4D<DataType> operator||(const Vector4D<DataType>& value1, const Vector4D<DataType>& value2)
		{
			return Vector4D<DataType>(value1.X || value2.X, value1.Y || value2.Y, value1.Z || value2.Z, value1.W || value2.W);
		}
	}
}