#pragma once
#include <GL/freeglut.h>

extern double ok, j, contor, timp;

void miscasus(void)
{
	if (ok != 0)
	{
		if (j < 320)
		{
			contor = 1;
			j += 1;
		}
		glutPostRedisplay();
	}
}

void miscajos(void)
{
	if (ok != 0)
	{
		if (j > 0)
		{
			contor = -1;
			j -= 1;
		}
		glutPostRedisplay();
	}
}

void accelereaza(void) {
	if (ok != 0) {
		if (timp < 0.7) {
			timp += 0.01;
		}
	}
}

void decelereaza(void) {
	if (ok != 0) {
		if (timp > 0.05) {
			timp -= 0.01;
		}
	}
}

void keyboard(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP:
		miscasus();
		break;
	case GLUT_KEY_DOWN:
		miscajos();
		break;
	case GLUT_KEY_RIGHT:
		accelereaza();
		break;
	case GLUT_KEY_LEFT:
		decelereaza();
		break;
	}
}