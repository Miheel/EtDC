#ifndef CHAPTER_HPP
#define CHAPTER_HPP
#include <string>
#include "card.hpp"

class Chapter : public Card
{
public:
	Chapter(std::string card, std::string back);
	~Chapter() = default;

private:
	sf::Text dmg;
	//std::vector<DieFace> hp;
};

#endif // !CHAPTER_HPP
