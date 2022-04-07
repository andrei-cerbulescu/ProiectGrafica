#pragma once
#include <GL/freeglut.h>

extern double loc_vert, height;
extern int este_politie, urmeaza_politie;

void deseneaza_masina() {
	glPushMatrix();
	glTranslated(loc_vert, height, 0.0);

	glColor3f(0.471, 0.667, 0.949);
	glRecti(-45, -15, 45, 15);

	if (este_politie) {
		glColor3f(1, 0.0, 0.0);
		glRecti(-30, -10, -15, 0);
	}

	if (urmeaza_politie) {
		glBegin(GL_TRIANGLES);

		glColor3f(1.0, 1.0, 0);
		glOrtho(-30.0, -45.0, -45.0, -2.5, 1.5, 5.5);
		glVertex2f(-45.0, -5.0);
		glVertex2f(-60.0, 10.0);
		glVertex2f(-60.0, -20.0);

		glEnd();

		glBegin(GL_TRIANGLES);

		glColor3f(1.0, 1.0, 0);

		glVertex2f(-45.0, 5.0);
		glVertex2f(-60.0, 20.0);
		glVertex2f(-60.0, -10.0);

		glEnd();
	}

	glPopMatrix();
}