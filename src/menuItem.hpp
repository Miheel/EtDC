#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <SFML/Graphics.hpp>
#include <string_view>

class MenuItem: public sf::Drawable
{
public:
	MenuItem(std::string_view title, const sf::Font &font, sf::Vector2f size, sf::Color color);
	~MenuItem() = default;

	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	bool  contains(float x, float y);
	bool  contains(sf::Event::MouseButtonEvent mouse);

private:
	sf::RectangleShape box;
	sf::Text text;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

#endif // !MENUITEM_HPP
