#include "player.hpp"
#include <iostream>
#include <string>
#include "CONSTANTS.hpp"

Player::Player(std::string character) 
	:playerDie(cor::PLAYER_DICE_PATH, cor::PLAYER_DICE_FACES.at(character)), hp("20", font)
{
	if (!font.loadFromFile(cor::MENU_FONT))
		std::cerr << "Font not loaded\n";

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

			playerDie.setOrigin(playerDie.getLocalBounds().width, 0.f);
			playerDie.setPosition(player_portrait.getGlobalBounds().left + player_portrait.getGlobalBounds().width, player_portrait.getGlobalBounds().height);
			break;
		case Pos::Over:
			hp.setOrigin(0.f, hp.getLocalBounds().height + hp.getGlobalBounds().height/2.f);
			hp.setPosition(player_portrait.getGlobalBounds().left, player_portrait.getGlobalBounds().top);

			playerDie.setOrigin(playerDie.getLocalBounds().width, playerDie.getLocalBounds().height);
			playerDie.setPosition(player_portrait.getGlobalBounds().left + player_portrait.getGlobalBounds().width, player_portrait.getGlobalBounds().top);
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
	}
}

void Player::takeDmg(int dmg)
{
	auto playerHpInt = std::stoi(static_cast<std::string>(hp.getString()));
	hp.setString(std::to_string(playerHpInt - dmg));
}

int Player::getHp()
{
	return std::stoi(static_cast<std::string>(hp.getString()));
}

Die* Player::getDie()
{
	return &playerDie;
}

dieFaceRef Player::roll()
{
	return playerDie.roll();
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(player_portrait);
	target.draw(hp);
	target.draw(playerDie);
}
