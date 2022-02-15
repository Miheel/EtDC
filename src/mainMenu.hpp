#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "state.hpp"
#include "menuItem.hpp"

class MainMenu: public State
{
public:
	MainMenu(Game *game);
	~MainMenu() = default;

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
	std::vector<MenuItem> btns;
	sf::Font font;
	sf::Texture backTex;
	sf::Sprite backSrite;
};

#endif // !MAINMENU_HPP
