#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "state.hpp"
#include "menuItem.hpp"

/**
* @brief derived class of state handling the main nemu screen
*
*/
class MainMenu: public State
{
public:
	/**
	* @brief constructor creating a menu state
	* @param game pointer to Game class
	*/
	MainMenu(Game *game);

	/**
	* @brief defualt constructor
	*/
	~MainMenu() = default;

	void init() override;
	void update(float dt, sf::RenderWindow & win) override;
	void draw(sf::RenderWindow & win) override;
	void handleEvent(sf::RenderWindow & win, sf::Event & event) override;

private:
	std::vector<MenuItem> btns;
	sf::Font font;
	sf::Texture backTex;
	sf::Sprite backSrite;
};

#endif // !MAINMENU_HPP
