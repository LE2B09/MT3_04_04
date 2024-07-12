#pragma once

/// <summary>
/// 4x4行列
/// </summary>
class Matrix4x4ex 
{
public:
	float m[4][4];

	// デフォルトコンストラクタ
	Matrix4x4ex();

	// 指定された値で初期化するコンストラクタ
	Matrix4x4ex(float elements[4][4]);

	Matrix4x4ex& operator+=(const Matrix4x4ex& other);
	Matrix4x4ex& operator-=(const Matrix4x4ex& other);
	Matrix4x4ex& operator*=(const Matrix4x4ex& other);

	friend Matrix4x4ex operator+(const Matrix4x4ex& m1, const Matrix4x4ex& m2);
	friend Matrix4x4ex operator-(const Matrix4x4ex& m1, const Matrix4x4ex& m2);
	friend Matrix4x4ex operator*(const Matrix4x4ex& m1, const Matrix4x4ex& m2);
};