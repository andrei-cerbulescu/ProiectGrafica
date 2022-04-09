#pragma once
#include <GL/freeglut.h>
#include <string>
#include <iomanip>
#include <sstream>

extern float temp_mancare;
extern double ok, timp;

void RenderString(float x, float y, void* font, const unsigned char* string, float values[])
{
	glColor3f(values[0], values[1], values[3]);
	glRasterPos2f(x, y);
	glutBitmapString(font, string);
}

void RenderString(float x, float y, void* font, const unsigned char* string)
{
	float values[] = {0.0f, 0.0f, 0.0f};
	RenderString(x, y, font, string, values);
}


void RenderString(float x, float y, void* font, std::string to_render)
{
	RenderString(x, y, font, (const unsigned char*)to_render.c_str());
}

void RenderString(float x, float y, void* font, std::string to_render, float values[])
{
	RenderString(x, y, font, (const unsigned char*)to_render.c_str(), values);
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