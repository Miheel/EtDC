#ifndef HELP_HPP
#define HELP_HPP
#include <vector>
#include <string>
#include "card.hpp"

/**
* @brief namespace cor
*/
namespace cor
{
	/**
	* @brief splits a string into a vector
	* @param str a string to split
	* @return a vector containing the split string
	*/
	std::vector<std::string> splitString(std::string str);

	/**
	* @brief reads a file containgin card attributes and set the atribuets of the corresponding card object
	* @param card the card to set the atributes on
	* @param cardName the text file to read from
	*/
	void readCard(Card& card, std::string cardName, size_t nrOfPlayers);
}
#endif // !HELP_HPP
