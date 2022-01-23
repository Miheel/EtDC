#include "die.hpp"

Die::Die(std::array<std::string_view, 6> faces) 
	:faces(faces)
{
	for (size_t i = 0; i < spriteFaces.size(); i++)
	{
		spriteFaces[i] = { sf::Sprite(), sf::Texture() };
		spriteFaces[i].second.loadFromFile(faces[i].data());
		spriteFaces[i].first.setTexture(spriteFaces[i].second);
	}
}

void Die::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(spriteFaces[0].first);
}
