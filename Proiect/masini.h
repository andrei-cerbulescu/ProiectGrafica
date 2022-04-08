#pragma once
#include <GL/freeglut.h>

extern double loc_vert, height;
extern int este_politie, urmeaza_politie, flashuri_date;

float timeout_flashuri;
bool flashuri_aprinse;

void da_flashuri() {
	if (flashuri_aprinse) {
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

	timeout_flashuri -= 0.01;
	if (timeout_flashuri < 0) {
		if (!flashuri_aprinse) {
			timeout_flashuri = 2;
		}
		else {
			timeout_flashuri = 5;
		}
		flashuri_aprinse = !flashuri_aprinse;
	}
}

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
		da_flashuri();
	}

	glPopMatrix();
}