#pragma once
#include "Vector3ex.h"

//AABB
struct AABB final
{
	Vector3ex min; //最小値
	Vector3ex max; //最大値
};