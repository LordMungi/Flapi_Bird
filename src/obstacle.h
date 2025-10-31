#pragma once
#include "shapes.h"

namespace obstacle
{
	struct Obstacle
	{
		shape::Rectangle collision;
	};

	Obstacle init();

	void move(Obstacle& obstacle);
	void resetPosition(Obstacle& obstacle);

	void draw(Obstacle obstacle);
}
