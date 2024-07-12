#pragma once
#include "Vector3ex.h"

/// <summary>
/// ボールの構造体
/// </summary>
struct Ball final
{
	Vector3ex position;           // ボールの位置
	Vector3ex velocity;           // ボールの速度
	Vector3ex acceleration;       // ボールの加速度
	float mass;                 // ボールの質量
	float radius;               // ボールの半径
	unsigned int color;         // ボールの色
};