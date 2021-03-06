#include "bossCard.hpp"
#include "CONSTANTS.hpp"
#include "utility.hpp"
#include <iostream>
#include <fstream>


BossCard::BossCard(std::string card, std::string back)
	:Card(card, back)
{}

void BossCard::setAttributes(std::string cardName, size_t nrOfPlayers)
{
	cor::readCard(*this, cardName, nrOfPlayers);
}

std::vector<std::shared_ptr<Die>>* BossCard::getHp()
{
	return &hp;
}

void BossCard::addHp(std::shared_ptr<Die> hp)
{
	this->hp.push_back(hp);
}

std::string BossCard::getDMG()
{
	return dmg.getString();
}

void BossCard::setDMG(std::string dmg)
{
	this->dmg.setString(dmg);
}
