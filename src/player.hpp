#ifndef PLAYER_HPP
#define PLAUER_HPP
#include <SFML/Graphics.hpp>
#include "die.hpp"

enum class Orig
{
	TopL,
	TopR,
	BotL,
	BotR
};
enum class Pos
{
	Under,
	Over
};

class Player: public sf::Drawable
{
public:
	Player(std::string character);
	~Player() = default;

	void setPosition(float x, float y, Pos pos);
	void setOrig(Orig orig);
private:
	sf::Texture playerTex;
	sf::Sprite player_portrait;
	Die playerDie;
	sf::Font font;
	sf::Text hp;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

};

#endif // !PLAYER_HPP
