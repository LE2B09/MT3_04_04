#pragma once
#include "Vector3ex.h"

//線分
struct Segment final
{
	Vector3ex origin;      //始点
	Vector3ex diff;        //終点からの差分
};
