#include "extraCard.hpp"
#include "../CONSTANTS.hpp"
#include <iostream>

ExtraCard::ExtraCard(std::string card, std::string back)
	:Card(card, back)
{}

void ExtraCard::setAttributes(std::string cardName, size_t nrOfPlayers)
{}

std::vector<std::shared_ptr<Die>>* ExtraCard::getHp()
{
	return &hp;
}

void ExtraCard::addHp(std::shared_ptr<Die> hp)
{}

std::string ExtraCard::getDMG()
{
	return dmg.getString();
}

void ExtraCard::setDMG(std::string dmg)
{}
