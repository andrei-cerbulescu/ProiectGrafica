#pragma once
#include <vector>
double adjust_width_by = 100.0;
double adjust_heigth_by = 140.0;

template <class T>
T get_adjusted_width(T a) {
	return a - adjust_width_by;
}

template <class T>
T get_adjusted_heigth(T a) {
	return a - adjust_heigth_by;
}

enum class Tip_Chenar {Bila, Intreg};
class Text{
private:
	double x;
	double y;
	std::string text;
	Tip_Chenar chenar;
public:
	Text(double x, double y, std::string text, Tip_Chenar chenar = Tip_Chenar::Intreg) {
		this->x = x;
		this->y = y;
		this->text = text;
		this->chenar = chenar;
	}
	void deseneaza(float vals[]) {
		RenderString(this->x, this->y, GLUT_BITMAP_HELVETICA_18, this->text, vals);
		this->x + text.size() * 12;
	}
	void deseneaza() {
		float values[] = { 0.0f, 0.0f, 0.0f };
		this->deseneaza(values);
	}
	void deseneaza_cu_chenar(float vals[]) {
		glColor3f(1.0f, 0.0f, 0.0f);
		switch (chenar) {
			case Tip_Chenar::Intreg:
				glPushMatrix();
				glTranslated(this->x, this->y, 0.0);
				glRecti(0, 0, this->text.size() * 12, 18);
				glPopMatrix();
				break;
			case Tip_Chenar::Bila: {
				glPointSize(10.0f);
				glBegin(GL_POINTS);
				glVertex2f((this->x + this->sfarsit_desen()) / 2, this->y - 6);
				glEnd();
				break;
			}
		}
		deseneaza();

	}
	void deseneaza_cu_chenar() {
		float values[] = { 1.0f, 0.0f, 0.0f };
		this->deseneaza_cu_chenar(values);
	}
	double sfarsit_desen() {
		return this->x + this->text.size() * 12;
	}
};

class OptiuniOnScreen {
private:
	double diff;
	std::vector<Text> menu_list_options;
	double start_y;
	double start_x;
	int current_choice;
	Tip_Chenar chenar;
public:
	OptiuniOnScreen(double diff, double start_x, double start_y, Tip_Chenar chenar) {
		this->diff = diff;
		this->start_x = start_x;
		this->start_y = start_y;
		this->chenar = chenar;
	}
	void increase_choice() {
		current_choice = (current_choice + 1) % menu_list_options.size();
	}
	void decrease_choice() {
		if (current_choice == 0)
			current_choice = menu_list_options.size() - 1;
		else
			current_choice--;
	}
	void append_option(std::string what_to_draw) {
		double start;
		if (menu_list_options.empty())
			start = start_x;
		else
			start = menu_list_options[menu_list_options.size() - 1].sfarsit_desen();
		menu_list_options.push_back(*(new Text(start, start_y, what_to_draw, chenar)));
	}
	void display_menu() {
		for (int i = 0; i < menu_list_options.size(); i++) {
			if (i == current_choice) {
				menu_list_options[i].deseneaza_cu_chenar();
			}
			else {
				menu_list_options[i].deseneaza();
			}
		}
	}
	int get_current_size() {
		return menu_list_options.size();
	}
	int get_current_choice() { return current_choice; }
};