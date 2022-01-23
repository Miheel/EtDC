#include "mainMenu.hpp"
#include <iostream>
#include "adventure.hpp"
#include "optMenu.h"
#include "CONSTANTS.hpp"

MainMenu::MainMenu(Game *game)
	:State(game)
{
}

void MainMenu::init()
{
	if (!backTex.loadFromFile(cor::MENU_BACKGROUND))
		std::cerr << "Background not loaded\n";
	else
	{
		backSrite.setTexture(backTex);
		backSrite.setPosition(0, 0);
	}
	if (!font.loadFromFile(cor::MENU_FONT))
		std::cerr << "Font not loaded\n";

	for (size_t i = 0; i < cor::MENU_OPT_NAMES.size(); i++)
	{
		btns.push_back(MenuItem(cor::MENU_OPT_NAMES[i], font, sf::Vector2f(200, 75), sf::Color::Blue));
	}
}

void MainMenu::update(float dt, sf::RenderWindow &win)
{
	backSrite.setScale(win.getSize().x / backSrite.getLocalBounds().width,
		win.getSize().y / backSrite.getLocalBounds().height);

	int i = 1;
	for (auto IT = btns.begin(); IT != btns.end(); IT++, i++)
	{
		(*IT).setPosition(win.getSize().x / 2.f, 100.f * i);
	}
}

void MainMenu::draw(sf::RenderWindow &win)
{
	win.draw(backSrite);
	for (auto e : btns)
	{
		win.draw(e);
	}
}

void MainMenu::handleEvent(sf::RenderWindow &win, sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			//game btn
			if (btns[0].contains(event.mouseButton))
			{
				std::cout << "Switch to game\n";
				game->changeState(std::make_shared<Adventure>(Adventure(game)));
			}
			//opt btn
			else if (btns[1].contains(event.mouseButton))
			{
				std::cout << "Switch to option\n";
				//game->changeState(std::make_shared<OptMenu>(OptMenu(game)));
			}
			//quit btn
			else if (btns[2].contains(event.mouseButton))
			{
				std::cout << "Quitting game\n";
				win.close();
			}
		}
	}
}

void MainMenu::pause()
{
}

void MainMenu::resume()
{
}
