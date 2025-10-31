#pragma once
#include "shapes.h"

namespace obstacle
{
	struct Obstacle
	{
		shape::Rectangle collision;
	};

	Obstacle init();

	void move();
	void draw();
}
