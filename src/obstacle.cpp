#include "obstacle.h"

#include "config.h"
#include "render.h"
#include "random.h"

namespace obstacle
{
	const int speed = 50;

	Obstacle init()
	{
		Obstacle obstacle;

		obstacle.collision.position = { config::gamespace.x + 5, config::gamespace.y / 2 };
		obstacle.collision.size = { 15, 15 };

		return obstacle;
	}

	void move(Obstacle& obstacle)
	{
		obstacle.collision.position.x -= speed * GetFrameTime();
	}

	void resetPosition(Obstacle& obstacle)
	{
		obstacle.collision.position.x = config::gamespace.x + 5;
		obstacle.collision.position.y = static_cast<float>(random::intRange(25, static_cast<int>(config::gamespace.y - 25)));
	}

	void draw(Obstacle obstacle)
	{
		render::rectangle(obstacle.collision, RED);
	}
}