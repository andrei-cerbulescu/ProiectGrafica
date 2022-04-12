#pragma once
#include <GL/freeglut.h>
#include "Utils.h"
#include "texte.h"
#include <vector>
#include <iostream>

extern double WINDOW_WIDTH;
extern double WINDOW_HEIGTH;

double top = 4 * WINDOW_HEIGTH / 5;
double bottom = 3 * WINDOW_HEIGTH / 5;
double diff = 12;
std::vector<Text> menu_list_options;
double start_y = get_adjusted_heigth(200);
double start_x = get_adjusted_width(100);
int current_choice = 0;

void increase_choice() { 
	current_choice = (current_choice + 1) % menu_list_options.size();
}
void decrease_choice() {
	if (current_choice == 0)
		current_choice = menu_list_options.size() - 1;
	else
		current_choice--;
}

void deseneaza_bastonas(double &left) {
	glBegin(GL_POLYGON);
		glVertex2f(left, bottom);
		glVertex2f(left, top);
		left += diff;
		glVertex2f(left, top);
		glVertex2f(left, bottom);
		glVertex2f(left-diff, bottom);
	glEnd();
}

void deseneaza_talpa(double& left) {
	glBegin(GL_POLYGON);
		glVertex2f(left, bottom);
		glVertex2f(left, bottom+diff);
	left += diff;
		glVertex2f(left, bottom+diff);
		glVertex2f(left, bottom);
		glVertex2f(left, bottom);
	glEnd();
}

void deseneaza_spatiu(double& left) {
	left += 2 * diff;
}

void deseneaza_fata_dezamagita(double& left) {
	glBegin(GL_POLYGON);
		glVertex2f(left, top);
		glVertex2f(left + diff/2, top);
		left += diff*2;
		glVertex2f(left, bottom);
		glVertex2f(left - diff / 2, bottom);
	glEnd();
}

void deseneaza_fata_dezamagita_dar_pe_invers(double& left) {
	glBegin(GL_POLYGON);
		glVertex2f(left, bottom);
		glVertex2f(left + diff / 2, bottom);
		left += diff * 2;
		glVertex2f(left, top);
		glVertex2f(left - diff / 2, top);
	glEnd();
}

void deseneaza_acoperis(double& left) {
	glBegin(GL_POLYGON);
		glVertex2f(left, top - 2 * diff );
		glVertex2f(left, top);
		left += 2 * diff;
		glVertex2f(left, top);
		glVertex2f(left, top - 2 * diff);
	glEnd();
}

void deseneaza_etaj(double& left) {
	double mijloc = bottom + top;
	mijloc /= 2;
	glBegin(GL_POLYGON);
		glVertex2f(left, mijloc - diff/4);
		glVertex2f(left, mijloc + diff/4);
		left += 2 * diff;
		glVertex2f(left, mijloc + diff/4);
		glVertex2f(left, mijloc - diff/4);
	glEnd();
}

void deseneaza_scari_acoperis(double& left) {
	double mijloc = (bottom + top) / 2;
	glBegin(GL_POLYGON);
		glVertex2f(left, mijloc - diff/4);
		glVertex2f(left, top);
		left += diff/2;
		glVertex2f(left, top);
		glVertex2f(left, mijloc - diff/4);
	glEnd();
}

void deseneaza_fata_dezamagita_jumatate_jos(double& left) {
	double mijloc = (bottom + top) / 2;
	glBegin(GL_POLYGON);
		glVertex2f(left, mijloc - diff / 4);
		glVertex2f(left + diff / 2, mijloc - diff / 4);
		left += diff * 2;
		glVertex2f(left, bottom);
		glVertex2f(left - diff / 2, bottom);
	glEnd();
}

void deseneaza_podea(double& left) {
	glBegin(GL_POLYGON);
	glVertex2f(left, bottom);
	glVertex2f(left, bottom + diff / 4);
	left += 2 * diff;
	glVertex2f(left, bottom + diff / 4);
	glVertex2f(left, bottom);
	glEnd();
}

void deseneaza_fata_dezamagita_jumatate_sus(double& left) {
	double mijloc = (bottom + top) / 2;
	glBegin(GL_POLYGON);
	glVertex2f(left, top);
	glVertex2f(left + diff / 2, top);
	left += diff * 2;
	glVertex2f(left, mijloc - diff / 4);
	glVertex2f(left - diff / 2, mijloc - diff / 4);
	glEnd();
}

void deseneaza_fata_dezamagita_dar_pe_invers_jumate_sus(double& left) {
	double mijloc = (bottom + top) / 2;
	glBegin(GL_POLYGON);
	glVertex2f(left, mijloc - diff / 4 );
	glVertex2f(left + diff / 2, mijloc - diff / 4);
	left += diff * 2;
	glVertex2f(left, top);
	glVertex2f(left - diff / 2, top);
	glEnd();
}

