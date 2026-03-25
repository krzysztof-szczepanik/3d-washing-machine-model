#include "globals.hpp"
#include "input.hpp"
#include "display.hpp"
#include "lighting.hpp"
#include "projection.hpp"
#include "console.hpp"
#include "texture.hpp"

#include <GLFW/glfw3.h>
#include <cmath>

using namespace std;

int main(void) {
	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing

	window = glfwCreateWindow(1200, 1000, "3D Washing Machine Model", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	loadTextures();
	renderConsole();

	while (!glfwWindowShouldClose(window)) {
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		
		glfwSetKeyCallback(window, key_callback);

		applyProjection(width, height);

		glMatrixMode(GL_MODELVIEW);

		float squareSize = static_cast<float>(min(width, height)) * 0.2f;

		display(squareSize);

		glClearColor(1, 1, 1, 1);
		glfwSwapBuffers(window);

		glEnable(GL_LIGHT0);
		glEnable(GL_NORMALIZE);
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);

		// LIGHT0:
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
		glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

		// LIGHT1:
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0f); // spotlight with 60 degree opening angle
		glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0f); // spotlight concentration exponent
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
		glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_direction1);

		// LIGHT2:
		glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient2);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse2);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular2);
		glLightfv(GL_LIGHT2, GL_POSITION, light_position2);

		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // set texture environment mode

		glfwPollEvents();
	}

	glfwTerminate();
	glDeleteTextures(TEXTURE_COUNT, textureIDs); // delete texture objects

	return 0;
}
