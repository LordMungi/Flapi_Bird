#include "program.h"

#include <raylib.h>

#include "render.h"

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
	}

	static void init()
	{
		render::startWindow();
	}

	static void update()
	{

	}

	static void draw()
	{

	}

	static void close()
	{
		render::closeWindow();
	}
}