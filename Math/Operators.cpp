#include "Matrix4x4ex.h"
#include "Vector3ex.h"



// デフォルトコンストラクタ: 0で初期化
Matrix4x4ex::Matrix4x4ex() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m[i][j] = 0.0f;
		}
	}
}

// 指定された値で初期化するコンストラクタ
Matrix4x4ex::Matrix4x4ex(float elements[4][4]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m[i][j] = elements[i][j];
		}
	}
}

Matrix4x4ex& Matrix4x4ex::operator+=(const Matrix4x4ex& other) {
	// 加算の実装
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			m[i][j] += other.m[i][j];
	return *this;
}

Matrix4x4ex& Matrix4x4ex::operator-=(const Matrix4x4ex& other) {
	// 減算の実装
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			m[i][j] -= other.m[i][j];
	return *this;
}

Matrix4x4ex& Matrix4x4ex::operator*=(const Matrix4x4ex& other) {
	// 乗算の実装
	Matrix4x4ex result;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result.m[i][j] = 0;
			for (int k = 0; k < 4; ++k) {
				result.m[i][j] += m[i][k] * other.m[k][j];
			}
		}
	}
	*this = result;
	return *this;
}

Matrix4x4ex operator+(const Matrix4x4ex& m1, const Matrix4x4ex& m2) {
	Matrix4x4ex result = m1;
	result += m2;
	return result;
}

Matrix4x4ex operator-(const Matrix4x4ex& m1, const Matrix4x4ex& m2) {
	Matrix4x4ex result = m1;
	result -= m2;
	return result;
}

Matrix4x4ex operator*(const Matrix4x4ex& m1, const Matrix4x4ex& m2) {
	Matrix4x4ex result = m1;
	result *= m2;
	return result;
}

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