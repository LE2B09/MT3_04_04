#ifndef MATHFUNCTION_H
#define MATHFUNCTION_H

#define NOMINMAX
#include "AABB.h"
#include "Ball.h"
#include "Math/Vector3ex.h"
#include "Math/Matrix4x4ex.h"
#include "Vector4.h"
#include "Segment.h"
#include "Sphereh.h"
#include "Plane.h"
#include "Triangle.h"
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <corecrt_math_defines.h>

/// <summary>
/// ベクトルと行列を合わせたクラス
/// </summary>
class MathFunction
{
public:
	/*----------Vector4型の関数---------*/

	Vector4 Multiply(const Vector4& v, const Matrix4x4ex& m);


	/*----------Vector3型の関数----------*/

	/// <summary>
	/// 加算
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	Vector3ex Add(const Vector3ex& v1, const Vector3ex& v2);
	/// <summary>
	/// 減算
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	Vector3ex Subtract(const Vector3ex& v1, const Vector3ex& v2);
	/// <summary>
	/// スカラー
	/// </summary>
	/// <param name="scalar"></param>
	/// <param name="v"></param>
	/// <returns></returns>
	Vector3ex Multiply(float scalar, const Vector3ex& v);
	/// <summary>
	/// 内積
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	float Dot(const Vector3ex& v1, const Vector3ex& v2);
	/// <summary>
	/// 長さ（ノルム）
	/// </summary>
	/// <param name="v"></param>
	/// <returns></returns>
	float Length(const Vector3ex& v);
	/// <summary>
	/// 正規化
	/// </summary>
	/// <param name="v"></param>
	/// <returns></returns>
	Vector3ex Normalize(const Vector3ex& v);
	/// <summary>
	/// 座標変換
	/// </summary>
	/// <param name="vector"></param>
	/// <param name="matrix"></param>
	/// <returns></returns>
	Vector3ex Transform(const Vector3ex& vector, const Matrix4x4ex& matrix);
	/// <summary>
	/// クロス積
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	Vector3ex Cross(const Vector3ex& v1, const Vector3ex& v2);
	/// <summary>
	/// ベクトル射影
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	Vector3ex Project(const Vector3ex& v1, const Vector3ex& v2);
	/// <summary>
	/// 最近接点
	/// </summary>
	/// <param name="point"></param>
	/// <param name="segment"></param>
	/// <returns></returns>
	Vector3ex ClosestPoint(const Vector3ex& point, const Segment& segment);
	/// <summary>
	/// 与えられたベクトルに垂直なベクトルを計算
	/// </summary>
	/// <param name="vector"></param>
	/// <returns></returns>
	Vector3ex Perpendicular(const Vector3ex& vector);
	/// <summary>
	/// 線形補間
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <param name="t"></param>
	/// <returns></returns>
	Vector3ex Lerp(const Vector3ex& v1, const Vector3ex& v2, float t);
	/// <summary>
	/// 3D座標を2Dスクリーン座標に変換する関数
	/// </summary>
	/// <param name="point"></param>
	/// <param name="viewProjectionMatrix"></param>
	/// <param name="viewportMatrix"></param>
	/// <returns></returns>
	Vector3ex ProjectToScreen(const Vector3ex& point, const Matrix4x4ex& viewProjectionMatrix, const Matrix4x4ex& viewportMatrix);
	/// <summary>
	/// 反射ベクトルを求める関数
	/// </summary>
	/// <param name="input">入射ベクトル</param>
	/// <param name="normal">法線</param>
	/// <returns></returns>
	Vector3ex Reflect(const Vector3ex& input, const Vector3ex& normal);

	/*----------Matrix型の関数----------*/

