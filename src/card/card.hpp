#ifndef CARD_HPP
#define CARD_HPP

#include <SFML/Graphics.hpp>

class Card
{
public:
	Card(std::string card, std::string back);
	virtual ~Card() = default;
	void setPosition(float x, float y);
	bool contains(float x, float y);
	bool contains(sf::Event::MouseButtonEvent mouse);

	sf::Sprite cardFront;
	sf::Sprite cardBack;
private:
	sf::Texture frontTex;
	sf::Texture backTex;
};

#endif // !CARD_HPP
