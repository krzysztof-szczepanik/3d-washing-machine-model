#include "drum.hpp"
#include "globals.hpp"
#include "math.hpp"

#include <GLFW/glfw3.h>
#include <cmath>



// ================ HELPER FUNCTIONS =================

static void drawDrumInnerCylinder(double segments, double y) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5 + l; // front radius
	double front = 1.0 + m - l; // position on Z axis

	double r2 = 0.5; // rear radius
	double back = 0.5; // position on Z axis


	glBegin(GL_TRIANGLE_STRIP);

	for (angle = 0.0; angle < (2.0 * PI + 1e-6); angle += (PI / segments)) {
		// CALCULATE VERTEX X, Y COORDINATES:
		x1 = r2 * sin(angle);
		y1 = r2 * cos(angle);
		z1 = back;

		x2 = r1 * sin(angle);
		y2 = r1 * cos(angle);
		z2 = front;

		// TEMP VARS FOR NORMAL CALC (third vertex not drawn, calculable):
		x3 = r1 * sin(angle + (PI / segments));
		y3 = r1 * cos(angle + (PI / segments));
		z3 = front;

		glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

		computeNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		glNormal3d(-computedNormalX, -computedNormalY, -computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1 - y, z1);
		glVertex3d(x2, y2 - y, z2);
	}

	glEnd();
}

static void drawDrumBackLayer1(double segments, double y) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5; // front radius
	double front = 0.5; // position on Z axis

	double r2 = 0.5 - l; // rear radius
	double back = 0.5 - m; // position on Z axis


	glBegin(GL_TRIANGLE_STRIP);

	for (angle = 0.0; angle < (2.0 * PI + 1e-6); angle += (PI / segments)) {
		// CALCULATE VERTEX X, Y COORDINATES:
		x1 = r2 * sin(angle);
		y1 = r2 * cos(angle);
		z1 = back;

		x2 = r1 * sin(angle);
		y2 = r1 * cos(angle);
		z2 = front;

		// TEMP VARS FOR NORMAL CALC (third vertex not drawn, calculable):
		x3 = r1 * sin(angle + (PI / segments));
		y3 = r1 * cos(angle + (PI / segments));
		z3 = front;

		glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

		computeNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		glNormal3d(-computedNormalX, -computedNormalY, -computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1 - y, z1);
		glVertex3d(x2, y2 - y, z2);
	}

	glEnd();
}

static void drawDrumBackLayer2(double segments, double y) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5 - l; // front radius
	double front = 0.5 - m; // position on Z axis

	double r2 = 0.5 - l - m; // rear radius
	double back = 0.5 - m - m; // position on Z axis


	glBegin(GL_TRIANGLE_STRIP);

	for (angle = 0.0; angle < (2.0 * PI + 1e-6); angle += (PI / segments)) {
		// CALCULATE VERTEX X, Y COORDINATES:
		x1 = r2 * sin(angle);
		y1 = r2 * cos(angle);
		z1 = back;

		x2 = r1 * sin(angle);
		y2 = r1 * cos(angle);
		z2 = front;

		// TEMP VARS FOR NORMAL CALC (third vertex not drawn, calculable):
		x3 = r1 * sin(angle + (PI / segments));
		y3 = r1 * cos(angle + (PI / segments));
		z3 = front;

		glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

		computeNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		glNormal3d(-computedNormalX, -computedNormalY, -computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1 - y, z1);
		glVertex3d(x2, y2 - y, z2);
	}

	glEnd();
}

static void drawDrumBackLayer3(double segments, double y) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5 - l - m; // front radius
	double front = 0.5 - m - m; // position on Z axis

	double r2 = 0.0; // rear radius
	double back = 0.5 - m - m; // position on Z axis


	glBegin(GL_TRIANGLE_STRIP);

	for (angle = 0.0; angle < (2.0 * PI + 1e-6); angle += (PI / segments)) {
		// CALCULATE VERTEX X, Y COORDINATES:
		x1 = r2 * sin(angle);
		y1 = r2 * cos(angle);
		z1 = back;

		x2 = r1 * sin(angle);
		y2 = r1 * cos(angle);
		z2 = front;

		// TEMP VARS FOR NORMAL CALC (third vertex not drawn, calculable):
		x3 = r1 * sin(angle + (PI / segments));
		y3 = r1 * cos(angle + (PI / segments));
		z3 = front;

		glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

		computeNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		glNormal3d(-computedNormalX, -computedNormalY, -computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1 - y, z1);
		glVertex3d(x2, y2 - y, z2);
	}

	glEnd();
}

