#pragma once
#include <GL/freeglut.h>
#include "./texte.h"

double timer = 0;
extern double ok;
extern bool oprit_de_politie;

void scena_oprit_de_politie() {
	timer += 0.0005;

	if (timer < 5) {
		RenderString(250.0f, 200.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Buna seara. Actele la control.");
	}

	if (timer > 5 && timer < 10) {
		RenderString(250.0f, 200.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Stiti cu ce viteza mergeati?");
	}

	if (timer > 10) {
		RenderString(250.0f, 200.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Game Over");
	}

	if (timer > 15) {
		ok = 0;
		oprit_de_politie = false;
		timer = 0;
	}
}