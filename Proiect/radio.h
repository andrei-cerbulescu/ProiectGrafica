#pragma once
#include <GL/freeglut.h>
#include "./texte.h"
#include <string>
#pragma comment(lib, "Winmm.lib")

int id_canal = 0;
int decalaj = 0;
double radio_timer = 0;
int dim_decalaj = 12;
bool muzica_pornita = true;

void schimba_canal(int val) {
	id_canal += val;
	decalaj = 0;
	muzica_pornita = false;
}

void schimba_muzica() {
	PlaySound(NULL, NULL, SND_ASYNC | SND_FILENAME);
	mciSendString(L"close radio", NULL, 0, NULL);
	switch (id_canal) {
	case 1:
		mciSendString(L"open \".\\sunete\\kiss_fm.wav\" type mpegvideo alias radio", NULL, 0, NULL);
		mciSendString(L"play radio", NULL, 0, NULL);
		break;
	case 2:
		mciSendString(L"open \".\\sunete\\taraf.wav\" type mpegvideo alias radio", NULL, 0, NULL);
		mciSendString(L"play radio", NULL, 0, NULL);
		//PlaySound(L".\\sunete\\taraf.wav", NULL, SND_ASYNC | SND_FILENAME);
		break;
	}

}

void deseneaza_radio() {
	glColor3f(0.55, 0.788, 0.451);
	std::string radio = "Radio: ";
	std::string canal = "";
	if (id_canal > 2) {
		id_canal = 0;
	}
	switch (id_canal) {
	case 0:
		canal = "oprit";
		break;
	case 1:
		canal = "Kiss FM";
		break;
	case 2:
		canal = "Taraf";
		break;
	default:
		canal = "oprit";
		break;
	}
	radio_timer += 0.01;
	if (radio_timer > 10) {
		radio_timer = 0;
		decalaj += 1;
		if (decalaj >= dim_decalaj) {
			decalaj = -5;
		}
	}
	std::string canal_decalat = "";
	for (int i = 0; i < decalaj; i++) {
		canal_decalat += " ";
	}
	canal_decalat += canal;
	if (decalaj >= 0) {
		radio = radio + canal_decalat.substr(0, dim_decalaj - 2);
	}
	else {
		radio = radio + canal_decalat.substr(-decalaj, canal_decalat.length());
	}
	if (!muzica_pornita) {
		schimba_muzica();
		muzica_pornita = true;
	}
	RenderString(0.0f, 425.0f, GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)radio.c_str());
}