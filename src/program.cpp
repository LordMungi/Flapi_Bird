#include "program.h"

#include <iostream>
#include <ctime>

#include "render.h"
#include "game.h"
#include "label.h"

namespace program
{
	static void init();
	static void update();
	static void draw();
	static void close();

	label::Label versionLabel;
	
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
		versionLabel = label::init("version 0.1", { {5, 95},{5, 5} }, render::TextAlign::Left, WHITE);
	}

	static void update()
	{
		game::update();
	}

	static void draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		game::draw();
		label::draw(versionLabel);

		EndDrawing();
	}

	static void close()
	{
		render::closeWindow();
	}
}