	/// <summary>
	/// 加算行列
	/// </summary>
	/// <param name="m1"></param>
	/// <param name="m2"></param>
	/// <returns></returns>
	Matrix4x4ex Add(const Matrix4x4ex& m1, const Matrix4x4ex& m2);
	/// <summary>
	/// 減算行列
	/// </summary>
	/// <param name="m1"></param>
	/// <param name="m2"></param>
	/// <returns></returns>
	Matrix4x4ex Subtract(const Matrix4x4ex& m1, const Matrix4x4ex& m2);
	/// <summary>
	/// 乗算行列
	/// </summary>
	/// <param name="m1"></param>
	/// <param name="m2"></param>
	/// <returns></returns>
	Matrix4x4ex Multiply(const Matrix4x4ex& m1, const Matrix4x4ex& m2);
	/// <summary>
	/// 逆行列
	/// </summary>
	/// <param name="matrix"></param>
	/// <returns></returns>
	Matrix4x4ex Inverse(const Matrix4x4ex& matrix);
	/// <summary>
	/// 転置行列
	/// </summary>
	/// <param name="m"></param>
	/// <returns></returns>
	Matrix4x4ex Transpose(const Matrix4x4ex& m);
	/// <summary>
	/// 単位行列
	/// </summary>
	/// <returns></returns>
	Matrix4x4ex MakeIdentity();
	/// <summary>
	/// スケーリング行列
	/// </summary>
	/// <param name="scale"></param>
	/// <returns></returns>
	Matrix4x4ex MakeScaleMatrix(const Vector3ex& scale);
	/// <summary>
	/// X軸の回転行列
	/// </summary>
	/// <param name="radian"></param>
	/// <returns></returns>
	Matrix4x4ex MakeRotateXMatrix(float radian);
	/// <summary>
	/// Yの回転行列
	/// </summary>
	/// <param name="radian"></param>
	/// <returns></returns>
	Matrix4x4ex MakeRotateYMatrix(float radian);
	/// <summary>
	/// Zの回転行列
	/// </summary>
	/// <param name="radian"></param>
	/// <returns></returns>
	Matrix4x4ex MakeRotateZMatrix(float radian);
	/// <summary>
	/// 平行移動行列 
	/// </summary>
	/// <param name="translate"></param>
	/// <returns></returns>
	Matrix4x4ex MakeTranslateMatrix(const Vector3ex& translate);
	/// <summary>
	/// アフィン変換行列
	/// </summary>
	/// <param name="scale"></param>
	/// <param name="radian"></param>
	/// <param name="translate"></param>
	/// <returns></returns>
	Matrix4x4ex MakeAffineMatrix(const Vector3ex& scale, const Vector3ex& radian, const Vector3ex& translate);
	/// <summary>
	/// 透視投影行列
	/// </summary>
	/// <param name="fovY"></param>
	/// <param name="aspectRatio"></param>
	/// <param name="nearClip"></param>
	/// <param name="farClip"></param>
	/// <returns></returns>
	Matrix4x4ex MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
	/// <summary>
	/// 正射影行列
	/// </summary>
	/// <param name="left"></param>
	/// <param name="top"></param>
	/// <param name="right"></param>
	/// <param name="bottom"></param>
	/// <param name="nearClip"></param>
	/// <param name="farClip"></param>
	/// <returns></returns>
	Matrix4x4ex MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
	/// <summary>
	/// ビュー行列
	/// </summary>
	/// <param name="left"></param>
	/// <param name="top"></param>
	/// <param name="width"></param>
	/// <param name="height"></param>
	/// <param name="minDepth"></param>
	/// <param name="maxDepth"></param>
	/// <returns></returns>
	Matrix4x4ex MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

	/*----------立体を描画する関数----------*/

