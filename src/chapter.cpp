#include "chapter.hpp"
#include "CONSTANTS.hpp"
#include "utility.hpp"
#include <iostream>
#include <fstream>


Chapter::Chapter(std::string card, std::string back)
	:Card(cor::CHAPT_PATH + card, back)
{
}

void Chapter::setAttributes(std::string cardName, size_t nrOfPlayers)
{
	cor::readCard(*this, cor::CHAPT_PATH + cardName, nrOfPlayers);
}

std::vector<std::shared_ptr<Die>>* Chapter::getHp()
{
	return &hp;
}

void Chapter::addHp(std::shared_ptr<Die> hp)
{
	this->hp.push_back(hp);
}

std::string Chapter::getDMG()
{
	return dmg.getString();
}

void Chapter::setDMG(std::string dmg)
{
	this->dmg.setString(dmg);
}


