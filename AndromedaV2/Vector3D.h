#pragma once

namespace Andromeda {
	namespace Math {
		template <class>
		struct Vector2D;
		template <class>
		struct Vector4D;

		template <class DataType>
		struct Vector3D {
			union {
				struct {
					DataType X;
					DataType Y;
					DataType Z;
				};
				struct {
					DataType R;
					DataType G;
					DataType B;
				};
				struct {
					DataType H;
					DataType S;
					DataType L;
				};
				struct {
					DataType H;
					DataType S;
					DataType V;
				};
				struct {
					DataType Values[3];
				};
			};



			Vector3D(const DataType& val1)
				: X(val1), Y(val1), Z(val1)
			{
			}
			Vector3D(const DataType& val1, const DataType& val2)
				: X(val1), Y(val2), Z()
			{
			}
			Vector3D(const DataType& val1, const DataType& val2, const DataType& val3)
				: X(val1), Y(val2), Z(val3)
			{
			}



			Vector3D(const Vector2D<DataType>& other)
				: X(other.X), Y(other.Y), Z()
			{
			}
			Vector3D(const Vector3D<DataType>& other)
				: X(other.X), Y(other.Y), Z(other.Z)
			{
			}
			Vector3D(const Vector4D<DataType>& other)
				: X(other.X), Y(other.Y), Z(other.Z)
			{
			}



			Vector3D(const DataType& otherX, const Vector2D<DataType>& otherYZ)
				: X(otherX), Y(otherYZ.X), Z(otherYZ.Y)
			{
			}
			Vector3D(const Vector2D<DataType>& otherXY, const DataType& otherZ)
				: X(otherXY.X), Y(otherXY.Y), Z(otherZ)
			{
			}



			template <class OtherDataType>
			Vector3D<DataType>& operator=(const Vector3D<OtherDataType>& other)
			{
				this->X = other.X;
				this->Y = other.Y;
				this->Z = other.Z;
				return *this;
			}



			template <class OtherDataType>
			DataType& operator[](uint64 i)
			{
				return this->Values[i];
			}



