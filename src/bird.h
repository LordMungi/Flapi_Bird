#pragma once
#include "shapes.h"

namespace bird
{
	struct Bird
	{
		shape::Rectangle collision;
		int direction;
	};

	Bird init();

	void move();
	void draw();
}