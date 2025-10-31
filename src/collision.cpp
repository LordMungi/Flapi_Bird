#include "collision.h"

namespace coll
{
	bool rectRect(shape::Rectangle rect1, shape::Rectangle rect2)
	{
		return rect1.position.x + rect1.size.x / 2 > rect2.position.x - rect2.size.x / 2 &&
			rect1.position.x - rect1.size.x / 2 < rect2.position.x + rect2.size.x / 2 &&
			rect1.position.y + rect1.size.y / 2 > rect2.position.y - rect2.size.y / 2 &&
			rect1.position.y - rect1.size.y / 2 < rect2.position.y + rect2.size.y / 2;
	}
}