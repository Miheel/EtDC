#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "game.hpp"

/**
* @brief base state class with pure virtual funktions and funktions to manage a game state
*/
class State
{
public:

	State() = default;

	/**
	* @brief Constructor 
	* @param game pointer to Game class
	*/
	State(Game *game) :game(game) {}

	/**
	* @brief Default destructor
	*/
	virtual ~State() = default;

	/**
	* @brief initialize valious game components of the state
	* pure virtual function must be implemented by the derived class
	*/
	virtual void init() = 0;

	/**
	* @brief updates the components of the state
	* pure virtual function must be implemented by the derived class
	* @param dt game time 
	* @param wim the window on which to update the components
	*/
	virtual void update(float dt, sf::RenderWindow &win) = 0;

	/**
	* @brief updates the components of the state
	* @param wim the window on which to draw the components
	*/
	virtual void draw(sf::RenderWindow &win) = 0;

	/**
	* @brief handles input and events comming to the game
	* pure virtual function must be implemented by the derived class
	* @param wim the window the event happend on
	* @param event the event the happend
	*/
	virtual void handleEvent(sf::RenderWindow &win, sf::Event &event) = 0;

	/**
	* @brief changes the game state
	* @param state the new state to change to
	*/
	void changeState(std::shared_ptr<State> state) {
		game->changeState(state);
	}
	//virtual void pause() = 0;
	//virtual void resume() = 0;

protected:
	Game *game;
};

#endif // !STATE_HPP
