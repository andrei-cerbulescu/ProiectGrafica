#pragma once
#include "radio.h"
enum class State { Started, Game_Over, Main_Menu };
enum class Reason { Police, Crash, Cold, None};

extern double ok;
extern double j;
extern double i;
extern double rsj, rdj, rss, rds;
extern double progres;
extern float temp_mancare;

class GameState {
private:
    static GameState* instance;
    State current_state;
    Reason game_over_reason;
    GameState() {
        this->setMainMenu();
    }

public:
    static GameState* getInstance() {
        if (!instance)
            instance = new GameState;
        return instance;
    }
    State getState() {
        return this->current_state;
    }
    Reason getGameOverReason() {
        return this->game_over_reason;
    }

    void setGameOver(Reason reason) {
        PlaySound(NULL, NULL, SND_ASYNC | SND_FILENAME);
        mciSendString(L"close sunet_ambient", NULL, 0, NULL);
        mciSendString(L"close radio", NULL, 0, NULL);
        this->game_over_reason = reason;
        this->current_state = State::Game_Over;
        mciSendString(L"open \".\\sunete\\game_over.mp3\" type mpegvideo alias game_over", NULL, 0, NULL);
        mciSendString(L"play game_over repeat", NULL, 0, NULL);
    }
    void setMainMenu() {
        PlaySound(NULL, NULL, SND_ASYNC | SND_FILENAME);
        mciSendString(L"close radio", NULL, 0, NULL);
        mciSendString(L"close game_over", NULL, 0, NULL);
        this->current_state = State::Main_Menu;
        PlaySound(L".\\sunete\\glovo.wav", NULL, SND_ASYNC | SND_FILENAME);
    }
    void setStartGame() {
        PlaySound(NULL, NULL, SND_ASYNC | SND_FILENAME);
        mciSendString(L"close game_over", NULL, 0, NULL);
        mciSendString(L"open \".\\sunete\\trafic.mp3\" type mpegvideo alias sunet_ambient", NULL, 0, NULL);
        mciSendString(L"play sunet_ambient repeat", NULL, 0, NULL);
        schimba_muzica();
        rsj = 0; rdj = 0; rss = 0; rds = 0.0; j = 0.0; ok = 1; progres = 0; temp_mancare = 100;  this->current_state = State::Started;
    }

    static void quitGame() {
        glutLeaveMainLoop();
    }

};
GameState* GameState::instance = 0;

