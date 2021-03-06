#pragma once
#include <GL/freeglut.h>
#include "Colors.h"

extern double timp, ok;
extern double progres;
double total_drum = 12000;
extern float score, temp_mancare;

void deseneaza_bara_progres() {
	if (ok) {
		progres += timp;
	}
	glPushMatrix();
	glTranslated(250.0, -100.0, 0.0);

	glColor3fv(Colors::getInstance()->getColor(Shade::Black));
	glRecti(-90, -5, 90, 5);

	glPopMatrix();

	glPushMatrix();
	glTranslated(250.0 - 80.0 + (180 * progres/total_drum), -100.0, 0.0);

	if (progres / total_drum > 1) {
		progres = 0;
		score += temp_mancare;
		temp_mancare = 100;
	}

	glColor3fv(Colors::getInstance()->getColor(Shade::Yellow));
	glRecti(-10, -10, 10, 10);

	glPopMatrix();
}