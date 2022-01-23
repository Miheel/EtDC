#include "adventure.hpp"
#include <iostream>
#include "card/chapter.hpp"
#include "card/boss_card.hpp"
#include "randGen.hpp"
#include "CONSTANTS.hpp"

Adventure::Adventure(Game * game)
	:State(game)
{
}

void Adventure::init()
{
	cor::RandGen random;

	size_t playerPool = 4;
	size_t deckPool = 15;

	for (size_t i = 0; i < playerPool; i++)
	{
		player_vec.push_back(std::make_shared<Player>(cor::CHARACTERS[random(0, 5)].data()));
		player_vec[i]->setOrig(static_cast<Orig>(i));
	}

	chapter_deck.push(std::make_shared<BossCard>(cor::BOSS.data(), cor::BOSS_BACK.data()));
	for (size_t i = 0; i < deckPool; i++)
	{

		chapter_deck.push(std::make_shared<Chapter>(cor::CHAPTERS[random(0, 14)].data(), cor::CHAPTER_BACK.data()));
	}
	chapter_deck.push(std::make_shared<Card>(cor::BEGINNING.data(), cor::BEGINNING_BACK.data()));
}

void Adventure::update(float dt, sf::RenderWindow & win)
{
	player_vec[0]->setPosition(0.f, 0.f, Pos::Under);
	player_vec[1]->setPosition(static_cast<float>(game->win.getSize().x), 0.f, Pos::Under);
	player_vec[2]->setPosition(0.f, static_cast<float>(game->win.getSize().y), Pos::Over);
	player_vec[3]->setPosition(static_cast<float>(game->win.getSize().x), static_cast<float>(game->win.getSize().y), Pos::Over);

	if (!chapter_deck.empty())
	{
		chapter_deck.top()->setPosition(game->win.getSize().x / 2.f, game->win.getSize().y / 2.f);
	}
	if (turnedChapter)
	{
		turnedChapter->setPosition(game->win.getSize().x / 2.f, game->win.getSize().y / 2.f);
	}
}

void Adventure::draw(sf::RenderWindow & win)
{
	for (auto e : player_vec)
	{
		win.draw(*e);
	}
	if (!chapter_deck.empty())
	{
		win.draw(chapter_deck.top()->cardBack);
	}
	if (turnedChapter)
	{
		win.draw(turnedChapter->cardFront);
	}
}

void Adventure::handleEvent(sf::RenderWindow & win, sf::Event & event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			//chapter deck
			if (!chapter_deck.empty() && chapter_deck.top()->contains(event.mouseButton))
			{
				std::cout << "turn chapter card\n";
				turnedChapter = chapter_deck.top();
				chapter_deck.pop();
			}
			//playerdie
			/*if ()
			{
			}*/
		}
	}
}

void Adventure::pause()
{
}

void Adventure::resume()
{
}
