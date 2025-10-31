#pragma once
#include "shapes.h"

namespace coll
{
	bool rectRect(shape::Rectangle rect1, shape::Rectangle rect2);
	bool rectRoof(shape::Rectangle rect, float roof);
	bool rectFloor(shape::Rectangle rect, float floor);
}