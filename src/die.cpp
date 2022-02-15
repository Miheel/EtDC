#include "die.hpp"

Die::Die(std::string path, std::array<std::string_view, 6> faces)
	:faces(faces), rolledDie(spriteFaces[0].first, faces[0])
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
	return rolledDie.first.getGlobalBounds();
}

sf::FloatRect Die::getLocalBounds()
{
	return rolledDie.first.getLocalBounds();
}

bool Die::contains(float x, float y)
{
	return rolledDie.first.getGlobalBounds().contains(x, y);
}

bool Die::contains(sf::Event::MouseButtonEvent mouse)
{
	return this->contains(static_cast<float>(mouse.x), static_cast<float>(mouse.y));
}

dieFaceRef Die::roll()
{
	auto index = randGen(0, static_cast<int>(spriteFaces.size() - 1));
	rolledDie.first = spriteFaces[index].first;
	rolledDie.second = faces[index];
	return rolledDie;
}

void Die::setFace(std::string face)
{
	auto index = std::distance(faces.begin(), std::find(faces.begin(), faces.end(), face));
	rolledDie.first = spriteFaces.at(index).first;
	rolledDie.second = faces[index];
}

dieFaceRef Die::getFace()
{
	return rolledDie;
}

void Die::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(rolledDie.first);
}
