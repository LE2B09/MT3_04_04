#pragma once
#include "Vector3ex.h"

//平面
struct Plane final
{
	Vector3ex normal;		//!< 法線
	float distance;		//!< 距離
};
