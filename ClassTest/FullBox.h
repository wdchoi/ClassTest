#pragma once
#include "Geometry.h"
class FullBox : public Geometry {
private:
	int center_x, center_y;
	int thinkness;
public:
	FullBox(const int& _c_x, const int& _c_y, const int&_e_x) {
		initialize(_c_x, _c_y, _e_x);
	}

	void initialize(const int& _c_x, const int& _c_y, const int&_e_x) {
		center_x = _c_x;
		center_y = _c_y;
		thinkness = _e_x;
		
	}
	void draw() {
		for (int k = 0; k < 5; k++) {

			for (int j = center_y - thinkness; j < center_y + thinkness; j++)
				for (int i = center_x - thinkness; i < center_x + thinkness; i++) {
					drawPixel(i, j, 1.0f, 0.0f, 0.0f);
				}
		}
	}
};