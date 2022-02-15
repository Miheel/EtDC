#include "adventure.hpp"
#include <iostream>
#include "card/chapter.hpp"
#include "card/boss_card.hpp"
#include "randGen.hpp"
#include "mainMenu.hpp"
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
	size_t dicePool = 9;

	//players
	for (size_t i = 0; i < playerPool; i++)
	{
		player_vec.push_back(std::make_shared<Player>(cor::CHARACTERS[random(0, 5)].data()));
		player_vec[i]->setOrig(static_cast<Orig>(i));
	}

	//chapter deck bottom card, boss, 15 chapter cards and start card
	chapter_deck.push(std::make_shared<Card>(cor::BOTTOM_DECK, cor::BOTTOM_DECK));
	chapter_deck.push(std::make_shared<BossCard>(cor::BOSS.data(), cor::BOSS_BACK.data()));
	for (size_t i = 0; i < deckPool; i++)
	{
		chapter_deck.push(std::make_shared<Chapter>(cor::CHAPTERS[random(0, 14)].data(), cor::CHAPTER_BACK.data()));
	}
	chapter_deck.push(std::make_shared<Card>(cor::BEGINNING.data(), cor::BEGINNING_BACK.data()));

	//9 chapter dice with three different faces
	for (size_t i = 0; i < dicePool; i++)
	{
		chapterDice.push_back(std::make_shared<Die>(cor::CHAPTER_DICE_PATH, cor::CHAPTER_DICE_FACES));
		chapterDice[i]->setOrigin(0.f, chapterDice[i]->getLocalBounds().height);

		switch (i)
		{
			case 0:
			case 1:
			case 2:
				chapterDice[i]->setFace(cor::CHAPTER_DICE_FACES[0].data());
				break;
			case 3:
			case 4:
			case 5:
				chapterDice[i]->setFace(cor::CHAPTER_DICE_FACES[1].data());
				break;
			case 6:
			case 7:
			case 8:
				chapterDice[i]->setFace(cor::CHAPTER_DICE_FACES[2].data());
				break;
		}
	}
	//next turn button texture, sprite, origin and scale
	if (nextTexture.loadFromFile(cor::END_TURN_BTN))
	{
		nextTurnBtn.setTexture(nextTexture);
		nextTurnBtn.setOrigin(nextTurnBtn.getGlobalBounds().width / 2.f, nextTurnBtn.getGlobalBounds().top + nextTurnBtn.getGlobalBounds().height);
		nextTurnBtn.setScale(0.5f, 0.5f);
	}
}

