#include "player.hpp"
#include <iostream>
#include "CONSTANTS.hpp"

Player::Player(std::string character) 
	:playerDie(cor::DIE_FACES.at(character))
{

	if (!font.loadFromFile(cor::MENU_FONT))
		std::cerr << "Font not loaded\n";
	hp.setFont(font);
	hp.setString("20");

	if (!playerTex.loadFromFile(cor::CHAR_PATH + character))
	{
		std::cerr << "could not load tex\n";
	}
	player_portrait.setTexture(playerTex);

}

void Player::setPosition(float x, float y, Pos pos)
{
	player_portrait.setPosition(x, y);

	switch (pos)
	{
		case Pos::Under:
			hp.setPosition(player_portrait.getGlobalBounds().left, player_portrait.getGlobalBounds().height);
			break;
		case Pos::Over:
			hp.setOrigin(0.f, hp.getLocalBounds().height + hp.getGlobalBounds().height/2.f);
			hp.setPosition(player_portrait.getGlobalBounds().left, player_portrait.getGlobalBounds().top);
			break;
		default:
			break;
	}
}

void Player::setOrig(Orig orig)
{
	switch (orig)
	{
		case Orig::TopL:
			break;
		case Orig::TopR:
			player_portrait.setOrigin(player_portrait.getGlobalBounds().width, 0.f);
			break;
		case Orig::BotL:
			player_portrait.setOrigin(0.f, player_portrait.getGlobalBounds().height);
			break;
		case Orig::BotR:
			player_portrait.setOrigin(player_portrait.getGlobalBounds().width, player_portrait.getGlobalBounds().height);
			break;
		default:
			break;
	}
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(player_portrait);
	target.draw(hp);
	target.draw(playerDie);
}
