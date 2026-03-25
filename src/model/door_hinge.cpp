#include "door_hinge.hpp"

#include <GLFW/glfw3.h>



// ==================== FUNCTIONS ====================

void drawDoorHinge() {
	double l = 0.05;
	double k = 0.025;
	double h = 0.1;

	glBegin(GL_QUADS);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

	// FRONT WALL:
	glNormal3d(0, 0, 1);
	glVertex3d(l, -l - h, l - k);
	glVertex3d(l, l + h, l - k);
	glVertex3d(-l + k, l + h, l - k);
	glVertex3d(-l + k, -l - h, l - k);

	// RIGHT WALL:
	glNormal3d(1, 0, 0);
	glVertex3d(l, -l - h, -l);
	glVertex3d(l, l + h, -l);
	glVertex3d(l, l + h, l - k);
	glVertex3d(l, -l - h, l - k);

	// LEFT WALL:
	glNormal3d(-1, 0, 0);
	glVertex3d(-l + k, -l - h, l - k);
	glVertex3d(-l + k, l + h, l - k);
	glVertex3d(-l, l + h, -l);
	glVertex3d(-l, -l - h, -l);

	// BOTTOM WALL:
	glNormal3d(0, -1, 0);
	glVertex3d(l, -l - h, -l);
	glVertex3d(l, -l - h, l - k);
	glVertex3d(-l + k, -l - h, l - k);
	glVertex3d(-l, -l - h, -l);

	// TOP WALL:
	glNormal3d(0, 1, 0);
	glVertex3d(l, l + h, l - k);
	glVertex3d(l, l + h, -l);
	glVertex3d(-l, l + h, -l);
	glVertex3d(-l + k, l + h, l - k);

	// BACK WALL:
	glNormal3d(0, 0, -1);
	glVertex3d(-l, -l - h, -l);
	glVertex3d(-l, l + h, -l);
	glVertex3d(l, l + h, -l);
	glVertex3d(l, -l - h, -l);

	glEnd();
}