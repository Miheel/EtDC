#ifndef SPLASH_HPP
#define SPLASH_HPP

#include "state.hpp"
#include <SFML/Audio.hpp>

/**
* @brief derived class of state handling splash screen
*
*/
class Splash: public State
{
public:

	Splash() = default;

	/**
	* @brief constructor creating a splash state
	* @param game pointer to Game class
	*/
	Splash(Game *game);

	/**
	* @brief default destructor
	*/
	~Splash() = default;

	void init() override;
	void update(float dt, sf::RenderWindow & win) override;
	void draw(sf::RenderWindow & win) override;
	void handleEvent(sf::RenderWindow & win, sf::Event & event) override;

private:
	sf::Texture tex;
	sf::Sprite Background;
	sf::Clock splashTime;
	sf::SoundBuffer soundbuffer;
	sf::Sound backgroundMusic;
};

#endif // !SPLASH_HPP
