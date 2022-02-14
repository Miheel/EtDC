#ifndef DIE_HPP
#define DIE_HPP
#include <SFML/Graphics.hpp>
#include <array>
#include <utility>
#include "randGen.hpp"


typedef std::pair<sf::Sprite&, std::string_view> dieFaceRef;
typedef std::pair<sf::Sprite, std::string_view> rolledDieFace;
class Die: public sf::Drawable
{
public:
	Die(std::string path, std::array<std::string_view, 6> faces);
	~Die() = default;

	void setPosition(float x, float y);
	void setOrigin(float x, float y);
	sf::FloatRect getGlobalBounds();
	sf::FloatRect getLocalBounds();
	bool contains(float x, float y);
	bool contains(sf::Event::MouseButtonEvent mouse);
	dieFaceRef roll();
	void setFace(std::string face);
	dieFaceRef getFace();

private:
	cor::RandGen randGen;
	dieFaceRef rolledDie;
	const std::array<std::string_view, 6> faces;

	std::array<std::pair<sf::Sprite, sf::Texture>, 6> spriteFaces;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	
};

#endif // !DIE_HPP
