#ifndef EXTRACARD_HPP
#define EXTRACARD_HPP
#include <string>
#include "card.hpp"
#include "../die.hpp"

/**
* @brief derived class from Card reprecenting a extra help card
*/
class ExtraCard : public Card
{
public:
	/**
	* @brief constructor creating a extra card object
	* @param card path to a image
	* @param back path to a imge
	*/
	ExtraCard(std::string card, std::string back);
	~ExtraCard() = default;

	/**
	* @brief sets all the attribues of the card
	* @param cardName path to an image
	* @param nrOfPlayers the number of players in the game
	*/
	void setAttributes(std::string cardName, size_t nrOfPlayers) override;
	std::vector<std::shared_ptr<Die>>* getHp() override;
	void addHp(std::shared_ptr<Die> hp) override;
	std::string getDMG() override;
	void setDMG(std::string dmg) override;
private:
	sf::Text dmg;
	std::vector<std::shared_ptr<Die>> hp;

};

#endif // !EXTRACARD_HPP
