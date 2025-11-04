#include "program.h"

#include <iostream>
#include <ctime>

#include "render.h"
#include "game.h"
#include "menu.h"

namespace program
{
	static void init();
	static void update();
	static void changeScreen();
	static void draw();
	static void close();

	screen::Type currentScreen = screen::Type::Null;
	screen::Type previousScreen = screen::Type::Null;
		
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

		currentScreen = screen::Type::Menu;
	}

	static void update()
	{
		switch (currentScreen)
		{
		case screen::Type::Menu:
			currentScreen = menu::update();
			break;
		case screen::Type::Game:
			currentScreen = game::update();
			break;
		case screen::Type::Credits:
			break;
		case screen::Type::Null:
			close();
			break;
		}

		if (currentScreen != previousScreen)
			changeScreen();
	}


	static void changeScreen()
	{
		switch (currentScreen)
		{
		case screen::Type::Menu:
			menu::init();
			break;
		case screen::Type::Game:
			game::init();
			break;
		case screen::Type::Credits:
			break;
		}

		previousScreen = currentScreen;
	}

	static void draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		switch (currentScreen)
		{
		case screen::Type::Menu:
			menu::draw();
			break;
		case screen::Type::Game:
			game::draw();
			break;
		case screen::Type::Credits:
			break;
		}


		EndDrawing();
	}

	static void close()
	{
		render::closeWindow();
	}

}