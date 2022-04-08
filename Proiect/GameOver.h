#pragma once
#include <GL/freeglut.h>
#include "Utils.h"
#include "texte.h"

extern double WINDOW_WIDTH;
extern double WINDOW_HEIGTH;
extern int choice;
extern bool pressed;
extern double ok;
extern double j;
extern double i;
extern double rsj, rdj, rss, rds;
extern double progres;
extern float temp_mancare;

void deseneaza_ecran_game_over(void) {
	glColor3f(0, 0, 0);

	// Ecran negru
	glBegin(GL_POLYGON);
	glVertex2i(get_adjusted_width(0), get_adjusted_heigth(0));
	glVertex2i(get_adjusted_width(0), get_adjusted_heigth(WINDOW_HEIGTH));
	glVertex2i(get_adjusted_width(WINDOW_WIDTH), get_adjusted_heigth(WINDOW_HEIGTH));
	glVertex2i(get_adjusted_width(WINDOW_WIDTH), get_adjusted_heigth(0));
	glEnd();
	
	// Chenar
	double left_x = get_adjusted_width(WINDOW_WIDTH / 4);
	double left_y = get_adjusted_heigth(WINDOW_HEIGTH / 4);
	double right_x = get_adjusted_width(3 * WINDOW_WIDTH / 4);
	double right_y = get_adjusted_heigth(3 * WINDOW_HEIGTH / 4);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2i(left_x, left_y);
	glVertex2i(left_x, right_y);
	glVertex2i(right_x, right_y);
	glVertex2i(right_x, left_y);
	glEnd();

	RenderString(left_x*2 + 24, right_y - 24, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"GAME OVER");

	double retry_x = left_x + 2 * 12;
	double retry_y = left_y + 2 * 12;

	double exit_x = right_x - 4 * 12;
	double exit_y = left_y + 2 * 12;

	std::string retry_string = "Retry";
	std::string exit_string  = "Exit";

	std::string chosen_string;
	double chosen_x;
	double chosen_y;

	if (choice == 0) {
		chosen_string = retry_string;
		chosen_x = retry_x;
		chosen_y = retry_y;
	}
	else {
		chosen_string = exit_string;
		chosen_x = exit_x;
		chosen_y = exit_y;
	}
	glPushMatrix();
	glTranslated(chosen_x -12 * 1.25, chosen_y - 12, 0.0);

	glColor3f(0, 1, 1);
	glRecti(0, 0, 12 * chosen_string.size(), 3 * 12);

	glPopMatrix();

	RenderString(retry_x, retry_y, GLUT_BITMAP_HELVETICA_12, (const unsigned char*)"Retry");
	RenderString(exit_x, exit_y, GLUT_BITMAP_HELVETICA_12, (const unsigned char*)"Exit");
}

void handle_game_over_screen() {
	std::cout << choice << std::endl;
	switch (choice) {
	case 0: rsj = 0; rdj = 0; rss = 0; rds = 0.0; j = 0.0; ok = 1; progres = 0; temp_mancare = 100;  current_state = State::Started; break;
		case 1: glutLeaveMainLoop(); break;
	}
}