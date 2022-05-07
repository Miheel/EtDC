#ifndef DIE_HPP
#define DIE_HPP
#include <SFML/Graphics.hpp>
#include <array>
#include <utility>
#include "randGen.hpp"


typedef std::pair<sf::Sprite&, std::string_view> dieFaceRef;
typedef std::pair<sf::Sprite, std::string_view> rolledDieFace;


/**
* @brief class used to create and manage die objects
*/
class Die: public sf::Drawable
{
public:
	/**
	* @brief parametrisized constructor 
	* @param path a path to images
	* @param faces array of strings of dice faces
	*/
	Die(std::string path, std::array<std::string_view, 6> faces);

	/**
	* @brief defualt constructor
	*/
	~Die() = default;

	/**
	* @brief set position of the drawable sprite
	* @param x coordinate of the new possition
	* @param y coordinate of the new possition
	*/
	void setPosition(float x, float y);

	/**
	* @brief sets the possition of the sprite
	* @param x coordinate on the sprite
	* @param y coordinate on the sprite
	*/
	void setOrigin(float x, float y);

	/**
	* @brief gets the global boundinh rectanhle of the entity
	*	The returned rectangle is in global coordinates, which means
	*	that it takes into account the transformations
	* @return Global bounding rectangle of the entity
	*/
	sf::FloatRect getGlobalBounds();

	/**
	* @brief gets the local bounding rectanhle of the entity
	*	The returned rectangle is in local coordinates, which means
	*	that it ignores the transformations
	* @return local bounding rectangle of the entity
	*/
	sf::FloatRect getLocalBounds();

	/**
	* @brief see if the inputted coordinates is within the entity
	* @param x on the screen coordinate
	* @param y on the screen coordinate
	* @return true of the coordinates is within the entity, false otherwise
	*/
	bool contains(float x, float y);

	/**
	* @brief see if the coordinates of a mouse click is within the entity
	* @param mouse a mouse click event
	* @return true if the coordinates of the mouseclick is within the entity, false otherwise
	*/
	bool contains(sf::Event::MouseButtonEvent mouse);

	/**
	* @brief rolls the die and gets back the rolled face of the die
	* @return the rolled face of the die
	*/
	dieFaceRef roll();

	/**
	* @brief sets a new face of the die instead of rolling
	* @param face a string representation of the face to set for the die
	*/
	void setFace(std::string face);

	/**
	* @brief returns the current rolled of set face of the die
	* @return the current face of the die
	*/
	dieFaceRef getFace();

private:
	cor::RandGen randGen;
	const std::array<std::string_view, 6> faces;	
	dieFaceRef rolledDie;

	std::array<std::pair<sf::Sprite, sf::Texture>, 6> spriteFaces;

	/**
	* @brief implemented pure virtual function from super class sf::Drawable
	*/
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	
};

#endif // !DIE_HPP
