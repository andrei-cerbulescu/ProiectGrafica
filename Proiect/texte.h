#pragma once
#include <GL/freeglut.h>

void RenderString(float x, float y, void* font, const unsigned char* string)
{

	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(x, y);

	glutBitmapString(font, string);
}

void depaseste_masinile() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.55, 0.788, 0.451);

	RenderString(200.0f, 425.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Depaseste masinile!");
}