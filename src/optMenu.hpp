#ifndef OPTMENU_HPP
#define OPTMENU_HPP

#include "state.hpp"

/**
* @brief derived class of state handling optin menu screen
*
*/
class OptMenu: public State
{
public:

	/**
	* @brief constructor creating a option menu state
	* @param game pointer to Game class
	*/
	OptMenu(Game *game);

	/**
	* @brief default destructor
	*/
	~OptMenu() = default;

	void init() override;
	void update(float dt, sf::RenderWindow & win) override;
	void draw(sf::RenderWindow & win) override;
	void handleEvent(sf::RenderWindow & win, sf::Event & event) override;

private:

};

#endif // !OPTMENU_HPP