void append_option(std::string what_to_draw) {
	double start;
	if (menu_list_options.empty())
		start = start_x;
	else
		start = menu_list_options[menu_list_options.size() - 1].sfarsit_desen();
	menu_list_options.push_back(*(new Text(start, start_y, what_to_draw, Tip_Chenar::Bila)));
}

void display_menu() {
	for (int i = 0; i < menu_list_options.size(); i++) {
		if (i == current_choice) {
			menu_list_options[i].deseneaza_cu_chenar();
		}
		else {
			menu_list_options[i].deseneaza();
		}
	}
}

void deseneaza_main_menu() {
	if (menu_list_options.size() == 0) {
		append_option("Joaca");
		append_option("Statistici");
		append_option("Iesi");
	}
	top = 4 * WINDOW_HEIGTH / 5;
	bottom = 3 * WINDOW_HEIGTH / 5;
	double left = WINDOW_WIDTH / 50;
	double placeholder;

	//glColor3fv(Colors::getInstance()->getColor(Shade::Black));

	// L
	deseneaza_bastonas(left);
	deseneaza_talpa(left);
	deseneaza_spatiu(left);

	// I
	deseneaza_bastonas(left);
	deseneaza_spatiu(left);

	// V
	deseneaza_fata_dezamagita(left);
	deseneaza_fata_dezamagita_dar_pe_invers(left);
	deseneaza_spatiu(left);

	// R
	deseneaza_bastonas(left);
	deseneaza_acoperis(placeholder = left);
	deseneaza_etaj(placeholder = left);
	deseneaza_scari_acoperis(placeholder);
	deseneaza_fata_dezamagita_jumatate_jos(left);
	deseneaza_spatiu(left);

	// E
	deseneaza_bastonas(left);
	deseneaza_acoperis(placeholder = left);
	deseneaza_etaj(placeholder = left);
	deseneaza_podea(left);
	deseneaza_spatiu(left);

	// Z
	deseneaza_acoperis(placeholder = left);
	deseneaza_fata_dezamagita_dar_pe_invers(placeholder = left);
	deseneaza_podea(left);
	deseneaza_spatiu(left);

	// A
	placeholder = left;
	deseneaza_fata_dezamagita_dar_pe_invers(left);
	placeholder += diff;
	deseneaza_etaj(placeholder);
	deseneaza_fata_dezamagita(left);
	deseneaza_spatiu(left);

	top = 3 * WINDOW_HEIGTH / 5;
	bottom = 2 * WINDOW_HEIGTH / 5;
	left = 10 * WINDOW_WIDTH / 50;

	// M
	deseneaza_bastonas(left);
	deseneaza_fata_dezamagita_jumatate_sus(left);
	deseneaza_fata_dezamagita_dar_pe_invers_jumate_sus(left);
	deseneaza_bastonas(left);
	deseneaza_spatiu(left);

	// A
	placeholder = left;
	deseneaza_fata_dezamagita_dar_pe_invers(left);
	placeholder += diff;
	deseneaza_etaj(placeholder);
	deseneaza_fata_dezamagita(left);
	deseneaza_spatiu(left);


	// N
	deseneaza_bastonas(left);
	deseneaza_fata_dezamagita(left);
	deseneaza_bastonas(left);
	deseneaza_spatiu(left);

	// C
	deseneaza_bastonas(left);
	deseneaza_acoperis(placeholder = left);
	deseneaza_podea(left);
	deseneaza_spatiu(left);

	// A
	placeholder = left;
	deseneaza_fata_dezamagita_dar_pe_invers(left);
	placeholder += diff;
	deseneaza_etaj(placeholder);
	deseneaza_fata_dezamagita(left);
	deseneaza_spatiu(left);


	// R
	deseneaza_bastonas(left);
	deseneaza_acoperis(placeholder = left);
	deseneaza_etaj(placeholder = left);
	deseneaza_scari_acoperis(placeholder);
	deseneaza_fata_dezamagita_jumatate_jos(left);
	deseneaza_spatiu(left);

	// E
	deseneaza_bastonas(left);
	deseneaza_acoperis(placeholder = left);
	deseneaza_etaj(placeholder = left);
	deseneaza_podea(left);
	deseneaza_spatiu(left);


	display_menu();
}

void handle_main_menu() {
	switch (current_choice) {
		case 0: GameState::getInstance()->setStartGame(); break;
		case 1: GameState::getInstance()->setStatsScreen(); break;
		case 2: GameState::quitGame(); break;
	}
}