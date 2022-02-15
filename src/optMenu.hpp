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

	/**
	* @brief method inherited from State class
	*/
	void init() override;

	/**
	* @brief method inherited from State class
	*/
	void update(float dt, sf::RenderWindow &win) override;

	/**
	* @brief method inherited from State class
	*/
	void draw(sf::RenderWindow &win) override;

	/**
	* @brief method inherited from State class
	*/
	void handleEvent(sf::RenderWindow &win, sf::Event &event) override;
	void pause() override;
	void resume() override;

private:

};

#endif // !OPTMENU_HPP
