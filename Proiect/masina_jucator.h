#pragma once
#include <GL/freeglut.h>
#include "./texte.h"

extern double rsj, rdj, rss, rds;
extern double ok;
extern double contor;

void deseneaza_masina_jucator() {
	glPushMatrix();
	glTranslated(0.0, j, 0.0);

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
		RenderString(250.0f, 200.0f, GLUT_BITMAP_8_BY_13, (const unsigned char*)"GAME OVER");
	}

	if (contor == 1 && (j != 160 && j != 320))
		j = j + 1;
	else if (contor == -1 && (j != 160 && j != 0))
		j = j - 1;
	else {
		contor = 0;

	}
}