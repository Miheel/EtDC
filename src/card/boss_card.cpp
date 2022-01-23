#include "boss_card.hpp"
#include <iostream>
#include <fstream>

BossCard::BossCard(std::string card, std::string back)
	:Card(card, back)
{
	std::ifstream cardFile(card);
	std::string line;
	while (std::getline(cardFile, line))
	{
		if (line.find("NAME") != std::string::npos)
		{
			dmg.setString(line);
		}
		if (line.find("DMG") != std::string::npos)
		{
			dmg.setString(line);
		}
		else if (line.find("HP") != std::string::npos)
		{
			//hp.push_back(DieFace(line));
		}
		else if (line.find("PLAYERHP") != std::string::npos)
		{
			for (size_t i = 0; i < 4; i++)
			{
				//hp.push_back(Die());
			}
		}
	}
}
