#pragma once
#include "Geometry.h"
class Circle : public Geometry {
private:
	int center_x, center_y;
	int r_radius;
	int pos_x, pos_y;
	float red=1.0f, green=0.0, blue=0.0;
	double dLength;
public:
	Circle(const int& _c_x, const int& _c_y, const int&_r_r) {
		initialize(_c_x, _c_y, _r_r);
	}

	void initialize(const int& _c_x, const int& _c_y, const int&_r_r) {
		center_x = _c_x;
		center_y = _c_y;
		r_radius = _r_r;
	}

	void draw() {
		/*dLength = sqrt((pos_x - center_x)*(pos_x - center_x) + (pos_y - center_y)*(pos_y - center_y));
		if (dLength <= r_radius) {
			red = 0.0f;
			green = 0.0f;
			blue = 1.0f;
		}
		else {
			red = 1.0f;
			green = 0.0f;
			blue = 0.0f;
		}*/
		for (int a = 0; a <= 2 * r_radius; a++)
		{
			for (int b = 0; b <= 2 * r_radius; b++)
			{
				int f = (r_radius - b)*(r_radius - b) + (r_radius - a)*(r_radius - a) - r_radius*r_radius;
				if (f < 0 && -200 < f)
				{
					drawPixel(center_x - r_radius + b, center_y - r_radius + a, red, green, blue);
				}
			}
		}
	}
};