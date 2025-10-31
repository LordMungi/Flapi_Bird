#include "game.h"

#include "bird.h"
#include "obstacle.h"
#include "collision.h"

namespace game
{
	bird::Bird bird;
	obstacle::Obstacle obstacle;

	static void updateBird();
	static void updateObstacle();

	void init()
	{
		bird = bird::init();
		obstacle = obstacle::init();
	}

	void update()
	{
		updateBird();
		updateObstacle();
	}

	void draw()
	{
		bird::draw(bird);
		obstacle::draw(obstacle);
	}

	static void updateBird()
	{
		if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
			bird::jump(bird);

		if (coll::rectRect(bird.collision, obstacle.collision))
			init();

		bird::move(bird);
	}

	static void updateObstacle()
	{
		obstacle::move(obstacle);
		if (obstacle.collision.position.x + obstacle.collision.size.x / 2 < 0)
			obstacle::resetPosition(obstacle);
	}
}