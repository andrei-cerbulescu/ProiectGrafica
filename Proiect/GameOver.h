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

Reason game_over_reason = Reason::None;

void draw_cold(int x, double left_most, double top_most, double right_most, double bottom_most);

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

	double reason_left_x = right_x / 4;
	double reason_left_y = right_y / 4;
	double reason_right_x = 3.8 * reason_left_x;
	double reason_right_y = 3.5 * reason_left_y;

	double diff = 18;

	double left_most = (reason_left_x + reason_right_x) / 4;
	double top_most = reason_right_y - diff;

	double right_most = left_most * 3;
	double bottom_most = reason_left_y + diff;

	switch (game_over_reason) {
		case Reason::Police: {
			double diff = 24;
			double insignia_left_x = reason_left_x + diff;
			double insignia_left_y = reason_right_y - 2 * diff;

			double insignia_right_x = reason_right_x - diff;

			double insignia_middle_x = (insignia_left_x + insignia_right_x) / 2;
			double insignia_middle_up_y = insignia_left_y + diff;
			double insignia_middle_down_y = reason_left_y + 18 + diff;

			glColor3f(0, 0, 0);
			glBegin(GL_POLYGON);
			glVertex2i(insignia_left_x, insignia_left_y);
			glVertex2i(insignia_middle_x, insignia_middle_up_y);
			glVertex2i(insignia_right_x, insignia_left_y);
			glVertex2i(insignia_middle_x, insignia_middle_down_y);
			glEnd();
			float colors[] = { 0.75f, 1.0f, 0.0f };

			RenderString(insignia_middle_x - diff, insignia_middle_up_y - 18 - diff, GLUT_BITMAP_HELVETICA_18, "POLICE", colors);
			RenderString(((reason_left_x + reason_right_x) / 2) - diff, reason_left_y + 10, GLUT_BITMAP_TIMES_ROMAN_10, "Ai fost prins!");
			break;
		}
		case Reason::Crash: {

			double diff = 12;
			double left_most_x = reason_left_x + diff;
			double left_most_y = (reason_left_y + reason_right_y) / 2;

			double right_most_x = reason_right_x - diff;
			double right_most_y = left_most_y;

			double top_most_x = (reason_left_x + reason_right_x) / 2;
			double top_most_y = reason_right_y - 18;
			double bottom_most_x = top_most_x;
			double bottom_most_y = reason_left_y + 18;

			double origin_x = (reason_left_x + reason_right_x) / 2;
			double origin_y = (reason_left_y + reason_right_y) / 2;

			glColor3f(1.0f, 0.4f, 0.0f);
			glBegin(GL_TRIANGLE_FAN);
			glVertex3f(origin_x, origin_y, 0.0f);
			glVertex3f(left_most_x, left_most_y, 0.0f);
			glVertex3f((left_most_x + top_most_x) / 2 - 25, (left_most_y + top_most_y) / 2 + 25, 0.0f);
			glVertex3f(top_most_x, top_most_y, 0.0f);
			glVertex3f((right_most_x + top_most_x) / 2 + 25, (right_most_y + top_most_y) / 2 + 25, 0.0f);
			glVertex3f(right_most_x, right_most_y, 0.0f);
			glVertex3f((right_most_x + bottom_most_x) / 2, (right_most_y + bottom_most_x) / 2 - 5, 0.0f);
			glVertex3f(bottom_most_x, bottom_most_y, 0.0f);
			glVertex3f((left_most_x + bottom_most_x) / 2 + 5, ((left_most_y + bottom_most_x) / 2) - 15, 0.0f);
			glVertex3f(left_most_x, left_most_y, 0.0f);
			glEnd();


			glColor3f(0.6f, 1.0f, 0.0f);
			glPushMatrix();
			glScalef(0.75f, 0.75f, 0.0f);
			glTranslatef(100.0f, 70.0f, 50.0f);
			glBegin(GL_TRIANGLE_FAN);
			glVertex3f(origin_x, origin_y, 0.0f);
			glVertex3f(left_most_x, left_most_y, 0.0f);
			glVertex3f((left_most_x + top_most_x) / 2 - 25, (left_most_y + top_most_y) / 2 + 25, 0.0f);
			glVertex3f(top_most_x, top_most_y, 0.0f);
			glVertex3f((right_most_x + top_most_x) / 2 + 25, (right_most_y + top_most_y) / 2 + 25, 0.0f);
			glVertex3f(right_most_x, right_most_y, 0.0f);
			glVertex3f((right_most_x + bottom_most_x) / 2, (right_most_y + bottom_most_x) / 2 - 5, 0.0f);
			glVertex3f(bottom_most_x, bottom_most_y, 0.0f);
			glVertex3f((left_most_x + bottom_most_x) / 2 + 5, ((left_most_y + bottom_most_x) / 2) - 15, 0.0f);
			glVertex3f(left_most_x, left_most_y, 0.0f);
			glEnd();
			RenderString(((reason_left_x + reason_right_x) / 2) - 20, reason_right_y, GLUT_BITMAP_TIMES_ROMAN_10, "Ai facut accident!");
			glPopMatrix();
			break;
		}
		case Reason::Cold: {
			glColor3f(0.4f, 1.0f, 0.0f); // umple clepsidra
			draw_cold(GL_POLYGON, left_most, top_most, right_most, bottom_most);

			glColor3f(1.0f, 1.0f, 1.0f); // goleste clepsidra
			draw_cold(GL_TRIANGLES, left_most, top_most, right_most, bottom_most);

			glColor3f(0.0f, 0.0f, 0.0f);
			draw_cold(GL_LINE_LOOP, left_most, top_most, right_most, bottom_most); // chenar clepsidra - negru
			RenderString(((reason_left_x + reason_right_x) / 2) - 40, reason_left_y, GLUT_BITMAP_TIMES_ROMAN_10, "Timpul a expirat!");
			break;
		}
	}

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

void draw_cold(int x, double left_most, double top_most, double right_most, double bottom_most) {
	glBegin(x);
	glVertex2i(left_most, top_most);
	glVertex2i(right_most, top_most);
	glVertex2i(left_most, bottom_most);
	glVertex2i(right_most, bottom_most);
	glEnd();
}