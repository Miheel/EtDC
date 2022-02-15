#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <vector>
#include "SFML/Graphics.hpp"

//forward declaration 
class State;

/**
* @brief class to manage game funktions
*/
class Game
{
public:
	/**
	* brief parametrisized constructor
	* @param mode defines the video mode for the window
	* @param title Title of the window
	*/
	Game(sf::VideoMode mode, const sf::String &title);

	/**
	* @brief defualt constructor
	*/
	~Game() = default;

	/**
	* @brief update the current state of the game
	*/
	void update();

	/**
	* @brief Draw the current game state on to screen
	*/
	void draw();

	/**
	* @brief manage the current game states events
	*/
	void handleEvent();

	/**
	* @brief changes the game state, removes the old state
	*/
	void changeState(std::shared_ptr<State> state);

	/**
	* @brief adds a new game state on top of the old state
	*/
	void pushState(std::shared_ptr<State> state);

	/**
	* @brief removes the current game state
	*/
	void popState();

	/**
	* @brief gets the size of the state container
	* @return How many states are in the container
	*/
	size_t stateSize();
	
	/**
	* @brief tells wether or not the wondow is open
	* @return true if the wondow is opne, false if the wondpw has been closed.
	*/
	bool isrunning();

	sf::RenderWindow win;
private:
	std::vector<std::shared_ptr<State>> states;

	sf::Clock gameTime;

};

#endif // !GAME_HPP
