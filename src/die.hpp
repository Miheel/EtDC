#ifndef DIE_HPP
#define DIE_HPP
#include <SFML/Graphics.hpp>
#include <array>
#include <utility>
#include "randGen.hpp"

class Die: public sf::Drawable
{
public:
	Die(std::array<std::string_view, 6> faces);
	~Die() = default;

	void setPosition(float x, float y);
	bool contains(float x, float y);
	bool contains(sf::Event::MouseButtonEvent mouse);
	sf::Sprite roll();

private:
	cor::RandGen randGen;
	const std::array<std::string_view, 6> faces;

	std::array<std::pair<sf::Sprite, sf::Texture>, 6> spriteFaces;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	
};

#endif // !DIE_HPP
