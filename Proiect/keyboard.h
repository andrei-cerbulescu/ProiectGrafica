#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include "GameOver.h"
#include "./radio.h"

extern double ok, j, contor, timp;
int choice;
bool pressed;
int MAX_CHOICE = 2;
int DEADZONE = 500;

void miscasus(void)
{
	if (ok != 0)
	{
		mciSendString(L"close screetch", NULL, 0, NULL);
		mciSendString(L"open \".\\sunete\\screetch.wav\" type mpegvideo alias screetch", NULL, 0, NULL);
		mciSendString(L"play screetch", NULL, 0, NULL);
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
		mciSendString(L"close screetch", NULL, 0, NULL);
		mciSendString(L"open \".\\sunete\\screetch.wav\" type mpegvideo alias screetch", NULL, 0, NULL);
		mciSendString(L"play screetch", NULL, 0, NULL);
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

void handle_choice_left() {
	if (choice == 0)
		choice = MAX_CHOICE - 1;
	else
		choice = (choice - 1) % MAX_CHOICE;
}

void handle_choice_right() {
	choice = (choice + 1) % MAX_CHOICE;
}

void keyboardSpecialKeys(int key, int x, int y)
{
	switch (GameState::getInstance()->getState()) {
	case State::Game_Over: {
		switch (key) {
		case GLUT_KEY_LEFT:
			handle_choice_left();
			break;
		case GLUT_KEY_RIGHT:
			handle_choice_right();
			break;
		}
		break;
	}
	case State::Started: {
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
			case GLUT_KEY_PAGE_UP:
				schimba_canal(1);
				break;
			}
		break;
		}
	case State::Main_Menu: {
		switch (key) {
		case GLUT_KEY_LEFT:
			decrease_choice();
			break;
		case GLUT_KEY_RIGHT:
			increase_choice();
			break;
		}
		break;
	}
	}

}

void keyboardNormalKeys(unsigned char key, int x, int y) {
	switch (GameState::getInstance()->getState()) {
	case State::Game_Over: {
		switch (key) {
		case 13: handle_game_over_screen(); break;
		}
		break;
	}
	case State::Started: {
		break;
	}
	case State::Main_Menu: {
		switch (key) {
		case 13: handle_main_menu(); break;
		}
		break;
	}
	}
}
enum class Button_Direction { UP, DOWN, LEFT, RIGHT, SPECIAL_LEFT, SPECIAL_RIGHT, NONE };

Button_Direction get_direction(int x, int y) {
	if (abs(x) - abs(y) > 0) {
		if (x > DEADZONE) {
			return Button_Direction::RIGHT;
		}
		if (x < -DEADZONE) {
			return Button_Direction::LEFT;
		}
	}
	else {
		if (y > DEADZONE) {
			return Button_Direction::DOWN;
		}
		if (y < -DEADZONE) {
			return Button_Direction::UP;
		}
	}
	return Button_Direction::NONE;
}

void joystick(unsigned int buttonmask, int x, int y, int z)
{
	std::cout << buttonmask << " " << x << " " << y << " " << z << '\n';
	switch (GameState::getInstance()->getState()) {
	case State::Game_Over: {
		switch (get_direction(x, y)) {
		case Button_Direction::LEFT: {
			handle_choice_left();
			break;
		}
		case Button_Direction::RIGHT: {
			handle_choice_right();
			break;
		}
		}
		switch (buttonmask) {
			case GLUT_JOYSTICK_BUTTON_B:
				handle_game_over_screen(); break;
		}
		break;
	}
	case State::Started: {
		switch (get_direction(x, y)) {
		case Button_Direction::UP:
			miscasus();
			break;
		case Button_Direction::DOWN:
			miscajos();
			break;
		case Button_Direction::LEFT: {
			decelereaza();
			break;
		}
		case Button_Direction::RIGHT: {
			accelereaza();
			break;
		}
		}
		switch (buttonmask) {
		case 128:
			accelereaza();
			break;
		case 64:
			decelereaza();
			break;
		case 16:
			break;
		case 32:
			schimba_canal(1);
			break;
		}
		
		break;
	}
	case State::Main_Menu: {
		switch (get_direction(x, y)) {
		case Button_Direction::LEFT: {
			decrease_choice();
			break;
		}
		case Button_Direction::RIGHT: {
			increase_choice();
			break;
		}
		}
		switch (buttonmask) {
		case GLUT_JOYSTICK_BUTTON_B:
			handle_main_menu(); break;
		}
		break;
	}
	}
}