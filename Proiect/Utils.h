#pragma once
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