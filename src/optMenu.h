#ifndef OPTMENU_HPP
#define OPTMENU_HPP

#include "state.hpp"

class OptMenu: public State
{
public:
	OptMenu(Game *game);
	~OptMenu() = default;

	void init() override;
	void update(float dt, sf::RenderWindow &win) override;
	void draw(sf::RenderWindow &win) override;

	void handleEvent(sf::RenderWindow &win, sf::Event &event) override;
	void pause() override;
	void resume() override;

private:

};

#endif // !OPTMENU_HPP
