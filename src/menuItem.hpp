#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <SFML/Graphics.hpp>
#include <string_view>

/**
* @brief class used to create menu items to use a buttons menu buttons
*/
class MenuItem: public sf::Drawable
{
public:
	/**
	* @brief contructor creating a menu item
	* @param title the visible text
	* @param font the font face of the text
	* @param size the size of the text
	* @param color the color of the rectangle
	*/
	MenuItem(std::string_view title, const sf::Font &font, sf::Vector2f size, sf::Color color);
	
	/**
	* @brief default destructor
	*/
	~MenuItem() = default;

	/**
	* @brief set position of the menu item
	* @param x coordinate of the new possition
	* @param y coordinate of the new possition
	*/
	void setPosition(float x, float y);

	/**
	* @brief gets the global boundinh rectanhle of the entity
	*	The returned rectangle is in global coordinates, which means
	*	that it takes into account the transformations
	* @return Global bounding rectangle of the entity
	*/
	sf::FloatRect getGlobalBounds();

	/**
	* @brief see if the inputted coordinates is within the entity
	* @param x on the screen coordinate
	* @param y on the screen coordinate
	* @return true of the coordinates is within the entity, false otherwise
	*/
	bool  contains(float x, float y);
	
	/**
	* @brief see if the coordinates of a mouse click is within the entity
	* @param mouse a mouse click event
	* @return true if the coordinates of the mouseclick is within the entity, false otherwise
	*/
	bool  contains(sf::Event::MouseButtonEvent mouse);

private:
	sf::RectangleShape box;
	sf::Text text;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

#endif // !MENUITEM_HPP
