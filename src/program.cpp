#include "program.h"

#include <iostream>
#include <ctime>

#include "render.h"
#include "game.h"

namespace program
{
	static void init();
	static void update();
	static void draw();
	static void close();
	
	void run()
	{
		init();

		while (!WindowShouldClose())
		{
			update();
			draw();
		}

		close();
	}

	static void init()
	{
		srand(static_cast<int>(time(0)));
		render::startWindow();
		game::init();
	}

	static void update()
	{
		game::update();
	}

	static void draw()
	{
		game::draw();
	}

	static void close()
	{
		render::closeWindow();
	}
}