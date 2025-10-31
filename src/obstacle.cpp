#include "obstacle.h"

#include "config.h"
#include "render.h"

namespace obstacle
{
	const int speed = 50;

	Obstacle init()
	{
		Obstacle obstacle;

		obstacle.collision.position = { config::gamespace.x / 2, config::gamespace.y - 25 };
		obstacle.collision.size = { 10, 50 };
	}

	void move(Obstacle& obstacle)
	{
		obstacle.collision.position.x -= speed * GetFrameTime();
	}

	void draw(Obstacle obstacle)
	{
		render::rectangle(obstacle.collision, RED);
	}
}