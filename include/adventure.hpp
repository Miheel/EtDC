#ifndef ADVENTURE_HPP
#define ADVENTURE_HPP

#include <vector>
#include "state.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "card.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
/**
* @brief derived class of state handling adventure screen
*
*/
class Adventure: public State 
{
public:
	/**
	* @brief constructor creating a adventure state
	* @param game pointer to Game class
	*/
	Adventure(Game *game);

	/**
	* @brief default destructor
	*/
	~Adventure() = default;

	void init() override;
	void update(float dt, sf::RenderWindow & win) override;
	void draw(sf::RenderWindow & win) override;
	void handleEvent(sf::RenderWindow & win, sf::Event & event) override;

private:
	sf::Sprite nextTurnBtn;
	sf::Texture nextTexture;
	std::vector<std::shared_ptr<Player>> player_vec;
	cor::Deck<std::shared_ptr<Card>> chapter_deck;
	std::shared_ptr<Card> turnedChapter = nullptr;
	std::vector<std::shared_ptr<Die>> chapterDice;
	std::vector<std::shared_ptr<rolledDieFace>> characterRolledDie;
	sf::SoundBuffer soundbuffer;
	sf::Sound backgroundMusic;
};

#endif // !ADVENTURE_HPP