	/// <summary>
	/// グリッドを描画
	/// </summary>
	/// <param name="ViewProjectionMatrix"></param>
	/// <param name="ViewportMatrix"></param>
	void DrawGrid(const Matrix4x4ex& ViewProjectionMatrix, const Matrix4x4ex& ViewportMatrix);
	/// <summary>
	/// 球体を描画
	/// </summary>
	/// <param name="sphere"></param>
	/// <param name="viewProjectionMatrix"></param>
	/// <param name="viewportMatrix"></param>
	/// <param name="color"></param>
	void DrawSphere(const Sphere& sphere, const Matrix4x4ex& viewProjectionMatrix, const Matrix4x4ex& viewportMatrix, uint32_t color);
	/// <summary>
	/// 平面を描画
	/// </summary>
	/// <param name="plane"></param>
	/// <param name="viewProjectionMatrix"></param>
	/// <param name="viewportMatrix"></param>
	/// <param name="color"></param>
	void DrawPlane(const Plane& plane, const Matrix4x4ex& viewProjectionMatrix, const Matrix4x4ex& viewportMatrix, uint32_t color);
	/// <summary>
	/// 三角形を描画
	/// </summary>
	/// <param name="triangle"></param>
	/// <param name="viewProjectionMatrix"></param>
	/// <param name="viewportMatrix"></param>
	/// <param name="color"></param>
	void DrawTriangle(const Triangle& triangle, const Matrix4x4ex& viewProjectionMatrix, const Matrix4x4ex& viewportMatrix, uint32_t color);
	/// <summary>
	/// AABBを描画
	/// </summary>
	/// <param name="aabb"></param>
	/// <param name="viewProjectionMatrix"></param>
	/// <param name="viewportMatrix"></param>
	/// <param name="color"></param>
	void DrawAABB(const AABB& aabb, const Matrix4x4ex& viewProjectionMatrix, const Matrix4x4ex& viewportMatrix, uint32_t color);
	/// <summary>
	/// ベジエ曲線を描画
	/// </summary>
	/// <param name="controlPoint0"></param>
	/// <param name="controlPoint1"></param>
	/// <param name="controlPoint2"></param>
	/// <param name="viewProjection"></param>
	/// <param name="viewportMatrix"></param>
	/// <param name="color"></param>
	void DrawBezier(const Vector3ex& controlPoint0, const Vector3ex& controlPoint1, const Vector3ex& controlPoint2, const Matrix4x4ex& viewProjection, const Matrix4x4ex& viewportMatrix, uint32_t color);
	/// <summary>
	/// ベジエ曲線の制御点を描画
	/// </summary>
	/// <param name="controlPoint"></param>
	/// <param name="viewProjection"></param>
	/// <param name="viewportMatrix"></param>
	void DrawControlPoint(const Vector3ex& controlPoint, const Matrix4x4ex& viewProjection, const Matrix4x4ex& viewportMatrix);

	/*----------衝突判定を取る関数----------*/

	/// <summary>
	/// 球と球の衝突判定
	/// </summary>
	/// <param name="s1">球１</param>
	/// <param name="s2">球２</param>
	/// <returns></returns>
	bool IsCollision(const Sphere& s1, const Sphere& s2);
	/// <summary>
	/// 球と平面の衝突判定
	/// </summary>
	/// <param name="sphere">球</param>
	/// <param name="plane">平面</param>
	/// <returns></returns>
	bool IsCollision(const Sphere& sphere, const Plane& plane);
	/// <summary>
	/// 線と平面の衝突判定
	/// </summary>
	/// <param name="segment">セグメント</param>
	/// <param name="plane">平面</param>
	/// <returns></returns>
	bool IsCollision(const Segment& segment, const Plane& plane);
	/// <summary>
	/// 三角形と線の衝突判定
	/// </summary>
	/// <param name="triangle">三角形</param>
	/// <param name="segment">セグメント</param>
	/// <returns></returns>
	bool IsCollision(const Triangle& triangle, const Segment& segment);
	/// <summary>
	/// AABBとAABBの衝突判定
	/// </summary>
	/// <param name="aabb1">AABB1</param>
	/// <param name="aabb2">AABB2</param>
	/// <returns></returns>
	bool IsCollision(const AABB& aabb1, const AABB& aabb2);
	/// <summary>
	/// AABBと球の衝突判定
	/// </summary>
	/// <param name="aabb">AABB</param>
	/// <param name="sphere">球</param>
	/// <returns></returns>
	bool IsCollision(const AABB& aabb, const Sphere& sphere);
	/// <summary>
	/// AABBと線の衝突判定
	/// </summary>
	/// <param name="aabb">AABB</param>
	/// <param name="segment">セグメント</param>
	/// <returns></returns>
	bool IsCollision(const AABB& aabb, const Segment& segment);
};
#endif // MATHFUNCTION_H