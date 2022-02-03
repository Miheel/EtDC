#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <vector>
#include "SFML/Graphics.hpp"

//forward declaration 
class State;

class Game
{
public:
	Game(sf::VideoMode mode, const sf::String &title);
	~Game() = default;

	void update();
	void draw();
	void handleEvent();

	void changeState(std::shared_ptr<State> state);
	void pushState(std::shared_ptr<State> state);
	void popState();
	size_t stateSize();

	bool isrunning();

	sf::RenderWindow win;
private:
	std::vector<std::shared_ptr<State>> states;

	sf::Clock gameTime;

};

#endif // !GAME_HPP
