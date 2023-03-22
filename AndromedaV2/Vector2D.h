#pragma once

#include <cmath>

namespace Andromeda {
	namespace Math {
		template <class>
		struct Vector3D;
		template <class>
		struct Vector4D;

		template <class DataType>
		struct Vector2D {
			union {
				struct {
					DataType X;
					DataType Y;
				};
				struct {
					DataType R;
					DataType G;
				};
				struct {
					DataType U;
					DataType V;
				};
				struct {
					DataType Values[2];
				};
			};



			Vector2D(const DataType& val1)
				: X(val1), Y(val1)
			{
			}
			Vector2D(const DataType& val1, const DataType& val2)
				: X(val1), Y(val2)
			{
			}



			Vector2D(const Vector2D<DataType>& other)
				: X(other.X), Y(other.Y)
			{
			}
			Vector2D(const Vector3D<DataType>& other)
				: X(other.X), Y(other.Y)
			{
			}
			Vector2D(const Vector4D<DataType>& other)
				: X(other.X), Y(other.Y)
			{
			}



			template <class OtherDataType>
			Vector2D<DataType>& operator=(const Vector2D<OtherDataType>& other)
			{
				this->X = other.X;
				this->Y = other.Y;
				return *this;
			}



			template <class OtherDataType>
			DataType& operator[](uint64 i)
			{
				return this->Values[i];
			}



