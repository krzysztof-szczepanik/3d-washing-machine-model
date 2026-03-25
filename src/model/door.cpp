#include "door.hpp"
#include "globals.hpp"
#include "math.hpp"

#include <GLFW/glfw3.h>
#include <cmath>



// ================ HELPER FUNCTIONS =================

static void drawDoorGlassOuter(double segments, double alfa) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5 - m; // front radius
	double front = 0.0 - m; // position on Z axis

	double r2 = 0.5; // rear radius
	double back = 0.0; // position on Z axis


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

		glColor4d(167.0 / 228.0, 245.0 / 255.0, 255.0 / 245.0, alfa);

		computeNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		glNormal3d(computedNormalX, computedNormalY, computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1, z1);
		glVertex3d(x2, y2, z2);
	}

	glEnd();
}

static void drawDoorGlassMiddle(double segments, double alfa) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5 - m - m; // front radius
	double front = 0.0 - m - l; // position on Z axis

	double r2 = 0.5 - m; // rear radius
	double back = 0.0 - m; // position on Z axis


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

		glColor4d(167.0 / 228.0, 245.0 / 255.0, 255.0 / 245.0, alfa);

		computeNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		glNormal3d(computedNormalX, computedNormalY, computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1, z1);
		glVertex3d(x2, y2, z2);
	}

	glEnd();
}

static void drawDoorGlassInner(double segments, double alfa) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5 - m - m; // front radius
	double front = 0.0 - m - l; // position on Z axis

	double r2 = 0.0; // rear radius
	double back = 0.0 - m - l; // position on Z axis


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

		glColor4d(167.0 / 228.0, 245.0 / 255.0, 255.0 / 245.0, alfa);

		computeNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		glNormal3d(-computedNormalX, -computedNormalY, -computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1, z1);
		glVertex3d(x2, y2, z2);
	}

	glEnd();
}

static void drawDoorRingBack(double segments) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5 + m - 0.02; // front radius
	double front = 0.0 - (l / 2); // position on Z axis

	double r2 = 0.5 - 0.02; // rear radius
	double back = 0.0 - (l / 2); // position on Z axis


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
		glVertex3d(x1, y1, z1);
		glVertex3d(x2, y2, z2);
	}

	glEnd();
}

static void drawDoorRingInnerSide(double segments) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5 - 0.02; // front radius
	double front = 0.0 + (l / 2); // position on Z axis

	double r2 = 0.5 - 0.02; // rear radius
	double back = 0.0 - (l / 2); // position on Z axis


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
		glVertex3d(x1, y1, z1);
		glVertex3d(x2, y2, z2);
	}

	glEnd();
}

static void drawDoorRingFront(double segments) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5 - 0.02; // front radius
	double front = 0.0 + (l / 2); // position on Z axis

	double r2 = 0.5 + m - 0.02; // rear radius
	double back = 0.0 + (l / 2); // position on Z axis


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
		glVertex3d(x1, y1, z1);
		glVertex3d(x2, y2, z2);
	}

	glEnd();
}

static void drawDoorRingOuterSide(double segments) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset

	double r1 = 0.5 + m - 0.02; // front radius
	double front = 0.0 + (l / 2); // position on Z axis

	double r2 = 0.5 + m - 0.02; // rear radius
	double back = 0.0 - (l / 2); // position on Z axis


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
		glVertex3d(x1, y1, z1);
		glVertex3d(x2, y2, z2);
	}

	glEnd();
}



// ==================== FUNCTIONS ====================

void drawDoor() {
	double segments = 12.0; // number of radial segments (geometry detail)
	double alfa = 0.3;      // glass transparency

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	drawDoorGlassOuter(segments, alfa);
	drawDoorGlassMiddle(segments, alfa);
	drawDoorGlassInner(segments, alfa);
	glDisable(GL_BLEND);

	drawDoorRingBack(segments);
	drawDoorRingInnerSide(segments);
	drawDoorRingFront(segments);
	drawDoorRingOuterSide(segments);
}