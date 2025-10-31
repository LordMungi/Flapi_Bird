#include "game.h"

#include "bird.h"
#include "obstacle.h"

namespace game
{
	bird::Bird bird;
	obstacle::Obstacle obstacle;

	void init()
	{
		bird = bird::init();
		obstacle = obstacle::init();
	}

	void update()
	{
		bird::move(bird);
		obstacle::move(obstacle);
	}

	void draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		bird::draw(bird);
		obstacle::draw(obstacle);

		EndDrawing();
	}
}