#pragma once
#include <GL/freeglut.h>

extern double loc_vert, height;
extern int este_politie;

void deseneaza_masina() {
	glPushMatrix();
	glTranslated(loc_vert, height, 0.0);

	glColor3f(0.471, 0.667, 0.949);
	glRecti(-45, -15, 45, 15);

	if (este_politie) {
		glColor3f(1, 0.0, 0.0);
		glRecti(-30, -10, -15, 0);
	}	

	glPopMatrix();
}