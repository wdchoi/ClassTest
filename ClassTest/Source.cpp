#include <GLFW/glfw3.h>
#include "math.h"
#include <iostream>
#include <vector>
#include "Geometry.h"
#include "Box.h"
#include "Circle.h"
#include "Line.h"
#include "Polygon.h"
#include "Triangle.h"
#include "FullBox.h"


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		//assign all pixels red color 
		for (int j = 0; j < height; j++)
			for (int i = 0; i < width; i++) {
				pixels[(i + width*j) * 3 + 0] = 1.0f;
				pixels[(i + width*j) * 3 + 1] = 1.0f;
				pixels[(i + width*j) * 3 + 2] = 1.0f;
			}



		std::vector<Geometry*> go_vector;
		Geometry * temp = nullptr;
		int k = 0;
		for (int i = 0; i < 6; i++) {
			if (i < 3) {
				temp = new Circle(75 + i * 225, 375, 60);
			}
			else {
				
				temp = new Circle(75 + k * 225, 150, 60);
				k += 1;
			}
			go_vector.push_back(temp);
		}

		go_vector.push_back(new Box(75,375,50,50));
		go_vector.push_back(new Line(265, 345, 330, 410));
		go_vector.push_back(new Polygon(250, 150, 300, 200));
		go_vector.push_back(new Circle(75, 150, 30));
		go_vector.push_back(new Triangle(485, 120,525, 200));
		go_vector.push_back(new FullBox(525, 375, 40));
		for (auto itr : go_vector) {
		(itr)->draw();
		}
		


		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);


		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		std::cout << xpos << "   " << 480 - ypos << std::endl;
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	delete[] pixels;
	//free(pixels);
	return 0;
}