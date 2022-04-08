#pragma once
#include <GL/freeglut.h>

extern double timp, ok;
extern double progres;
double total_drum = 12000;

void deseneaza_bara_progres() {
	if (ok) {
		progres += timp;
	}
	glPushMatrix();
	glTranslated(250.0, -100.0, 0.0);

	glColor3f(0.0, 0.0, 0.0);
	glRecti(-90, -5, 90, 5);

	glPopMatrix();

	glPushMatrix();
	glTranslated(250.0 - 80.0 + (180 * progres/total_drum), -100.0, 0.0);

	glColor3f(1.0, 1.0, 0.0);
	glRecti(-10, -10, 10, 10);

	glPopMatrix();
}