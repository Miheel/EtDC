#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "CONSTANTS.hpp"

auto main() -> int {

	Game game(sf::VideoMode(cor::WIN_X, cor::WIN_Y), "EtDC");
	while (game.isrunning())
	{
		game.handleEvent();
		game.update();
		game.draw();
	}

	return 0;
}
