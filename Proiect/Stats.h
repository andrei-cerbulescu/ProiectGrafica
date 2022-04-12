#pragma once
#include "Utils.h"
#include "GameData.h"
extern double WINDOW_WIDTH;
extern double WINDOW_HEIGTH;

OptiuniOnScreen optiuni(20, get_adjusted_width(WINDOW_WIDTH/3), get_adjusted_heigth(WINDOW_HEIGTH/4), Tip_Chenar::Intreg);

OptiuniOnScreen get_stats_options() {
	return optiuni;
}

void deseneaza_stats() {
	if (optiuni.get_current_size() == 0) {
		optiuni.append_option("Return");
	}
	double diff = 25;
	double initial_x = get_adjusted_width(2 * WINDOW_WIDTH / 7);
	double initial_y = get_adjusted_heigth(4 * WINDOW_HEIGTH / 7);
	RenderString(initial_x, initial_y -= diff, GLUT_BITMAP_TIMES_ROMAN_24, "Score: " + std::to_string(GameData::getInstance()->get_score()));
	RenderString(initial_x, initial_y -= diff, GLUT_BITMAP_TIMES_ROMAN_24, "Number of orders: " + std::to_string(GameData::getInstance()->get_number_of_orders()));
	RenderString(initial_x, initial_y -= diff, GLUT_BITMAP_TIMES_ROMAN_24, "Total time spent: " + std::to_string(GameData::getInstance()->get_time_spent_total()));
	RenderString(initial_x, initial_y -= diff, GLUT_BITMAP_TIMES_ROMAN_24, "Time spent playing: " + std::to_string(GameData::getInstance()->get_time_spent()));
	optiuni.display_menu();
}

void handle_stats() {
	switch (optiuni.get_current_choice()) {
		case 0: GameState::getInstance()->setMainMenu();
	}

}