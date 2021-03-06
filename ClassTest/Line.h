#pragma once
#include "Geometry.h"
class Line : public Geometry
{
private:
	int start_x, start_y;
	int end_x, end_y;
public:
	Line(const int& _start_x, const int & _start_y, const int& _end_x, const int& _end_y) {
		initialize(_start_x, _start_y, _end_x, _end_y);
	}
	void initialize(const int& _start_x, const int & _start_y, const int& _end_x, const int& _end_y) {
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}
	void draw() {
		drawLine(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
	}
};
