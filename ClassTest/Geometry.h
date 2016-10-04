#pragma once
#include <iostream>
#include "DrawLine.h"
class Geometry {
public:
	virtual void draw() {
		std::cout << "Geometry Obj" << std::endl;
	}
};
