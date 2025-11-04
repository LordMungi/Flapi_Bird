#include "game.h"

#include "bird.h"
#include "obstacle.h"
#include "collision.h"
#include "config.h"

namespace game
{
	screen::Type nextScreen;

	bird::Bird bird;
	obstacle::Obstacle obstacle;

	static void updateBird();
	static void updateObstacle();

	void init()
	{
		nextScreen = screen::Type::Game;

		bird = bird::init();
		obstacle = obstacle::init();
	}

	screen::Type update()
	{
		updateBird();
		updateObstacle();

		return nextScreen;
	}

	void draw()
	{
		bird::draw(bird);
		obstacle::draw(obstacle);
	}

	static void updateBird()
	{
		if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE))
			bird::jump(bird);

		if (IsKeyPressed(KEY_ESCAPE))
			nextScreen = screen::Type::Menu;

		if (coll::rectRect(bird.collision, obstacle.topCollision) || coll::rectRect(bird.collision, obstacle.bottomCollision))
			init();

		if (coll::rectRoof(bird.collision, 0))
			bird::bumpRoof(bird);

		if(coll::rectFloor(bird.collision, config::gamespace.y))
			init();

		bird::move(bird);
	}

	static void updateObstacle()
	{
		obstacle::move(obstacle);
		if (obstacle.topCollision.position.x + obstacle.topCollision.size.x / 2 < 0)
			obstacle::resetPosition(obstacle);
	}
}