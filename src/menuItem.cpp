#include "menuItem.hpp"

MenuItem::MenuItem(std::string_view title, const sf::Font &font, sf::Vector2f size, sf::Color color)
	:box(size), text(title.data(), font)
{
	box.setFillColor(color);
	box.setOrigin(box.getLocalBounds().left + box.getLocalBounds().width / 2.f,
		box.getLocalBounds().top + box.getLocalBounds().height / 2.f);

	text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.f,
		text.getLocalBounds().top + text.getLocalBounds().height / 2.f);
}

void MenuItem::setPosition(float x, float y)
{
	box.setPosition(x, y);
	text.setPosition(x, y);
}

sf::FloatRect MenuItem::getGlobalBounds()
{
	return box.getGlobalBounds();
}

bool MenuItem::contains(float x, float y)
{
	return box.getGlobalBounds().contains(x, y);
}

bool MenuItem::contains(sf::Event::MouseButtonEvent mouse)
{
	return box.getGlobalBounds().contains(static_cast<float>(mouse.x), static_cast<float>(mouse.y));
}

void MenuItem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(box);
	target.draw(text);
}
