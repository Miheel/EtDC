#include "game.hpp"
#include "state.hpp"
#include "spash.hpp"
#include <iostream>

Game::Game(sf::VideoMode mode, const sf::String &title) 
	:win(mode, title)
{
	//first state;
	this->pushState(std::make_shared<Splash>(Splash(this)));

	win.setFramerateLimit(60);
}

void Game::update()
{
	states.back()->update(gameTime.restart().asSeconds(), win);
}

void Game::draw()
{
	win.clear();
	states.back()->draw(win);
	win.display();
}

void Game::handleEvent()
{
	sf::Event event;

	while (win.pollEvent(event))
	{
		if (event.type == sf::Event::Resized)
		{
			sf::FloatRect newView(0.f, 0.f, (float)event.size.width, (float)event.size.height);
			win.setView(sf::View(newView));
		}
		if (event.type == sf::Event::Closed)
		{
			win.close();
		}
		states.back()->handleEvent(win, event);
	}
}

void Game::changeState(std::shared_ptr<State> state)
{
	if (!states.empty())
	{
		states.pop_back();
	}
	states.push_back(state);
	states.back()->init();
}

void Game::pushState(std::shared_ptr<State> state)
{
	if (!states.empty())
	{
		states.back()->pause();
	}
	states.push_back(state);
	states.back()->init();
}

void Game::popState()
{
	if (!states.empty())
	{
		states.pop_back();
		states.back()->resume();
	}
}

bool Game::isrunning()
{
	return win.isOpen();
}
