#ifndef CHAPTER_HPP
#define CHAPTER_HPP
#include <string>
#include "card.hpp"
#include "../die.hpp"

class Chapter : public Card
{
public:
	Chapter(std::string card, std::string back);
	~Chapter() = default;

	std::vector<std::shared_ptr<Die>> getHp() override;
	void addHp(std::shared_ptr<Die> hp) override;
	std::string getDMG() override;
	void setDMG(std::string dmg) override;
private:
	sf::Text dmg;
	std::vector<std::shared_ptr<Die>> hp;
};

#endif // !CHAPTER_HPP
