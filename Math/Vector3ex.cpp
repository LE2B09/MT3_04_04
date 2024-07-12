#include "Vector3ex.h"

Vector3ex::Vector3ex() : x(0), y(0), z(0) {}

Vector3ex::Vector3ex(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3ex Vector3ex::operator-() const { return Vector3ex(-x, -y, -z); }

Vector3ex Vector3ex::operator+() const { return *this; }

Vector3ex& Vector3ex::operator+=(const Vector3ex& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3ex& Vector3ex::operator-=(const Vector3ex& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3ex& Vector3ex::operator*=(float s) {
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

Vector3ex& Vector3ex::operator/=(float s) {
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

Vector3ex operator+(const Vector3ex& v1, const Vector3ex& v2) { return Vector3ex(v1) += v2; }

Vector3ex operator-(const Vector3ex& v1, const Vector3ex& v2) { return Vector3ex(v1) -= v2; }

Vector3ex operator*(const Vector3ex& v1, const Vector3ex& v2) { return Vector3ex(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z); }

Vector3ex operator*(const Vector3ex& v, float s) { return Vector3ex(v) *= s; }

Vector3ex operator*(float s, const Vector3ex& v) { return v * s; }

Vector3ex operator/(const Vector3ex& v, float s) { return Vector3ex(v) /= s; }