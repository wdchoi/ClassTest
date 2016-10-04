#pragma once
#include "Geometry.h"
class Box : public Geometry {
private:
	int center_x, center_y;
	int x_edge, y_edge;
public:
	Box(const int& _c_x, const int& _c_y, const int&_e_x, const int&_e_y) {
		initialize(_c_x, _c_y, _e_x, _e_y);
	}

	void initialize(const int& _c_x, const int& _c_y, const int&_e_x, const int&_e_y) {
		center_x = _c_x;
		center_y = _c_y;
		x_edge = _e_x;
		y_edge = _e_y;
	}
	void draw(){
	drawLine(center_x - x_edge / 2, center_y - y_edge / 2, center_x + x_edge / 2, center_y - y_edge / 2, 1.0f, 0.0f, 0.0f);
	drawLine(center_x + x_edge / 2, center_y - y_edge / 2, center_x + x_edge / 2, center_y + y_edge / 2, 1.0f, 0.0f, 0.0f);
	drawLine(center_x - x_edge / 2, center_y + y_edge / 2, center_x + x_edge / 2, center_y + y_edge / 2, 1.0f, 0.0f, 0.0f);
	drawLine(center_x - x_edge / 2, center_y - y_edge / 2, center_x - x_edge / 2, center_y + y_edge / 2, 1.0f, 0.0f, 0.0f);
}
};