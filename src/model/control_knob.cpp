#include "control_knob.hpp"
#include "globals.hpp"
#include "math.hpp"

#include <GLFW/glfw3.h>
#include <cmath>



// ================ HELPER FUNCTIONS =================

static void drawKnobRingInnerSide(double segments, double yOffset) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset
	double l2 = 0.02; // offset

	double r1 = 0.08; // front radius
	double front = 1.0 + m + l2; // position on Z axis

	double r2 = 0.08; // rear radius
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
		glNormal3d(-computedNormalX, -computedNormalY, -computedNormalZ);

		// DRAWING VERTICES:
		glVertex3d(x1, y1 - yOffset, z1);
		glVertex3d(x2, y2 - yOffset, z2);
	}

	glEnd();
}

static void drawKnobRingFront(double segments, double yOffset) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset
	double l2 = 0.02; // offset

	double r1 = 0.08; // front radius
	double front = 1.0 + m + l2; // position on Z axis

	double r2 = 0.05 + l; // rear radius
	double back = 1.0 + m + l2; // position on Z axis


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
		glVertex3d(x1, y1 - yOffset, z1);
		glVertex3d(x2, y2 - yOffset, z2);
	}

	glEnd();
}

static void drawKnobRingOuterSide(double segments, double yOffset) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset
	double l2 = 0.02; // offset

	double r1 = 0.05 + l; // front radius
	double front = 1.0 + m + l2; // position on Z axis

	double r2 = 0.05 + l; // rear radius
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
		glVertex3d(x1, y1 - yOffset, z1);
		glVertex3d(x2, y2 - yOffset, z2);
	}

	glEnd();
}

static void drawKnobFront(double segments, double yOffset) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset
	double l2 = 0.02; // offset

	double r1 = 0.0; // front radius
	double front = 1.0 + m + l; // position on Z axis

	double r2 = 0.08; // rear radius
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
		glNormal3d(0, 0, 1);

		// DRAWING VERTICES:
		glVertex3d(x1, y1 - yOffset, z1);
		glVertex3d(x2, y2 - yOffset, z2);
	}

	glEnd();
}

static void drawKnobOuterSide(double segments, double yOffset) {
	GLdouble x1, y1, z1, x2, y2, z2, x3, y3, z3, angle; // coordinate and angle values 

	double m = 0.1; // front wall center offset
	double l = 0.05; // offset
	double l2 = 0.02; // offset

	double r1 = 0.08; // front radius
	double front = 1.0 + m + l; // position on Z axis

	double r2 = 0.08; // rear radius
	double back = 1.0 + m + l2; // position on Z axis


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
		glVertex3d(x1, y1 - yOffset, z1);
		glVertex3d(x2, y2 - yOffset, z2);
	}

	glEnd();
}



// ==================== FUNCTIONS ====================

void drawControlKnob() {
	double segments = 12.0; // number of radial segments (geometry detail)
    double yOffset  = 0.0;  // vertical offset of the knob geometry

	drawKnobRingInnerSide(segments, yOffset);
	drawKnobRingFront(segments, yOffset);
	drawKnobRingOuterSide(segments, yOffset);
	drawKnobFront(segments, yOffset);
	drawKnobOuterSide(segments, yOffset);
}