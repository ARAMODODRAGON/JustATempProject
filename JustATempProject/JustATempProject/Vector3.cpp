#include "Vector3.h"

const Vector3 Vector3::Forward = Vector3(0.0f, 0.0f, -1.0f);
const Vector3 Vector3::Back = Vector3(0.0f, 0.0f, 1.0f);
const Vector3 Vector3::Left = Vector3(-1.0f, 0.0f, 0.0f);
const Vector3 Vector3::Right = Vector3(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::Up = Vector3(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::Down = Vector3(0.0f, -1.0f, 0.0f);
const Vector3 Vector3::Zero = Vector3(0.0f);
const Vector3 Vector3::One = Vector3(1.0f);

Vector3::Vector3(float value) : X(value), Y(value), Z(value) {}

Vector3::Vector3(float X_, float Y_, float Z_) : X(X_), Y(Y_), Z(Z_) {}

float Vector3::Dot(const Vector3& vecA, const Vector3& vecB) {
	return vecA.X * vecB.X + vecA.Y * vecB.Y + vecA.Z * vecB.Z;
}
