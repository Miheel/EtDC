#include "help.hpp"
#include "CONSTANTS.hpp"
#include "die.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

std::vector<std::string> splitString(std::string str) {
	std::stringstream iss(str);
	std::string word;
	std::vector<std::string> temp;

	while (std::getline(iss, word, ','))
	{
		temp.push_back(word);
	}
	return temp;
}

void readCard(Card& card, std::string cardName)
{
	cardName.replace(cardName.end() - 3, cardName.end(), "txt");

	std::ifstream cardFile(cardName);
	std::string line;

	while (std::getline(cardFile, line))
	{
		if (line.find("DMG") != std::string::npos)
		{
			card.setDMG(line.substr(line.find(":") + 1, line.size()));
		}
		else if (line.find("STATICHP") != std::string::npos)
		{
			auto temp_vec = splitString(line.substr(line.find(":") + 1, line.size()));
			for (auto e : temp_vec)
			{
				auto temp_die = std::make_shared<Die>(cor::CHAPTER_DICE_PATH, cor::CHAPTER_DICE_FACES);
				temp_die->setFace(e + ".png");
				card.addHp(temp_die);
			}

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
