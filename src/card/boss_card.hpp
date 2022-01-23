#ifndef BOSS_CARD_HPP
#define BOSS_CARD_HPP
#include <string>
#include "card.hpp"

class BossCard : public Card
{
public:
	BossCard(std::string card, std::string back);
	~BossCard() = default;

private:
	sf::Text name;
	sf::Text dmg;
	//std::vector<DieFace> hp;
};

#endif // !BOSS_CARD_HPP
