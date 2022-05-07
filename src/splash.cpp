#include "splash.hpp"
#include "mainMenu.hpp"
#include <iostream>
#include "CONSTANTS.hpp"

Splash::Splash(Game *game) 
	:State(game)
{
}

void Splash::init()
{
	if (!tex.loadFromFile(cor::SPLASH_BACKGROUND))
	{
		//error
	}
	Background.setTexture(tex);
	
	if (!soundbuffer.loadFromFile(cor::SPLASH_BACKGROUND_SOUND))
	{
		std::cout << "Could not play sound\n";
	}
	backgroundMusic.setBuffer(soundbuffer);
	backgroundMusic.play();
}

void Splash::update(float dt, sf::RenderWindow &win)
{
	if (splashTime.getElapsedTime().asSeconds() > soundbuffer.getDuration().asSeconds())
	{
		this->changeState(std::make_shared<MainMenu>(MainMenu(game)));
		std::cout << "go to menu\n";
	}
	Background.setScale(win.getSize().x / Background.getLocalBounds().width,
		win.getSize().y / Background.getLocalBounds().height);
}

void Splash::draw(sf::RenderWindow &win)
{
	win.draw(Background);
}

void Splash::handleEvent(sf::RenderWindow &win, sf::Event &event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		backgroundMusic.stop();
		this->changeState(std::make_shared<MainMenu>(MainMenu(game)));
		std::cout << "go to menu\n";
	}
	switch (event.key.code)
	{
		case sf::Keyboard::Enter:
			backgroundMusic.stop();
			this->changeState(std::make_shared<MainMenu>(MainMenu(game)));
			break;
		case sf::Keyboard::Space:
			backgroundMusic.stop();
			this->changeState(std::make_shared<MainMenu>(MainMenu(game)));
			break;
		default:
			break;
	}
}
