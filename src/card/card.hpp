#ifndef CARD_HPP
#define CARD_HPP

#include <SFML/Graphics.hpp>

class Die;

/**
* @brief a Card class reprecenting a playing card
*/
class Card
{
public:
	/**
	* @brief constructor creating a card object
	* @param card path to a image
	* @param back path to a imge
	*/
	Card(std::string card, std::string back);

	/**
	* @brief default destructor
	*/
	virtual ~Card() = default;

	/**
	* @brief sets the position of the object sprite
	* @param x coordinate of the new possition
	* @param y coordinate of the new possition
	*/
	void setPosition(float x, float y);

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
	* @brief gets a the hp of the card
	* @return a pointer to a vector containing die objects
	*/
	virtual std::vector<std::shared_ptr<Die>>* getHp();

	/**
	* @brief virtual function to be implemented by derived class, adds hp to the cards hp pool
	* @param hp a smart pointer to a die object
	*/
	virtual void addHp(std::shared_ptr<Die> hp){}

	/**
	* @brief virtual function to be implemented by derived class, gets the dmg numbers
	* @return a string representing the amount of damage the card can do
	*/
	virtual std::string getDMG();

	/**
	* @brief virtual function to be implemented by derived class, sets the number of dmg the card can do
	* @param dmg the amount the damage the card should do
	*/
	virtual void setDMG(std::string dmg) {}

	sf::Sprite cardFront;
	sf::Sprite cardBack;
private:
	sf::Texture frontTex;
	sf::Texture backTex;

};

#endif // !CARD_HPP
