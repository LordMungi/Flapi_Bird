#include "background.h"
#include "render.h"
#include "random.h"
#include "config.h"

namespace background
{
	static shape::Rectangle layer1;
	static shape::Rectangle layer2;
	static shape::Rectangle layer3;

	void init()
	{
		layer1.size = { 15, 70 };
		layer1.position = { 100, config::gamespace.y - layer1.size.y / 2 };

		layer2.size = { 20, 50 };
		layer2.position = { 100, config::gamespace.y - layer2.size.y / 2 };

		layer3.size = { 25, 25 };
		layer3.position = { 100, config::gamespace.y - layer3.size.y / 2 };

	}

	void update()
	{
		layer1.position.x -= 10 * GetFrameTime();
		if (layer1.position.x + layer1.size.x / 2 < 0)
			layer1.position.x = config::gamespace.x + layer1.size.x;

		layer2.position.x -= 15 * GetFrameTime();
		if (layer2.position.x + layer2.size.x / 2 < 0)
			layer2.position.x = config::gamespace.x + layer2.size.x;

		layer3.position.x -= 25 * GetFrameTime();
		if (layer3.position.x + layer3.size.x / 2 < 0)
			layer3.position.x = config::gamespace.x + layer3.size.x;
	}

	void draw()
	{
		render::rectangle(layer1, BLUE);
		render::rectangle(layer2, YELLOW);
		render::rectangle(layer3, GREEN);
	}
}