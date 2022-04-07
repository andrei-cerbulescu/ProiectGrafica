#pragma once
#include <GL/freeglut.h>

extern double loc_vert, height;

void deseneaza_masina() {
	glPushMatrix();
	glTranslated(loc_vert, height, 0.0);

	glColor3f(0.471, 0.667, 0.949);
	glRecti(-45, -15, 45, 15);


	glPopMatrix();
}