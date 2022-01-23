#ifndef SPLASH_HPP
#define SPLASH_HPP

#include "state.hpp"

class Splash: public State
{
public:
	Splash(Game *game);
	~Splash() = default;

	void init() override;
	void update(float dt, sf::RenderWindow &win) override;
	void draw(sf::RenderWindow &win) override;

	void handleEvent(sf::RenderWindow &win, sf::Event &event) override;
	void pause() override;
	void resume() override;

private:
	sf::Texture tex;
	sf::Sprite Background;
	sf::Clock splashTime;
};

#endif // !SPLASH_HPP