static void drawDrumRingBack(double segments, double y) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5; // front radius
	double front = 1.0 + m - l; // position on Z axis

	double r2 = 0.5 + l; // rear radius
	double back = 1.0 + m - l; // position on Z axis


	glBegin(GL_TRIANGLE_STRIP);

	for (angle = 0.0; angle < (2.0 * PI + 1e-6); angle += (PI / segments)) {
		// CALCULATE VERTEX X, Y COORDINATES:
		x1 = r2 * sin(angle);
		y1 = r2 * cos(angle);
		z1 = back;

		x2 = r1 * sin(angle);
		y2 = r1 * cos(angle);
		z2 = front;

		// TEMP VARS FOR NORMAL CALC (third vertex not drawn, calculable):
		x3 = r1 * sin(angle + (PI / segments));
		y3 = r1 * cos(angle + (PI / segments));
		z3 = front;

		glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

		computeNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		glNormal3d(-computedNormalX, -computedNormalY, -computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1 - y, z1);
		glVertex3d(x2, y2 - y, z2);
	}

	glEnd();
}

static void drawDrumRingInnerSide(double segments, double y) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5; // front radius
	double front = 1.0 + m + l; // position on Z axis

	double r2 = 0.5; // rear radius
	double back = 1.0 + m - l; // position on Z axis


	glBegin(GL_TRIANGLE_STRIP);

	for (angle = 0.0; angle < (2.0 * PI + 1e-6); angle += (PI / segments)) {
		// CALCULATE VERTEX X, Y COORDINATES:
		x1 = r2 * sin(angle);
		y1 = r2 * cos(angle);
		z1 = back;

		x2 = r1 * sin(angle);
		y2 = r1 * cos(angle);
		z2 = front;

		// TEMP VARS FOR NORMAL CALC (third vertex not drawn, calculable):
		x3 = r1 * sin(angle + (PI / segments));
		y3 = r1 * cos(angle + (PI / segments));
		z3 = front;

		glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

		computeNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		glNormal3d(-computedNormalX, -computedNormalY, -computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1 - y, z1);
		glVertex3d(x2, y2 - y, z2);
	}

	glEnd();
}

static void drawDrumRingFront(double segments, double y) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5; // front radius
	double front = 1.0 + m + l; // position on Z axis

	double r2 = 0.5 + m; // rear radius
	double back = 1.0 + m + l; // position on Z axis


	glBegin(GL_TRIANGLE_STRIP);

	for (angle = 0.0; angle < (2.0 * PI + 1e-6); angle += (PI / segments)) {
		// CALCULATE VERTEX X, Y COORDINATES:
		x1 = r2 * sin(angle);
		y1 = r2 * cos(angle);
		z1 = back;

		x2 = r1 * sin(angle);
		y2 = r1 * cos(angle);
		z2 = front;

		// TEMP VARS FOR NORMAL CALC (third vertex not drawn, calculable):
		x3 = r1 * sin(angle + (PI / segments));
		y3 = r1 * cos(angle + (PI / segments));
		z3 = front;

		glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

		computeNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		glNormal3d(computedNormalX, computedNormalY, computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1 - y, z1);
		glVertex3d(x2, y2 - y, z2);
	}

	glEnd();
}

static void drawDrumRingOuterSide(double segments, double y) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5 + m; // front radius
	double front = 1.0 + m + l; // position on Z axis

	double r2 = 0.5 + m; // rear radius
	double back = 1.0 + m; // position on Z axis


	glBegin(GL_TRIANGLE_STRIP);

	for (angle = 0.0; angle < (2.0 * PI + 1e-6); angle += (PI / segments)) {
		// CALCULATE VERTEX X, Y COORDINATES:
		x1 = r2 * sin(angle);
		y1 = r2 * cos(angle);
		z1 = back;

		x2 = r1 * sin(angle);
		y2 = r1 * cos(angle);
		z2 = front;

		// TEMP VARS FOR NORMAL CALC (third vertex not drawn, calculable):
		x3 = r1 * sin(angle + (PI / segments));
		y3 = r1 * cos(angle + (PI / segments));
		z3 = front;

		glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

		computeNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		glNormal3d(computedNormalX, computedNormalY, computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1 - y, z1);
		glVertex3d(x2, y2 - y, z2);
	}

	glEnd();
}



// ==================== FUNCTIONS ====================

void drawDrum() {
	double segments = 12.0; // number of radial segments (geometry detail)
	double y = 0.2;         // drum height adjustment

	drawDrumInnerCylinder(segments, y);
	drawDrumBackLayer1(segments, y);
	drawDrumBackLayer2(segments, y);
	drawDrumBackLayer3(segments, y);
	drawDrumRingBack(segments, y);
	drawDrumRingInnerSide(segments, y);
	drawDrumRingFront(segments, y);
	drawDrumRingOuterSide(segments, y);
}