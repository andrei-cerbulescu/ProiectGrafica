#pragma once
#include <GL/freeglut.h>
#include "Colors.h"

extern double loc_vert, height;
extern int este_politie, urmeaza_politie, flashuri_date;

float timeout_flashuri;
bool flashuri_aprinse;

void da_flashuri() {
	if (flashuri_aprinse) {
		glBegin(GL_TRIANGLES);

		glColor3fv(Colors::getInstance()->getColor(Shade::Yellow));
		glOrtho(-30.0, -45.0, -45.0, -2.5, 1.5, 5.5);
		glVertex2f(-45.0, -5.0);
		glVertex2f(-60.0, 10.0);
		glVertex2f(-60.0, -20.0);

		glEnd();

		glBegin(GL_TRIANGLES);

		glColor3fv(Colors::getInstance()->getColor(Shade::Yellow));

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

	glColor3fv(Colors::getInstance()->getColor(Shade::Enemy_Car));
	glRecti(-45, -15, 45, 15);

	if (este_politie) {
		glColor3fv(Colors::getInstance()->getColor(Shade::Red));
		glRecti(-30, -10, -15, 0);
	}

	if (urmeaza_politie) {
		da_flashuri();
	}

	glPopMatrix();
}