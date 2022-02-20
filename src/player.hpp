#ifndef PLAYER_HPP
#define PLAUER_HPP
#include <SFML/Graphics.hpp>
#include "die.hpp"

/**
* @brief enum class spesifying origins 
*/
enum class Orig
{
	TopL,
	TopR,
	BotL,
	BotR
};

/**
* @brief enum class spesifying positions
*/
enum class Pos
{
	Under,
	Over
};

/**
* @brief player class handling player info and thier position
*/
class Player: public sf::Drawable
{
public:
	/**
	* @brief constructor creating a player form character name
	* @param character a character name 
	*/
	Player(std::string character);

	/**
	* @brief Default destructor
	*/
	~Player() = default;

	/**
	* @brief sets the position of the character portrait
	*/
	void setPosition(float x, float y, Pos pos);

	/**
	* @brief sets the origin of the character portrait
	*/
	void setOrig(Orig orig);

	/**
	* @brief subctracts from the player hp
	* @param dmg the incomming damage numbers to substract 
	*/
	void takeDmg(int dmg);

	/**
	* @brief gets the die the player class is holding
	* @return a pointer the a player die
	*/
	Die* getDie();

	/**
	* @brief player rolls the die and gets back the result
	* @return a die face that was rolled together with a string representation of the face
	*/
	dieFaceRef roll();
private:
	sf::Texture playerTex;
	sf::Sprite player_portrait;
	Die playerDie;
	sf::Font font;
	sf::Text hp;

	/**
	* @brief Draw the object to a render target
	*	overloaded pure virtual function from sf::Drawable
	*
	* @param target Render target to draw to
	* @param states Current render states
	*
	*/
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

};

#endif // !PLAYER_HPP
