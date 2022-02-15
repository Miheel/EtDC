#ifndef SPLASH_HPP
#define SPLASH_HPP

#include "state.hpp"

/**
* @brief derived class of state handling splash screen
*
*/
class Splash: public State
{
public:
	/**
	* @brief constructor creating a splash state
	* @param game pointer to Game class
	*/
	Splash(Game *game);

	/**
	* @brief default destructor
	*/
	~Splash() = default;

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
	sf::Texture tex;
	sf::Sprite Background;
	sf::Clock splashTime;
};

#endif // !SPLASH_HPP
