#pragma once
#include <GL/freeglut.h>
#include "./texte.h"
#include "./masini.h"
#include "./Utils.h"
#include "./State.h"


extern double rsj, rdj, rss, rds;
extern double ok;
extern double contor;
extern double WINDOW_WIDTH;
extern double WINDOW_HEIGTH;
extern State current_state;

void deseneaza_masina_jucator() {
	glPushMatrix();
	glTranslated(0.0, j, 0.0);


	if (contor == 1 && (j != 160 && j != 320)) {
		j = j + 1;
		glRotatef(45.f, 0.f, 0.f, 1.f);
	}

	else {
		if (contor == -1 && (j != 160 && j != 0))
		{
			glRotatef(-45.f, 0.f, 0.f, 1.f);
			j = j - 1;
		}
		else {
			contor = 0;

		}
	}
	
	glColor3f(0.996, 0.365, 0.149);
	glRecti(-45, -15, 45, 15);
	RenderString(-15, -3, GLUT_BITMAP_8_BY_13, (const unsigned char*)"GLOVO");

	if (ok == 0)
	{
		rsj = 8;
		rss = -8;
		rdj = -8;
		rds = 8;
	}

	glPopMatrix();
	glPopMatrix();

	if (ok == 0) {
		current_state = State::Game_Over;
		PlaySound(NULL, NULL, SND_ASYNC | SND_FILENAME);
		RenderString(get_adjusted_width(WINDOW_WIDTH/2), get_adjusted_width(WINDOW_HEIGTH/2), GLUT_BITMAP_8_BY_13, (const unsigned char*)"GAME OVER");
	}
}