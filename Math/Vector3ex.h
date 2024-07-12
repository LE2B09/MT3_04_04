#pragma once

/// <summary>
/// 3次元ベクトル
/// </summary>
class Vector3ex
{
public:
	float x, y, z;

	Vector3ex();
	Vector3ex(float x, float y, float z);
	Vector3ex operator-() const;
	Vector3ex operator+() const;
	Vector3ex& operator+=(const Vector3ex& other);
	Vector3ex& operator-=(const Vector3ex& other);
	Vector3ex& operator*=(float s);
	Vector3ex& operator/=(float s);

	friend Vector3ex operator+(const Vector3ex& v1, const Vector3ex& v2);
	friend Vector3ex operator-(const Vector3ex& v1, const Vector3ex& v2);
	friend Vector3ex operator*(const Vector3ex& v1, const Vector3ex& v2);
	friend Vector3ex operator*(const Vector3ex& v, float s);
	friend Vector3ex operator*(float s, const Vector3ex& v);
	friend Vector3ex operator/(const Vector3ex& v, float s);
};