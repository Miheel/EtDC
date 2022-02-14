#include "chapter.hpp"
#include "../CONSTANTS.hpp"
#include "../help.hpp"
#include <iostream>
#include <fstream>


Chapter::Chapter(std::string card, std::string back)
	:Card(cor::CHAPT_PATH + card, back)
{
	readCard(*this, cor::CHAPT_PATH + card);
	//card.replace(card.end() - 3, card.end(), "txt");
	//std::ifstream cardFile(card);
	//std::string line;
	//while (std::getline(cardFile, line))
	//{
	//	if (line.find("DMG") != std::string::npos)
	//	{
	//		dmg.setString(line.substr(line.find(":") + 1, line.size()));
	//		std::string s = dmg.getString();
	//		std::cout << s;
	//	}
	//	else if (line.find("STATICHP") != std::string::npos)
	//	{
	//		auto temp_vec = splitString(line.substr(line.find(":") + 1, line.size()));
	//		for (auto e : temp_vec)
	//		{
	//			auto temp_die = std::make_shared<Die>(cor::CHAPTER_DICE_PATH, cor::CHAPTER_DICE_FACES);
	//			temp_die->setFace(e + ".png");
	//			hp.push_back(temp_die);
	//		}
	//	}
	//	else if (line.find("PLAYERHP") != std::string::npos)
	//	{
	//		for (size_t i = 0; i < 4; i++)
	//		{
	//			//hp.push_back(Die());
	//		}
	//	}
	//}
}

std::vector<std::shared_ptr<Die>> Chapter::getHp()
{
	return hp;
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