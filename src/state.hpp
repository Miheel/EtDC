#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "game.hpp"

class State
{
public:
	State(Game *game) :game(game) {}
	virtual ~State() = default;

	virtual void init() = 0;
	virtual void update(float dt, sf::RenderWindow &win) = 0;
	virtual void draw(sf::RenderWindow &win) = 0;

	virtual void handleEvent(sf::RenderWindow &win, sf::Event &event) = 0;
	void changeState(std::shared_ptr<State> state) {
		game->changeState(state);
	}
	virtual void pause() = 0;
	virtual void resume() = 0;

protected:
	Game *game;
};

#endif // !STATE_HPP
