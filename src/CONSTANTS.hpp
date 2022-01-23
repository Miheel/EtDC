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

	constexpr std::array<std::string_view, 3> MENU_OPT_NAMES = {
		"Start Game",
		"Options",
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
	const std::string CHAPTER_BACK = ABS_RES_PATH + "chapter/cardBack/chapter_back.png";


	const std::map<std::string_view, std::array<std::string_view, 6>> DIE_FACES = {
	//constexpr std::array <std::pair<std::string_view, std::array<std::string_view, 6>>, 6> DIE_FACES = 

		{ "abbot.png", { "wisdom1", "might2", "Double wisdom3", "Double might4", "cunning5", "wisdom6" }},
		{ "cook.png", { "might1", "wisdom2", "Double cunning3", "Double might4", "cunning5", "might6" }},
		{ "miller.png", { "cunning1", "wisdom2", "Double might3", "Double cunning4", "might5", "cunning6" }},
		{ "smith.png", { "might1", "wisdom2", "Double wisdom3", "Double might4", "cunning5", "might6" }},
		{ "tailor.png", { "cunning1", "wisdom2", "Double cunning3", "Double wisdom4", "might5", "cunning6" }},
		{ "tanner.png", { "wisdom1", "might2", "Double wisdom3", "Double cunning4", "cunning5", "wisdom6" }}
	 };

} // !namespace cor

#endif // !RESPATH_HPP
