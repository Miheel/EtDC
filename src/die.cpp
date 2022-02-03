#include "die.hpp"

Die::Die(std::string path, std::array<std::string_view, 6> faces)
	:faces(faces), rolledDie(spriteFaces[0].first)
{
	for (size_t i = 0; i < spriteFaces.size(); i++)
	{
		spriteFaces[i] = { sf::Sprite(), sf::Texture() };
		spriteFaces[i].second.loadFromFile(path + faces[i].data());
		spriteFaces[i].first.setTexture(spriteFaces[i].second);
		spriteFaces[i].first.setScale(0.2f, 0.2f);
	}

}

void Die::setPosition(float x, float y)
{
	for (size_t i = 0; i < spriteFaces.size(); i++)
	{
		spriteFaces[i].first.setPosition(x, y);
	}
}

void Die::setOrigin(float x, float y)
{
	for (size_t i = 0; i < spriteFaces.size(); i++)
	{
		spriteFaces[i].first.setOrigin(x, y);
	}
}

sf::FloatRect Die::getGlobalBounds()
{
	return rolledDie.getGlobalBounds();
}

sf::FloatRect Die::getLocalBounds()
{
	return rolledDie.getLocalBounds();
}

sf::Sprite& Die::roll()
{
	rolledDie = spriteFaces[randGen(0, spriteFaces.size())].first;
	return rolledDie;
}

void Die::setFace(std::string face)
{
	int index = std::distance(faces.begin(), std::find(faces.begin(), faces.end(), face));
	rolledDie = spriteFaces.at(index).first;
}

sf::Sprite& Die::getFace()
{
	return rolledDie;
}

void Die::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(rolledDie);
}
