#pragma once
#include <GL/freeglut.h>
#include <string>
#include <iomanip>
#include <sstream>

extern float temp_mancare;
extern double ok, timp;

void RenderString(float x, float y, void* font, const unsigned char* string)
{

	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(x, y);

	glutBitmapString(font, string);
}

void livreaza_comanda() {
	glColor3f(0.55, 0.788, 0.451);

	RenderString(200.0f, 425.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"Livreaza comanda!");
}

void mancare_calda() {
	if (ok == 1) temp_mancare -= 0.0015;
	glColor3f(0.55, 0.788, 0.451);
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << temp_mancare;
	std::string var = "Temperatura mancare: " + stream.str();
	RenderString(400.0f, -100.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)var.c_str());
}

void vitezometru() {
	if (ok == 1) temp_mancare -= 0.0005;
	glColor3f(0.55, 0.788, 0.451);
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << timp * 200;
	std::string var = "Viteza: " + stream.str() + " km/h";
	RenderString(-90.0f, -100.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)var.c_str());
}