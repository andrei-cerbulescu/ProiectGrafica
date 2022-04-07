#include <iostream>
#include<windows.h>
#include <GL/freeglut.h>
#include "./Iarba.h"
#include "./Texte.h"
#include "./sosea.h"
#include "./masina_jucator.h"
#include "./masini.h"
#include "./keyboard.h"

using namespace std;

GLdouble left_m = -100.0;
GLdouble right_m = 700.0;
GLdouble bottom_m = -140.0;
GLdouble top_m = 460.0;
double ok = 1;
double j = 0.0;
double i = 0.0;
double contor = 0;
double loc_vert = 800;
int vector[3] = { 0, 160, 320 };
double height = vector[rand() % 3];
int score = 0;
double timp = 0.15;
int pct = 1000;
double rsj, rdj, rss, rds = 0;
float temp_mancare = 100;
int urmeaza_politie = 0;
int este_politie = 0;
int flashuri_date = 0;

void init(void)
{
	glClearColor(0.98, 0.929, 0.792, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(left_m, right_m, bottom_m, top_m, -1.0, 1.0);
}

void startgame(void)
{
	if (loc_vert < -150)
	{
		este_politie = 0;
		height = vector[rand() % 3];
		if (urmeaza_politie) {
			urmeaza_politie = 0;
			este_politie = 1;
		}
		if (!este_politie && !urmeaza_politie) {
			urmeaza_politie = rand() % 100 < 20;
		}
		loc_vert = 800;
	}

	if (score >= pct && pct <= 15000)
	{
		timp += 0.1;
		pct += 1000;
	}


	if (height != j || (loc_vert > 90 || loc_vert < -90))
	{

		if (i < -380)
		{
			i = 0;
		}
		i = i - 2 * timp;

		loc_vert -= timp;

		glutPostRedisplay();
	}
	else {
		ok = 0;
	}
}

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	deseneaza_sosea();

	deseneaza_masina_jucator();

	deseneaza_masina();
	
	deseneazaIarba();

	livreaza_comanda();
	mancare_calda();
	vitezometru();

	startgame();
	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 700.0, -140.0, 460.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Depaseste masinile - mini game");
	init();
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);

	glutMainLoop();
}