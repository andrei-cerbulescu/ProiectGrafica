#pragma once
#include <stdio.h>
#include <fstream>
class GameData {
private:
    static GameData* instance;
    unsigned long prepare_application_start;
    unsigned long prepare_game_start;
    float score;
    unsigned int number_of_orders;
    unsigned long time_spent_total;
    unsigned long time_spent;
    std::string current_path;

    GameData() {
        prepare_application_start = std::time(0);
        if (load_data())
            return;
        score = 0;
        number_of_orders = 0;
        time_spent_total = 0;
        time_spent = 0;
        current_path = "save.dat";
    }

public:
    static GameData* getInstance() {
        if (!instance)
            instance = new GameData;
        return instance;
    }
    bool load_data(std::string path = "save.dat") {
        std::ifstream f;
        f.open(path);
        if (!f.is_open()) {
            printf("No save file detected.\n");
            return false;
        }
        this->current_path = path;
        f >> score >> number_of_orders >> time_spent_total >> time_spent;
        return true;
    }
    bool save_data() {
        save_time_spent_total();
        return save_data_to_file();
    }
    bool save_data_to_file() {
        std::ofstream f;
        f.open(this->current_path);
        if (!f.is_open()) {
            printf("Couldn't save.\n");
            return false;
        }
        f << score << " " << number_of_orders << " " << time_spent_total << " " << time_spent;
        printf("Saved.\n");
        return true;
    }
    void prepare_time_start() {
        prepare_game_start = std::time(0);
    }
    void save_time_spent_in_game() {
        time_spent += (std::time(0) - prepare_game_start);
    }
    void save_time_spent_total() {
        time_spent_total += (std::time(0) - prepare_application_start);
        prepare_application_start = (std::time(0));
    }
    void increase_orders(int val = 1) {
        number_of_orders += val;
    }
    void increase_score(float score = 0) {
        this->score += score;
    }
    float get_score() { return score; };
    unsigned int get_number_of_orders() { return number_of_orders; };
    unsigned long get_time_spent_total() { return time_spent_total; };
    unsigned long get_time_spent() { return time_spent; }
};
GameData* GameData::instance = 0;