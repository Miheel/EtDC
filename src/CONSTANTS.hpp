#ifndef RESPATH_HPP
#include <string_view>
#include <string>
#include <array>
#include <utility>
#include <map>
#include <string_view>

namespace cor {
	const int WIN_X = 1310;
	const int WIN_Y = 900;

	const std::string ABS_RES_PATH = "D:/Code/Repos/EtDC/res/";

	const std::string SPLASH_BACKGROUND = ABS_RES_PATH + "astolfo.jpg";

	const std::string MENU_BACKGROUND = ABS_RES_PATH + "escape-the-dark-castle.jpg";
	const std::string MENU_FONT = ABS_RES_PATH + "font/arial.ttf";

	constexpr std::array<std::string_view, 4> MENU_OPT_NAMES = {
		"Start Game",
		"Options",
		"Resume",
		"Quit"
	};

	const std::string CHAR_PATH = ABS_RES_PATH + "character/";
	constexpr std::array<std::string_view, 6> CHARACTERS = {
		"abbot.png",
		"cook.png",
		"miller.png",
		"smith.png",
		"tailor.png",
		"tanner.png"
	};

	const std::string BOSS = ABS_RES_PATH + "chapter/boss/boss.png";
	const std::string BOSS_BACK = ABS_RES_PATH + "chapter/boss/cardBack/boss_back.png";

	const std::string BEGINNING = ABS_RES_PATH + "chapter/start/start.png";
	const std::string BEGINNING_BACK = ABS_RES_PATH + "chapter/start/cardBack/start_back.png";

	const std::string CHAPT_PATH = ABS_RES_PATH + "chapter/";
	constexpr std::array<std::string_view, 15> CHAPTERS = {
		"card_1.png",
		"card_2.png",
		"card_3.png",
		"card_4.png",
		"card_5.png",
		"card_6.png",
		"card_7.png",
		"card_8.png",
		"card_9.png",
		"card_10.png",
		"card_11.png",
		"card_12.png",
		"card_13.png",
		"card_14.png",
		"card_15.png"
	};

	const std::string BOTTOM_DECK = ABS_RES_PATH + "chapter/deck_bottom.png";

	const std::string CHAPTER_BACK = ABS_RES_PATH + "chapter/cardBack/chapter_back.png";

	const std::string PLAYER_DICE_PATH = ABS_RES_PATH + "dice/player/";
	const std::map<std::string_view, std::array<std::string_view, 6>> PLAYER_DICE_FACES = {
		//constexpr std::array <std::pair<std::string_view, std::array<std::string_view, 6>>, 6> DIE_FACES = 

			{ "abbot.png", { "wisdom.png", "might.png", "Double_wisdom.png", "Double_might.png", "cunning.png", "wisdom.png" }},
			{ "cook.png", { "might.png", "wisdom.png", "Double_cunning.png", "Double_might.png", "cunning.png", "might.png" }},
			{ "miller.png", { "cunning.png", "wisdom.png", "Double_might.png", "Double_cunning.png", "might.png", "cunning.png" }},
			{ "smith.png", { "might.png", "wisdom.png", "Double_wisdom.png", "Double_might.png", "cunning.png", "might.png" }},
			{ "tailor.png", { "cunning.png", "wisdom.png", "Double_cunning.png", "Double_wisdom.png", "might.png", "cunning.png" }},
			{ "tanner.png", { "wisdom.png", "might.png", "Double_wisdom.png", "Double_cunning.png", "cunning.png", "wisdom.png" }}
	};

	const std::string CHAPTER_DICE_PATH = ABS_RES_PATH + "dice/chapter/";
	constexpr std::array<std::string_view, 6> CHAPTER_DICE_FACES = {
			"wisdom.png",
			"might.png",
			"cunning.png",
			"wisdom.png",
			"might.png",
			"cunning.png"
	};

	const std::string END_TURN_BTN = ABS_RES_PATH + "btn/end_turn.png";

} // !namespace cor

#endif // !RESPATH_HPP
