#include "bird.h"

#include "config.h"
#include "render.h"

namespace bird
{
	Bird init()
	{
		Bird bird;
		
		bird.collision.position = { 20, config::gamespace.y / 2 };
		bird.collision.size = { 8, 8 };
		bird.direction = 0;
		bird.speed = 100;

		return bird;
	}

	void move(Bird& bird)
	{
		bird.collision.position.y += bird.direction * bird.speed * GetFrameTime();
	}

	void draw(Bird bird)
	{
		render::rectangle(bird.collision, WHITE);
	}
}