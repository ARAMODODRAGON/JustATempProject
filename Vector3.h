#ifndef VECTOR2_H
#define VECTOR2_H

class Vector3 {
private:
public:
	float X, Y, Z;

	Vector3(float value = 0.0f);
	Vector3(float X, float Y, float Z);

	inline Vector3 operator*(const float& scalar) {
		return Vector3(X * scalar, Y * scalar, Z * scalar);
	}
	inline Vector3 operator/(const float& divisor) {
		return Vector3(X / divisor, Y / divisor, Z / divisor);
	}
	inline Vector3 operator+(const Vector3& vec) {
		return Vector3(X + vec.X, Y + vec.Y, Z + vec.Z);
	}
	inline Vector3 operator-(const Vector3& vec) {
		return Vector3(X - vec.X, Y - vec.Y, Z - vec.Z);
	}
	inline Vector3& operator+=(const Vector3& vec) {
		X += vec.X; Y += vec.Y; Z += vec.Z;
		return *this;
	}
	inline Vector3& operator-=(const Vector3& vec) {
		X -= vec.X; Y -= vec.Y; Z -= vec.Z;
		return *this;
	}

	static float Dot(const Vector3& vecA, const Vector3& vecB);

	static const Vector3 Forward;
	static const Vector3 Back;
	static const Vector3 Left;
	static const Vector3 Right;
	static const Vector3 Up;
	static const Vector3 Down;
	static const Vector3 Zero;
	static const Vector3 One;
};


#endif // !VECTOR2_H