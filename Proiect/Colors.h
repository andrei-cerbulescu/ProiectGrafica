#pragma once
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <random>
enum class Mode{Normal, Alternative, Random};
enum class Shade{Green, Black, Blue, Yellow, White, Orange, Very_Light_Blue, Grass, Player_Car, Enemy_Car, Red, Radio, Background};
class Colors{
	static Colors* instance;
	std::mt19937 g1;
	unsigned int seed;
	Mode color_mode;
	Colors() {
		color_mode = Mode::Normal;
		changeSeed();
	}
public:
	static Colors* getInstance() {
		if (!instance)
			instance = new Colors();
		return instance;
	}
	void setMode(Mode mode) {
		this->color_mode = mode;
	}
	float* getColor(Shade shade, bool ignoreEffects = true) {
		float aux[3] = { 0.0f, 0.0f, 0.0f };
		if (color_mode == Mode::Random && ignoreEffects) {
			aux[0] = (float) (g1() % 10 / 10.0f);
			aux[1] = (float) (g1() % 10 / 10.0f);
			aux[2] = (float) (g1() % 10 / 10.0f);
			return aux;
		}
		switch (shade) {
		case Shade::Black: aux[0] = 0.0f; aux[1] = 0.0f, aux[2] = 0.0f; break;
		case Shade::Yellow: aux[0] = 1.0f; aux[1] = 1.0f, aux[2] = 0.0f; break;
		case Shade::White: aux[0] = 1.0f; aux[1] = 1.0f, aux[2] = 1.0f; break;
		case Shade::Orange: aux[0] = 1.0f; aux[1] = 0.4f, aux[2] = 0.0f; break;
		case Shade::Very_Light_Blue: aux[0] = 0.0f; aux[1] = 1.0f, aux[2] = 1.0f; break;
		case Shade::Grass: aux[0] = 0.55f; aux[1] = 0.788f, aux[2] = 0.451f; break;
		case Shade::Player_Car: aux[0] = 0.996f; aux[1] = 0.365f, aux[2] = 0.149f; break;
		case Shade::Enemy_Car: aux[0] = 0.471f; aux[1] = 0.667f, aux[2] = 0.949f; break;
		case Shade::Red: aux[0] = 1.0f; aux[1] = 0.0f, aux[2] = 0.0f; break;
		case Shade::Radio: aux[0] = 0.55f; aux[1] = 0.788f, aux[2] = 0.451f; break;
		case Shade::Background: aux[0] = 0.98f; aux[1] = 0.929f, aux[2] = 0.792f; break;
		}
		if (color_mode == Mode::Alternative && ignoreEffects) {
			aux[0] = 1.0f - aux[0];
			aux[1] = 1.0f - aux[1];
			aux[2] = 1.0f - aux[2];
		}
		return aux;


	}
	void changeSeed() {
		seed = time(0);
		setSeed();
	}
	void setSeed() {
		g1.seed(seed);
	}
};
Colors* Colors::instance = 0;