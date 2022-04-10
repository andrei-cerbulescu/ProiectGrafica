#include <iostream>
#include<windows.h>
#include <GL/freeglut.h>
#include "./Iarba.h"
#include "./Texte.h"
#include "./sosea.h"
#include "./masina_jucator.h"
#include "./masini.h"
#include "./keyboard.h"
#include "./State.h"
#include "./GameOver.h"
#include <time.h>
#include "./bara_progres.h"
#include "./scena_oprit_de_politie.h"
#include "./radio.h"
#include "./MainMenu.h"
#include "GameData.h"
#include "Stats.h"

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
int coloane[3] = { 0, 160, 320 };
double height = coloane[rand() % 3];
int score = 0;
double timp = 0.15;
int pct = 1000;
double rsj, rdj, rss, rds = 0;
float temp_mancare = 100;
double WINDOW_WIDTH = 800;
double WINDOW_HEIGTH = 600;
int urmeaza_politie = 0;
int este_politie = 0;
int flashuri_date = 0;
bool oprit_de_politie = false;
double progres = 0;

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

		if (este_politie && timp > 0.35) {
			oprit_de_politie = true;
		}

		este_politie = 0;
		height = coloane[rand() % 3];

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

void startmenu(void) {
	startgame();
	if (height == j) {
		if (j < 2) {
			miscasus();
		}
		else {
			miscajos();
		}
	}

}
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	switch (GameState::getInstance()->getState()) {
	case State::Started: {
		if (oprit_de_politie || temp_mancare <= 0) {
			if (oprit_de_politie) {
				scena_oprit_de_politie();
			}
			if (temp_mancare <= 0) {
				RenderString(400.0f, -100.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)"S-a racit mancarea! :/");
				GameState::getInstance()->setGameOver(Reason::Cold);
			}
		}
		else {
			deseneaza_sosea();

			deseneaza_masina_jucator();

			deseneaza_masina();

			deseneazaIarba();

			livreaza_comanda();
			mancare_calda();
			vitezometru();

			deseneaza_bara_progres();
			deseneaza_radio();

			startgame();
		}
		break;
	}
	case State::Game_Over: {
		deseneaza_ecran_game_over();
		break;
	}
	case State::Main_Menu: {
		deseneaza_sosea();
		deseneaza_masina_jucator();
		deseneaza_masina();
		deseneazaIarba();
		startmenu();
		deseneaza_main_menu();
		break;
	}
	case State::Stats: {
		deseneaza_sosea();
		deseneaza_masina_jucator();
		deseneaza_masina();
		deseneazaIarba();
		startmenu();
		deseneaza_stats();
		break;
	}
	}
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
	GameData::getInstance();
	srand(time(0));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGTH);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Livreaza Comanda");
	init();
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboardSpecialKeys);
	glutKeyboardFunc(keyboardNormalKeys);
	glutJoystickFunc(joystick, 250);
	glutMainLoop();
}
