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
		BeginDrawing();
		ClearBackground(BLACK);

		bird::draw(bird);
		obstacle::draw(obstacle);

		EndDrawing();
	}

	static void updateBird()
	{
		bird.direction = 0;
		if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
			bird.direction = -1;
		if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
			bird.direction = 1;

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