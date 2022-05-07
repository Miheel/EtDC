#ifndef ENDGAME_HPP
#define ENDGAME_HPP

#include "state.hpp"

/**
* @brief derived class of state handling the Death screen
*
*/
class EndGame : public State
{
public:
	/**
	* @brief constructor creating a menu state
	* @param game pointer to Game class
	*/
	EndGame(Game *game);

	/**
	* @brief defualt constructor
	*/
	~EndGame() = default;

	void setMessage(std::string message);

	void init() override;
	void update(float dt, sf::RenderWindow & win) override;
	void draw(sf::RenderWindow & win) override;
	void handleEvent(sf::RenderWindow & win, sf::Event & event) override;

private:
	sf::Text Message;
	sf::Clock time;
	sf::Font font;
};

#endif // !ENDGAME_HPP
