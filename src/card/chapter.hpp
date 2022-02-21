#ifndef CHAPTER_HPP
#define CHAPTER_HPP
#include <string>
#include "card.hpp"
#include "../die.hpp"

/**
* @brief derived class from Card reprecenting a chapter card
*/
class Chapter : public Card
{
public:
	/**
	* @brief constructor creating a chaptercard object
	* @param card path to a image
	* @param back path to a imge
	*/
	Chapter(std::string card, std::string back);
	~Chapter() = default;

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

#endif // !CHAPTER_HPP