void Adventure::update(float dt, sf::RenderWindow & win)
{
	//place player portraits in each corner
	player_vec[0]->setPosition(0.f, 0.f, Pos::Under);
	player_vec[1]->setPosition(static_cast<float>(game->win.getSize().x), 0.f, Pos::Under);
	player_vec[2]->setPosition(0.f, static_cast<float>(game->win.getSize().y), Pos::Over);
	player_vec[3]->setPosition(static_cast<float>(game->win.getSize().x), static_cast<float>(game->win.getSize().y), Pos::Over);

	//place backside of chapter deck in middle
	if (!chapter_deck.empty())
	{
		chapter_deck.top()->setPosition(game->win.getSize().x / 2.f, game->win.getSize().y / 2.f);
	}
	//place the turned chapter card beside the deck
	if (turnedChapter)
	{
		turnedChapter->setPosition(game->win.getSize().x / 2.f, game->win.getSize().y / 2.f);
	}
	//temporary variables to contains possistions to place item around the player portraits
	//and chapter deck
	auto cardLeft = chapter_deck.top()->cardBack.getGlobalBounds().left;
	auto cardTop = chapter_deck.top()->cardBack.getGlobalBounds().top;
	auto dieTop_0 = chapterDice[0]->getGlobalBounds().top;
	auto dieTop_3 = chapterDice[3]->getGlobalBounds().top;
	//place chapter dice above the chapter deck 3 rows with different die faces
	//row 1
	chapterDice[0]->setPosition(cardLeft, cardTop);
	chapterDice[1]->setPosition(cardLeft + chapterDice[0]->getGlobalBounds().width, cardTop);
	chapterDice[2]->setPosition(cardLeft + (chapterDice[1]->getGlobalBounds().width * 2), cardTop);
	//row 2
	chapterDice[3]->setPosition(cardLeft, chapterDice[0]->getGlobalBounds().top);
	chapterDice[4]->setPosition(cardLeft + chapterDice[0]->getGlobalBounds().width, dieTop_0);
	chapterDice[5]->setPosition(cardLeft + (chapterDice[1]->getGlobalBounds().width * 2), dieTop_0);
	//row 3
	chapterDice[6]->setPosition(cardLeft, chapterDice[3]->getGlobalBounds().top);
	chapterDice[7]->setPosition(cardLeft + chapterDice[0]->getGlobalBounds().width, dieTop_3);
	chapterDice[8]->setPosition(cardLeft + (chapterDice[1]->getGlobalBounds().width * 2), dieTop_3);

	cardLeft = chapter_deck.top()->cardFront.getGlobalBounds().left;
	auto cardBot = chapter_deck.top()->cardFront.getGlobalBounds().top + chapter_deck.top()->cardFront.getGlobalBounds().height;

	//place chapter hp dice under the turned chapter card
	int i = 0;
	for (auto e : *chapter_deck.top()->getHp())
	{
		e->getFace().first.setPosition(cardLeft + (e->getFace().first.getGlobalBounds().width * i++), cardBot);
	}

	//place player rolled dice under the chapter hp dice
	i = 0;
	for (auto &e : characterRolledDie)
	{
		e->first.setPosition(cardLeft + (e->first.getGlobalBounds().width * i++), cardBot + e->first.getGlobalBounds().height);
		e->first.setOrigin(0.f, 0.f);
	}

	//place next turn button at bottom middle of screen 
	nextTurnBtn.setPosition(game->win.getSize().x / 2.f, game->win.getSize().y);
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
		for (auto e : *turnedChapter->getHp())
		{
			win.draw(*e);
		}
	}
	for (auto e : chapterDice)
	{
		win.draw(*e);
	}
	for (auto &e : characterRolledDie)
	{
		win.draw(e->first);
	}
	win.draw(nextTurnBtn);
}

void Adventure::handleEvent(sf::RenderWindow & win, sf::Event & event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			//turn chapter if chapter deck has more than 1 item and mouse click on the deck 
			if (chapter_deck.size() > 1 && chapter_deck.top()->contains(event.mouseButton) && (!turnedChapter || turnedChapter->getHp()->size() == 0))
			{
				std::cout << "turn chapter card\n";
				turnedChapter = chapter_deck.top();
				chapter_deck.pop();
				characterRolledDie.clear();
			}
			//player roll die
			for (auto player : player_vec)
			{
				if (player->getDie()->contains(event.mouseButton) && characterRolledDie.size() < 4)
				{
					characterRolledDie.push_back(std::make_shared<rolledDieFace>(player->roll()));
				}
			}
			//remove chapter hp
			if (turnedChapter != nullptr && turnedChapter->getHp()->size() > 0)
			{	
				for (auto hpIT = turnedChapter->getHp()->begin(); hpIT != turnedChapter->getHp()->end(); hpIT++)
				{
					if ((*hpIT)->contains(event.mouseButton))
					{
						std::cout << (*hpIT)->getFace().second << "\n";
						auto foundIT = std::find_if(characterRolledDie.begin(), characterRolledDie.end(), [hpIT](std::shared_ptr<rolledDieFace> face) { return face->second == (*hpIT)->getFace().second; });
						if (foundIT != std::end(characterRolledDie)) {
							std::cout << "found " << (*foundIT)->second << "\n";
							characterRolledDie.erase(foundIT);
							turnedChapter->getHp()->erase(hpIT);
							break;
						}
					}
				}
			}
			//end turn
			if (nextTurnBtn.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
			{
				characterRolledDie.clear();
			}
		}
	}
	if (event.type = sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			game->pushState(std::make_shared<MainMenu>(MainMenu(game)));
		}
	}
}

void Adventure::pause()
{
}

void Adventure::resume()
{
}
