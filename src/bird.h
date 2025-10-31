#pragma once
#include "shapes.h"

namespace bird
{
	struct Bird
	{
		shape::Rectangle collision;
		int direction;
		int speed;
	};

	Bird init();

	void move(Bird& bird);
	void draw(Bird bird);
}