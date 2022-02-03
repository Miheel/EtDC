#ifndef ADVENTURE_HPP
#define ADVENTURE_HPP

#include "state.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "card/card.hpp"


class Adventure: public State 
{
public:
	Adventure(Game *game);
	~Adventure() = default;

	void init() override;
	void update(float dt, sf::RenderWindow & win) override;
	void draw(sf::RenderWindow & win) override;

	void handleEvent(sf::RenderWindow & win, sf::Event & event) override;
	void pause() override;
	void resume() override;

private:
	std::vector<std::shared_ptr<Player>> player_vec;
	cor::Deck<std::shared_ptr<Card>> chapter_deck;
	std::shared_ptr<Card> turnedChapter = nullptr;
	std::vector<std::shared_ptr<Die>> chapterDice;
};

#endif // !ADVENTURE_HPP