			DataType GetMagnitude()
			{
				return std::sqrt((this->X * this->X) + (this->Y * this->Y));
			}
			DataType GetMagnitudeSquared()
			{
				return (this->X * this->X) + (this->Y * this->Y);
			}
			Vector2D<DataType>& Normalize()
			{
				DataType& invMag = DataType(1) / GetMagnitude();
				this->X *= invMag;
				this->Y *= invMag;
				return *this;
			}
			Vector2D<DataType>& Power(const DataType& exp)
			{
				this->X = std::pow(this->X, exp);
				this->Y = std::pow(this->Y, exp);
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& Power(const Vector2D<DataType>& exp)
			{
				this->X = std::pow(this->X, exp.X);
				this->Y = std::pow(this->Y, exp.Y);
				return *this;
			}



			template <class OtherDataType>
			Vector2D<DataType>& operator+=(const OtherDataType& other)
			{
				this->X += other;
				this->Y += other;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator+=(const Vector2D<OtherDataType>& other)
			{
				this->X += other.X;
				this->Y += other.Y;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator-=(const OtherDataType& other)
			{
				this->X -= other;
				this->Y -= other;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator-=(const Vector2D<OtherDataType>& other)
			{
				this->X -= other.X;
				this->Y -= other.Y;
				return *this;
			}



			template <class OtherDataType>
			Vector2D<DataType>& operator*=(const OtherDataType& other)
			{
				this->X *= other;
				this->Y *= other;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator*=(const Vector2D<OtherDataType>& other)
			{
				this->X *= other.X;
				this->Y *= other.Y;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator/=(const OtherDataType& other)
			{
				this->X /= other;
				this->Y /= other;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator/=(const Vector2D<OtherDataType>& other)
			{
				this->X /= other.X;
				this->Y /= other.Y;
				return *this;
			}



			Vector2D<DataType>& operator++()
			{
				this->X++;
				this->Y++;
				return *this;
			}
			Vector2D<DataType>& operator--()
			{
				this->X--;
				this->Y--;
				return *this;
			}



			template <class OtherDataType>
			Vector2D<DataType>& operator%=(const OtherDataType& other)
			{
				this->X %= other;
				this->Y %= other;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator%=(const Vector2D<OtherDataType>& other)
			{
				this->X %= other.X;
				this->Y %= other.Y;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator&=(const OtherDataType& other)
			{
				this->X &= other;
				this->Y &= other;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator&=(const Vector2D<OtherDataType>& other)
			{
				this->X &= other.X;
				this->Y &= other.Y;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator|=(const OtherDataType& other)
			{
				this->X |= other;
				this->Y |= other;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator|=(const Vector2D<OtherDataType>& other)
			{
				this->X |= other.X;
				this->Y |= other.Y;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator^=(const OtherDataType& other)
			{
				this->X ^= other;
				this->Y ^= other;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator^=(const Vector2D<OtherDataType>& other)
			{
				this->X ^= other.X;
				this->Y ^= other.Y;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator<<=(const OtherDataType& other)
			{
				this->X <<= other;
				this->Y <<= other;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator<<=(const Vector2D<OtherDataType>& other)
			{
				this->X <<= other.X;
				this->Y <<= other.Y;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator>>=(const OtherDataType& other)
			{
				this->X >>= other;
				this->Y >>= other;
				return *this;
			}
			template <class OtherDataType>
			Vector2D<DataType>& operator>>=(const Vector2D<OtherDataType>& other)
			{
				this->X >>= other.X;
				this->Y >>= other.Y;
				return *this;
			}
		};



		template <class DataType>
		Vector2D<DataType> operator+(const Vector2D<DataType>& value)
		{
			return value;
		}
		template <class DataType>
		Vector2D<DataType> operator-(const Vector2D<DataType>& value)
		{
			return Vector2D<DataType>(-value.X, -value.Y);
		}



		template <class DataType>
		Vector2D<DataType> operator+(const Vector2D<DataType>& value, const DataType& scalar)
		{
			return Vector2D<DataType>(value.X + scalar, value.Y + scalar);
		}
		template <class DataType>
		Vector2D<DataType> operator+(const DataType& scalar, const Vector2D<DataType>& value)
		{
			return Vector2D<DataType>(scalar + value.X, scalar + value.Y);
		}
		template <class DataType>
		Vector2D<DataType> operator+(const Vector2D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector2D<DataType>(value.X + other.X, value.Y + other.Y);
		}



		template <class DataType>
		Vector2D<DataType> operator-(const Vector2D<DataType>& value, const DataType& scalar)
		{
			return Vector3D<DataType>(value.X - scalar, value.Y - scalar);
		}
		template <class DataType>
		Vector2D<DataType> operator-(const DataType& scalar, const Vector2D<DataType>& value)
		{
			return Vector3D<DataType>(scalar - value.X, scalar - value.Y);
		}
		template <class DataType>
		Vector2D<DataType> operator-(const Vector2D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector2D<DataType>(value.X - other.X, value.Y - other.Y);
		}



		template <class DataType>
		Vector2D<DataType> operator*(const Vector2D<DataType>& value, const DataType& scalar)
		{
			return Vector2D<DataType>(value.X * scalar, value.Y * scalar);
		}
		template <class DataType>
		Vector2D<DataType> operator*(const DataType& scalar, const Vector2D<DataType>& value)
		{
			return Vector2D<DataType>(scalar * value.X, scalar * value.Y);
		}
		template <class DataType>
		Vector2D<DataType> operator*(const Vector2D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector2D<DataType>(value.X * other.X, value.Y * other.Y);
		}



		template <class DataType>
		Vector2D<DataType> operator/(const Vector2D<DataType>& value, const DataType& scalar)
		{
			return Vector2D<DataType>(value.X / scalar, value.Y / scalar);
		}
		template <class DataType>
		Vector2D<DataType> operator/(const DataType& scalar, const Vector2D<DataType>& value)
		{
			return Vector2D<DataType>(scalar / value.X, scalar / value.Y);
		}
		template <class DataType>
		Vector2D<DataType> operator/(const Vector2D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector2D<DataType>(value.X / other.X, value.Y / other.Y);
		}



		template <class DataType>
		Vector2D<DataType> operator%(const Vector2D<DataType>& value, const DataType& scalar)
		{
			return Vector2D<DataType>(value.X % scalar, value.Y % scalar);
		}
		template <class DataType>
		Vector2D<DataType> operator%(const DataType& scalar, const Vector2D<DataType>& value)
		{
			return Vector2D<DataType>(scalar % value.X, scalar % value.Y);
		}
		template <class DataType>
		Vector2D<DataType> operator%(const Vector2D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector2D<DataType>(value.X % other.X, value.Y % other.Y);
		}



		template <class DataType>
		Vector2D<DataType> operator&(const Vector2D<DataType>& value, const DataType& scalar)
		{
			return Vector2D<DataType>(value.X & scalar, value.Y & scalar);
		}
		template <class DataType>
		Vector2D<DataType> operator&(const DataType& scalar, const Vector2D<DataType>& value)
		{
			return Vector2D<DataType>(scalar & value.X, scalar & value.Y);
		}
		template <class DataType>
		Vector2D<DataType> operator&(const Vector2D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector2D<DataType>(value.X & other.X, value.Y & other.Y);
		}



		template <class DataType>
		Vector2D<DataType> operator|(const Vector2D<DataType>& value, const DataType& scalar)
		{
			return Vector2D<DataType>(value.X | scalar, value.Y | scalar);
		}
		template <class DataType>
		Vector2D<DataType> operator|(const DataType& scalar, const Vector2D<DataType>& value)
		{
			return Vector2D<DataType>(scalar | value.X, scalar | value.Y);
		}
		template <class DataType>
		Vector2D<DataType> operator|(const Vector2D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector2D<DataType>(value.X | other.X, value.Y | other.Y);
		}



		template <class DataType>
		Vector2D<DataType> operator^(const Vector2D<DataType>& value, const DataType& scalar)
		{
			return Vector2D<DataType>(value.X ^ scalar, value.Y ^ scalar);
		}
		template <class DataType>
		Vector2D<DataType> operator^(const DataType& scalar, const Vector2D<DataType>& value)
		{
			return Vector2D<DataType>(scalar ^ value.X, scalar ^ value.Y);
		}
		template <class DataType>
		Vector2D<DataType> operator^(const Vector2D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector2D<DataType>(value.X ^ other.X, value.Y ^ other.Y);
		}



		template <class DataType>
		Vector2D<DataType> operator<<(const Vector2D<DataType>& value, const DataType& scalar)
		{
			return Vector2D<DataType>(value.X << scalar, value.Y << scalar);
		}
		template <class DataType>
		Vector2D<DataType> operator<<(const DataType& scalar, const Vector2D<DataType>& value)
		{
			return Vector2D<DataType>(scalar << value.X, scalar << value.Y);
		}
		template <class DataType>
		Vector2D<DataType> operator<<(const Vector2D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector2D<DataType>(value.X << other.X, value.Y << other.Y);
		}



		template <class DataType>
		Vector2D<DataType> operator>>(const Vector2D<DataType>& value, const DataType& scalar)
		{
			return Vector2D<DataType>(value.X >> scalar, value.Y >> scalar);
		}
		template <class DataType>
		Vector2D<DataType> operator>>(const DataType& scalar, const Vector2D<DataType>& value)
		{
			return Vector2D<DataType>(scalar >> value.X, scalar >> value.Y);
		}
		template <class DataType>
		Vector2D<DataType> operator>>(const Vector2D<DataType>& value, const Vector2D<DataType>& other)
		{
			return Vector2D<DataType>(value.X >> other.X, value.Y >> other.Y);
		}



		template <class DataType>
		Vector2D<DataType> operator~(const Vector2D<DataType>& value)
		{
			return Vector2D<DataType>(~value.X, ~value.Y);
		}



		template <class DataType>
		bool operator==(const Vector2D<DataType>& value1, const Vector2D<DataType>& value2)
		{
			return value1.X == value2.X && value1.Y == value2.Y;
		}
		template <class DataType>
		bool operator!=(const Vector2D<DataType>& value1, const Vector2D<DataType>& value2)
		{
			return value1.X != value2.X || value1.Y != value2.Y;
		}



		template <class DataType>
		bool operator<(const Vector2D<DataType>& value1, const Vector2D<DataType>& value2)
		{
			return value1.X < value2.X && value1.Y < value2.Y;
		}
		template <class DataType>
		bool operator<=(const Vector2D<DataType>& value1, const Vector2D<DataType>& value2)
		{
			return value1.X <= value2.X && value1.Y <= value2.Y;
		}
		template <class DataType>
		bool operator>(const Vector2D<DataType>& value1, const Vector2D<DataType>& value2)
		{
			return value1.X > value2.X && value1.Y > value2.Y;
		}
		template <class DataType>
		bool operator>=(const Vector2D<DataType>& value1, const Vector2D<DataType>& value2)
		{
			return value1.X >= value2.X && value1.Y >= value2.Y;
		}



		template <class DataType>
		Vector2D<DataType> operator&&(const Vector2D<DataType>& value1, const Vector2D<DataType>& value2)
		{
			return Vector2D<DataType>(value1.X && value2.X, value1.Y && value2.Y);
		}
		template <class DataType>
		Vector2D<DataType> operator||(const Vector2D<DataType>& value1, const Vector2D<DataType>& value2)
		{
			return Vector2D<DataType>(value1.X || value2.X, value1.Y || value2.Y);
		}
	}
}