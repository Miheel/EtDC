#include "card.hpp"

Card::Card(std::string card, std::string back)
{
	if (!frontTex.loadFromFile(card))
	{
		//ERROR
	}
	cardFront.setTexture(frontTex);

	if (!backTex.loadFromFile(back))
	{
		//ERROR
	}
	cardBack.setTexture(backTex);
	cardBack.setOrigin(0, cardBack.getLocalBounds().height / 2.f);
	cardFront.setOrigin(cardFront.getLocalBounds().width, cardFront.getLocalBounds().height / 2.f);
}

void Card::setPosition(float x, float y)
{
	cardFront.setPosition(x, y);
	cardBack.setPosition(x, y);
}

bool Card::contains(float x, float y)
{
	return cardBack.getGlobalBounds().contains(x, y);
}

bool Card::contains(sf::Event::MouseButtonEvent mouse)
{
	return this->contains(static_cast<float>(mouse.x), static_cast<float>(mouse.y));
}
