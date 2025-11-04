#include "menu.h"

#include "config.h"
#include "button.h"
#include "label.h"

namespace menu
{
	screen::Type nextScreen;

	enum class Options
	{
		Play,
		Credits,
		Exit,
		Last
	};
	const int maxButtons = static_cast<int>(Options::Last);

	button::Button buttons[maxButtons];

	label::Label versionLabel;

	void init()
	{
		nextScreen = screen::Type::Menu;

		shape::Rectangle shape;
		shape.position = { config::gamespace.x / 2, config::gamespace.y / 2 };
		shape.size = { 50, 10 };
		float separation = 5;

		buttons[static_cast<int>(Options::Play)] = button::init(shape, "Play");
		shape.position.y += shape.size.y + separation;

		buttons[static_cast<int>(Options::Credits)] = button::init(shape, "Credits");
		shape.position.y += shape.size.y + separation;

		buttons[static_cast<int>(Options::Exit)] = button::init(shape, "Exit");

		versionLabel = label::init("version 0.2", { {5, 95},{5, 5} }, render::TextAlign::Left, WHITE);
	}

	screen::Type update()
	{
		if (button::update(buttons[static_cast<int>(Options::Play)]))
			nextScreen = screen::Type::Game;
		if (button::update(buttons[static_cast<int>(Options::Credits)]))
			nextScreen = screen::Type::Credits;
		if (button::update(buttons[static_cast<int>(Options::Exit)]))
			nextScreen = screen::Type::Null;

		return nextScreen;
	}

	void draw()
	{
		for (int i = 0; i < maxButtons; i++)
			button::draw(buttons[i]);

		label::draw(versionLabel);
	}
}