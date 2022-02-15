#ifndef CARD_HPP
#define CARD_HPP

#include <SFML/Graphics.hpp>

class Die;

class Card
{
public:
	Card(std::string card, std::string back);
	virtual ~Card() = default;
	void setPosition(float x, float y);
	bool contains(float x, float y);
	bool contains(sf::Event::MouseButtonEvent mouse);

	virtual std::vector<std::shared_ptr<Die>>* getHp();
	virtual void addHp(std::shared_ptr<Die> hp){}
	virtual std::string getDMG();
	virtual void setDMG(std::string dmg) {}

	sf::Sprite cardFront;
	sf::Sprite cardBack;
private:
	sf::Texture frontTex;
	sf::Texture backTex;

};

#endif // !CARD_HPP
