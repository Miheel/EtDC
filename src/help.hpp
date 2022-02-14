#ifndef HELP_HPP
#define HELP_HPP
#include <vector>
#include <string>
#include "card/card.hpp"

std::vector<std::string> splitString(std::string str);

void readCard(Card& card, std::string cardName);
#endif // !HELP_HPP
