#include "endGame.hpp"
#include "mainMenu.hpp"
#include "CONSTANTS.hpp"

EndGame::EndGame(Game * game)
	:State(game)
{	
	Message.setString("Not set");
}

void EndGame::setMessage(std::string message)
{
	Message.setString(message);
}

void EndGame::init()
{
	font.loadFromFile(cor::MENU_FONT);
	Message.setFont(font);

	Message.setCharacterSize(70);
	Message.setOrigin(Message.getLocalBounds().left + Message.getLocalBounds().width / 2.f,
		Message.getLocalBounds().top + Message.getLocalBounds().height / 2.f);
}

void EndGame::update(float dt, sf::RenderWindow & win)
{
	Message.setPosition(win.getSize().x / 2.f, win.getSize().y / 2.f);
}

void EndGame::draw(sf::RenderWindow & win)
{
	win.draw(Message);
}

void EndGame::handleEvent(sf::RenderWindow & win, sf::Event & event)
{
	if (time.getElapsedTime().asSeconds() > 5)
	{
		this->changeState(std::make_shared<MainMenu>(MainMenu(game)));
	}
}