			DataType GetMagnitude()
			{
				return std::sqrt((this->X * this->X) + (this->Y * this->Y) + (this->Z * this->Z));
			}
			DataType GetMagnitudeSquared()
			{
				return (this->X * this->X) + (this->Y * this->Y) + (this->Z * this->Z);
			}
			Vector3D<DataType>& Normalize()
			{
				DataType& invMag = DataType(1) / GetMagnitude();
				this->X *= invMag;
				this->Y *= invMag;
				this->Z *= invMag;
				return *this;
			}
			Vector3D<DataType>& Power(const DataType& exp)
			{
				this->X = std::pow(this->X, exp);
				this->Y = std::pow(this->Y, exp);
				this->Z = std::pow(this->Z, exp);
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& Power(const Vector3D<DataType>& exp)
			{
				this->X = std::pow(this->X, exp.X);
				this->Y = std::pow(this->Y, exp.Y);
				this->Z = std::pow(this->Z, exp.Z);
				return *this;
			}



			template <class OtherDataType>
			Vector3D<DataType>& operator+=(const OtherDataType& other)
			{
				this->X += other;
				this->Y += other;
				this->Z += other;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator+=(const Vector3D<OtherDataType>& other)
			{
				this->X += other.X;
				this->Y += other.Y;
				this->Z += other.Z;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator-=(const OtherDataType& other)
			{
				this->X -= other;
				this->Y -= other;
				this->Z -= other;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator-=(const Vector3D<OtherDataType>& other)
			{
				this->X -= other.X;
				this->Y -= other.Y;
				this->Z -= other.Z;
				return *this;
			}



			template <class OtherDataType>
			Vector3D<DataType>& operator*=(const OtherDataType& other)
			{
				this->X *= other;
				this->Y *= other;
				this->Z *= other;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator*=(const Vector3D<OtherDataType>& other)
			{
				this->X *= other.X;
				this->Y *= other.Y;
				this->Z *= other.Z;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator/=(const OtherDataType& other)
			{
				this->X /= other;
				this->Y /= other;
				this->Z /= other;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator/=(const Vector3D<OtherDataType>& other)
			{
				this->X /= other.X;
				this->Y /= other.Y;
				this->Z /= other.Z;
				return *this;
			}



			Vector3D<DataType>& operator++()
			{
				this->X++;
				this->Y++;
				this->Z++;
				return *this;
			}
			Vector3D<DataType>& operator--()
			{
				this->X--;
				this->Y--;
				this->Z--;
				return *this;
			}



			template <class OtherDataType>
			Vector3D<DataType>& operator%=(const OtherDataType& other)
			{
				this->X %= other;
				this->Y %= other;
				this->Z %= other;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator%=(const Vector3D<OtherDataType>& other)
			{
				this->X %= other.X;
				this->Y %= other.Y;
				this->Z %= other.Z;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator&=(const OtherDataType& other)
			{
				this->X &= other;
				this->Y &= other;
				this->Z &= other;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator&=(const Vector3D<OtherDataType>& other)
			{
				this->X &= other.X;
				this->Y &= other.Y;
				this->Z &= other.Z;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator|=(const OtherDataType& other)
			{
				this->X |= other;
				this->Y |= other;
				this->Z |= other;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator|=(const Vector3D<OtherDataType>& other)
			{
				this->X |= other.X;
				this->Y |= other.Y;
				this->Z |= other.Z;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator^=(const OtherDataType& other)
			{
				this->X ^= other;
				this->Y ^= other;
				this->Z ^= other;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator^=(const Vector3D<OtherDataType>& other)
			{
				this->X ^= other.X;
				this->Y ^= other.Y;
				this->Z ^= other.Z;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator<<=(const OtherDataType& other)
			{
				this->X <<= other;
				this->Y <<= other;
				this->Z <<= other;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator<<=(const Vector3D<OtherDataType>& other)
			{
				this->X <<= other.X;
				this->Y <<= other.Y;
				this->Z <<= other.Z;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator>>=(const OtherDataType& other)
			{
				this->X >>= other;
				this->Y >>= other;
				this->Z >>= other;
				return *this;
			}
			template <class OtherDataType>
			Vector3D<DataType>& operator>>=(const Vector3D<OtherDataType>& other)
			{
				this->X >>= other.X;
				this->Y >>= other.Y;
				this->Z >>= other.Z;
				return *this;
			}
		};



		template <class DataType>
		Vector3D<DataType> operator+(const Vector3D<DataType>& value)
		{
			return value;
		}
		template <class DataType>
		Vector3D<DataType> operator-(const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(-value.X, -value.Y, -value.Z);
		}



		template <class DataType>
		Vector3D<DataType> operator+(const Vector3D<DataType>& value, const DataType& scalar)
		{
			return Vector3D<DataType>(value.X + scalar, value.Y + scalar, value.Z + scalar);
		}
		template <class DataType>
		Vector3D<DataType> operator+(const DataType& scalar, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(scalar + value.X, scalar + value.Y, scalar + value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator+(const Vector3D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector3D<DataType>(value.X + other.X, value.Y + other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator+(const Vector2D<DataType>& other, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(value.X + other.X, value.Y + other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator+(const Vector3D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector3D<DataType>(value.X + other.X, value.Y + other.Y, value.Z + other.Z);
		}



		template <class DataType>
		Vector3D<DataType> operator-(const Vector3D<DataType>& value, const DataType& scalar)
		{
			return Vector3D<DataType>(value.X - scalar, value.Y - scalar, value.Z - scalar);
		}
		template <class DataType>
		Vector3D<DataType> operator-(const DataType& scalar, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(scalar - value.X, scalar - value.Y, scalar - value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator-(const Vector3D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector3D<DataType>(value.X - other.X, value.Y - other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator-(const Vector2D<DataType>& other, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(other.X - value.X, other.Y - value.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator-(const Vector3D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector3D<DataType>(value.X - other.X, value.Y - other.Y, value.Z - other.Z);
		}



		template <class DataType>
		Vector3D<DataType> operator*(const Vector3D<DataType>& value, const DataType& scalar)
		{
			return Vector3D<DataType>(value.X * scalar, value.Y * scalar, value.Z * scalar);
		}
		template <class DataType>
		Vector3D<DataType> operator*(const DataType& scalar, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(scalar * value.X, scalar * value.Y, scalar * value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator*(const Vector3D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector3D<DataType>(value.X * other.X, value.Y * other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator*(const Vector2D<DataType>& other, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(value.X * other.X, value.Y * other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator*(const Vector3D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector3D<DataType>(value.X * other.X, value.Y * other.Y, value.Z * other.Z);
		}



		template <class DataType>
		Vector3D<DataType> operator/(const Vector3D<DataType>& value, const DataType& scalar)
		{
			return Vector3D<DataType>(value.X / scalar, value.Y / scalar, value.Z / scalar);
		}
		template <class DataType>
		Vector3D<DataType> operator/(const DataType& scalar, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(scalar / value.X, scalar / value.Y, scalar / value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator/(const Vector3D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector3D<DataType>(value.X / other.X, value.Y / other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator/(const Vector2D<DataType>& other, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(other.X / value.X, other.Y / value.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator/(const Vector3D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector3D<DataType>(value.X / other.X, value.Y / other.Y, value.Z / other.Z);
		}



		template <class DataType>
		Vector3D<DataType> operator%(const Vector3D<DataType>& value, const DataType& scalar)
		{
			return Vector3D<DataType>(value.X % scalar, value.Y % scalar, value.Z % scalar);
		}
		template <class DataType>
		Vector3D<DataType> operator%(const DataType& scalar, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(scalar % value.X, scalar % value.Y, scalar % value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator%(const Vector3D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector3D<DataType>(value.X % other.X, value.Y % other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator%(const Vector2D<DataType>& other, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(other.X % value.X, other.Y % value.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator%(const Vector3D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector3D<DataType>(value.X % other.X, value.Y % other.Y, value.Z % other.Z);
		}



		template <class DataType>
		Vector3D<DataType> operator&(const Vector3D<DataType>& value, const DataType& scalar)
		{
			return Vector3D<DataType>(value.X & scalar, value.Y & scalar, value.Z & scalar);
		}
		template <class DataType>
		Vector3D<DataType> operator&(const DataType& scalar, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(scalar & value.X, scalar & value.Y, scalar & value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator&(const Vector3D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector3D<DataType>(value.X & other.X, value.Y & other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator&(const Vector2D<DataType>& other, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(other.X & value.X, other.Y & value.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator&(const Vector3D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector3D<DataType>(value.X & other.X, value.Y & other.Y, value.Z & other.Z);
		}



		template <class DataType>
		Vector3D<DataType> operator|(const Vector3D<DataType>& value, const DataType& scalar)
		{
			return Vector3D<DataType>(value.X | scalar, value.Y | scalar, value.Z | scalar);
		}
		template <class DataType>
		Vector3D<DataType> operator|(const DataType& scalar, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(scalar | value.X, scalar | value.Y, scalar | value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator|(const Vector3D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector3D<DataType>(value.X | other.X, value.Y | other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator|(const Vector2D<DataType>& other, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(other.X | value.X, other.Y | value.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator|(const Vector3D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector3D<DataType>(value.X | other.X, value.Y | other.Y, value.Z | other.Z);
		}



		template <class DataType>
		Vector3D<DataType> operator^(const Vector3D<DataType>& value, const DataType& scalar)
		{
			return Vector3D<DataType>(value.X ^ scalar, value.Y ^ scalar, value.Z ^ scalar);
		}
		template <class DataType>
		Vector3D<DataType> operator^(const DataType& scalar, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(scalar ^ value.X, scalar ^ value.Y, scalar ^ value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator^(const Vector3D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector3D<DataType>(value.X ^ other.X, value.Y ^ other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator^(const Vector2D<DataType>& other, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(other.X ^ value.X, other.Y ^ value.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator^(const Vector3D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector3D<DataType>(value.X ^ other.X, value.Y ^ other.Y, value.Z ^ other.Z);
		}



		template <class DataType>
		Vector3D<DataType> operator<<(const Vector3D<DataType>& value, const DataType& scalar)
		{
			return Vector3D<DataType>(value.X << scalar, value.Y << scalar, value.Z << scalar);
		}
		template <class DataType>
		Vector3D<DataType> operator<<(const DataType& scalar, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(scalar << value.X, scalar << value.Y, scalar << value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator<<(const Vector3D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector3D<DataType>(value.X << other.X, value.Y << other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator<<(const Vector2D<DataType>& other, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(other.X << value.X, other.Y << value.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator<<(const Vector3D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector3D<DataType>(value.X << other.X, value.Y << other.Y, value.Z << other.Z);
		}



		template <class DataType>
		Vector3D<DataType> operator>>(const Vector3D<DataType>& value, const DataType& scalar)
		{
			return Vector3D<DataType>(value.X >> scalar, value.Y >> scalar, value.Z >> scalar);
		}
		template <class DataType>
		Vector3D<DataType> operator>>(const DataType& scalar, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(scalar >> value.X, scalar >> value.Y, scalar >> value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator>>(const Vector3D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector3D<DataType>(value.X >> other.X, value.Y >> other.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator>>(const Vector2D<DataType>& other, const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(other.X >> value.X, other.Y >> value.Y, value.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator>>(const Vector3D<DataType>& value, const Vector3D<DataType>& other)
		{
			return Vector3D<DataType>(value.X >> other.X, value.Y >> other.Y, value.Z >> other.Z);
		}



		template <class DataType>
		Vector3D<DataType> operator~(const Vector3D<DataType>& value)
		{
			return Vector3D<DataType>(~value.X, ~value.Y, ~value.Z);
		}



		template <class DataType>
		bool operator==(const Vector3D<DataType>& value1, const Vector3D<DataType>& value2)
		{
			return value1.X == value2.X && value1.Y == value2.Y && value1.Z == value2.Z;
		}
		template <class DataType>
		bool operator!=(const Vector3D<DataType>& value1, const Vector3D<DataType>& value2)
		{
			return value1.X != value2.X || value1.Y != value2.Y || value1.Z != value2.Z;
		}



		template <class DataType>
		bool operator<(const Vector3D<DataType>& value1, const Vector3D<DataType>& value2)
		{
			return value1.X < value2.X && value1.Y < value2.Y && value1.Z < value2.Z;
		}
		template <class DataType>
		bool operator<=(const Vector3D<DataType>& value1, const Vector3D<DataType>& value2)
		{
			return value1.X <= value2.X && value1.Y <= value2.Y && value1.Z <= value2.Z;
		}
		template <class DataType>
		bool operator>(const Vector3D<DataType>& value1, const Vector3D<DataType>& value2)
		{
			return value1.X > value2.X && value1.Y > value2.Y && value1.Z > value2.Z;
		}
		template <class DataType>
		bool operator>=(const Vector3D<DataType>& value1, const Vector3D<DataType>& value2)
		{
			return value1.X >= value2.X && value1.Y >= value2.Y && value1.Z >= value2.Z;
		}



		template <class DataType>
		Vector3D<DataType> operator&&(const Vector3D<DataType>& value1, const Vector3D<DataType>& value2)
		{
			return Vector3D<DataType>(value1.X && value2.X, value1.Y && value2.Y, value1.Z && value2.Z);
		}
		template <class DataType>
		Vector3D<DataType> operator||(const Vector3D<DataType>& value1, const Vector3D<DataType>& value2)
		{
			return Vector3D<DataType>(value1.X || value2.X, value1.Y || value2.Y, value1.Z || value2.Z);
		}
	}
}