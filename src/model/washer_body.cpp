#include "washer_body.hpp"
#include "globals.hpp"
#include "math.hpp"

#include <GLFW/glfw3.h>
#include <cmath>



// ==================== FUNCTIONS ====================

void drawWasherFrontWall(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4) {
	double n = 0.1; // edge and corner width
	double m = 0.1; // center offset
	double l = 0.05; // variable to adjust rounding sharpness vs smoothness
	
	// DRUM VARIABLES:
	double r = 0.5 + m; // drum radius
	double rRest = 0.9 - r; // remainder after subtracting drum radius from center wall width
	double angle = 12.0; // angle helper for center corners (same as drum)
	double y = 0.2; // drum height adjustment

	// TOP PANEL VARIABLES:
	double ph = rRest + m + 0.025; // top panel height
	double po = 0.025; // top panel offset from center wall
	double poh = 0.1; // height offset
	double pos = 0.1; // width offset

	// SCREEN VARIABLES:
	double es = 0.5; // screen width
	double ems = 0.035; // width margin
	double emh = 0.035; // height margin
	double eg = 0.005; // screen depth

	// DRUM CAVITY VARIABLES:
	double zs = 0.5; // drum cavity width
	double zg = 0.6; // drum cavity depth

	// CENTER BUTTON VARIABLES:
	double rp = 0.1; // button radius
	double k = 0.2; // button offset (screen edge to center / drum edge to center)
	double ppy = (1.0 - 0.1 - ((0.9 - (0.5 + 0.1)) + 0.1 + 0.025) + 0.1) - (((1.0 - 0.1 - ((0.9 - (0.5 + 0.1)) + 0.1 + 0.025) + 0.1) - (1.0 - 0.1 - 0.1)) / 2.0);

	glBegin(GL_QUADS);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	

	// CENTER:

	// TOP PANEL - FRONT RIGHT:
	glNormal3d(0, 0, 1);
	glVertex3d(x2 - n, y2 - n - ph + poh, z2 + m + po);
	glVertex3d(x2 - n, y2 - n - poh, z2 + m + po);
	glVertex3d(x2 - n - pos, y2 - n - poh, z2 + m + po);
	glVertex3d(x2 - n - pos, y2 - n - ph + poh, z2 + m + po);

	// TOP PANEL - FRONT TOP:
	glNormal3d(0, 0, 1);
	glVertex3d(x2 - n, y2 - n - poh, z2 + m + po);
	glVertex3d(x2 - n, y2 - n, z2 + m + po);
	glVertex3d(x3 + n, y3 - n, z3 + m + po);
	glVertex3d(x3 + n, y3 - n - poh, z3 + m + po);

	// TOP PANEL - FRONT LEFT:
	glNormal3d(0, 0, 1);
	glVertex3d(x3 + n + pos, y3 - n - ph + poh, z3 + m + po);
	glVertex3d(x3 + n + pos, y3 - n - poh, z3 + m + po);
	glVertex3d(x3 + n, y3 - n - poh, z3 + m + po);
	glVertex3d(x3 + n, y3 - n - ph + poh, z3 + m + po);

	// TOP PANEL - FRONT BOTTOM:
	glNormal3d(0, 0, 1);
	glVertex3d(x2 - n, y2 - n - ph, z2 + m + po);
	glVertex3d(x2 - n, y2 - n - ph + poh, z2 + m + po);
	glVertex3d(x3 + n, y3 - n - ph + poh, z3 + m + po);
	glVertex3d(x3 + n, y3 - n - ph, z3 + m + po);

	// TOP PANEL - FRONT CENTER RIGHT:
	glNormal3d(0, 0, 1);
	glVertex3d(x2 - n - pos - es, y2 - n - ph + poh, z2 + m + po);
	glVertex3d(x2 - n - pos - es, y2 - n - poh, z2 + m + po);
	glVertex3d(x2 - n - pos - es - k, y2 - n - poh, z2 + m + po);
	glVertex3d(x2 - n - pos - es - k, y2 - n - ph + poh, z2 + m + po);

	// TOP PANEL - FRONT CENTER TOP:
	glNormal3d(0, 0, 1);
	glVertex3d(x2 - n - pos - es - k, y2 - n - poh - 0.0125, z2 + m + po);
	glVertex3d(x2 - n - pos - es - k, y2 - n - poh, z2 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - poh, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - poh - 0.0125, z3 + m + po);

	// TOP PANEL - FRONT CENTER LEFT:
	glNormal3d(0, 0, 1);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - ph + poh, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - poh, z3 + m + po);
	glVertex3d(x3 + n + pos + zs, y3 - n - poh, z3 + m + po);
	glVertex3d(x3 + n + pos + zs, y3 - n - ph + poh, z3 + m + po);

	// TOP PANEL - FRONT CENTER BOTTOM:
	glNormal3d(0, 0, 1);
	glVertex3d(x2 - n - pos - es - k, y2 - n - ph + poh, z2 + m + po);
	glVertex3d(x2 - n - pos - es - k, y2 - n - ph + poh + 0.0125, z2 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - ph + poh + 0.0125, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - ph + poh, z3 + m + po);

	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glNormal3d(0, 0, 1);

	// BUTTON CORNERS:

	// RIGHT BOTTOM:
	glVertex3d(x2 - n - pos - es - k, y2 - n - ph + poh + 0.0125, z2 + m + po);
	glVertex3d(rp * sin(6 * (PI / angle)), (rp * cos(6 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp * sin(7 * (PI / angle)), (rp * cos(7 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(x2 - n - pos - es - k, y2 - n - ph + poh + 0.0125, z2 + m + po);
	glVertex3d(rp * sin(7 * (PI / angle)), (rp * cos(7 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp * sin(8 * (PI / angle)), (rp * cos(8 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(x2 - n - pos - es - k, y2 - n - ph + poh + 0.0125, z2 + m + po);
	glVertex3d(rp * sin(8 * (PI / angle)), (rp * cos(8 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp * sin(9 * (PI / angle)), (rp * cos(9 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(x2 - n - pos - es - k, y2 - n - ph + poh + 0.0125, z2 + m + po);
	glVertex3d(rp * sin(9 * (PI / angle)), (rp * cos(9 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp * sin(10 * (PI / angle)), (rp * cos(10 * (PI / angle)) + ppy), z3 + m + po);

	glVertex3d(x2 - n - pos - es - k, y2 - n - ph + poh + 0.0125, z2 + m + po);
	glVertex3d(rp * sin(10 * (PI / angle)), (rp * cos(10 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp * sin(11 * (PI / angle)), (rp * cos(11 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(x2 - n - pos - es - k, y2 - n - ph + poh + 0.0125, z2 + m + po);
	glVertex3d(rp * sin(11 * (PI / angle)), (rp * cos(11 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp * sin(12 * (PI / angle)), (rp * cos(12 * (PI / angle))) + ppy, z3 + m + po);

	// RIGHT TOP:
	glVertex3d(rp* sin(6 * (PI / angle)), (rp* cos(6 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x2 - n - pos - es - k, y2 - n - poh - 0.0125, z2 + m + po);
	glVertex3d(rp* sin(5 * (PI / angle)), (rp* cos(5 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(rp* sin(5 * (PI / angle)), (rp* cos(5 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x2 - n - pos - es - k, y2 - n - poh - 0.0125, z2 + m + po);
	glVertex3d(rp* sin(4 * (PI / angle)), (rp* cos(4 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(rp* sin(4 * (PI / angle)), (rp* cos(4 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x2 - n - pos - es - k, y2 - n - poh - 0.0125, z2 + m + po);
	glVertex3d(rp* sin(3 * (PI / angle)), (rp* cos(3 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(rp* sin(3 * (PI / angle)), (rp* cos(3 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x2 - n - pos - es - k, y2 - n - poh - 0.0125, z2 + m + po);
	glVertex3d(rp* sin(2 * (PI / angle)), (rp* cos(2 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(rp* sin(2 * (PI / angle)), (rp* cos(2 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x2 - n - pos - es - k, y2 - n - poh - 0.0125, z2 + m + po);
	glVertex3d(rp* sin(1 * (PI / angle)), (rp* cos(1 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(rp* sin(1 * (PI / angle)), (rp* cos(1 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x2 - n - pos - es - k, y2 - n - poh - 0.0125, z2 + m + po);
	glVertex3d(rp* sin(0 * (PI / angle)), (rp* cos(0 * (PI / angle))) + ppy, z3 + m + po);

	// LEFT TOP:
	glVertex3d(rp* sin(19 * (PI / angle)), (rp* cos(19 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - poh - 0.0125, z3 + m + po);
	glVertex3d(rp* sin(18 * (PI / angle)), (rp* cos(18 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(rp* sin(20 * (PI / angle)), (rp* cos(20 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - poh - 0.0125, z3 + m + po);
	glVertex3d(rp* sin(19 * (PI / angle)), (rp* cos(19 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(rp* sin(21 * (PI / angle)), (rp* cos(21 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - poh - 0.0125, z3 + m + po);
	glVertex3d(rp* sin(20 * (PI / angle)), (rp* cos(20 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(rp* sin(22 * (PI / angle)), (rp* cos(22 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - poh - 0.0125, z3 + m + po);
	glVertex3d(rp* sin(21 * (PI / angle)), (rp* cos(21 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(rp* sin(23 * (PI / angle)), (rp* cos(23 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - poh - 0.0125, z3 + m + po);
	glVertex3d(rp* sin(22 * (PI / angle)), (rp* cos(22 * (PI / angle))) + ppy, z3 + m + po);

	glVertex3d(rp* sin(24 * (PI / angle)), (rp* cos(24 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - poh - 0.0125, z3 + m + po);
	glVertex3d(rp* sin(23 * (PI / angle)), (rp* cos(23 * (PI / angle))) + ppy, z3 + m + po);

	// LEFT BOTTOM:
	glVertex3d(rp* sin(12 * (PI / angle)), (rp* cos(12 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp* sin(13 * (PI / angle)), (rp* cos(13 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - ph + poh + 0.0125, z3 + m + po);

	glVertex3d(rp* sin(13 * (PI / angle)), (rp* cos(13 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp* sin(14 * (PI / angle)), (rp* cos(14 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - ph + poh + 0.0125, z3 + m + po);

	glVertex3d(rp* sin(14 * (PI / angle)), (rp* cos(14 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp* sin(15 * (PI / angle)), (rp* cos(15 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - ph + poh + 0.0125, z3 + m + po);

	glVertex3d(rp* sin(15 * (PI / angle)), (rp* cos(15 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp* sin(16 * (PI / angle)), (rp* cos(16 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - ph + poh + 0.0125, z3 + m + po);

	glVertex3d(rp* sin(16 * (PI / angle)), (rp* cos(16 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp* sin(17 * (PI / angle)), (rp* cos(17 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - ph + poh + 0.0125, z3 + m + po);

	glVertex3d(rp* sin(17 * (PI / angle)), (rp* cos(17 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(rp* sin(18 * (PI / angle)), (rp* cos(18 * (PI / angle))) + ppy, z3 + m + po);
	glVertex3d(x3 + n + pos + zs + k, y3 - n - ph + poh + 0.0125, z3 + m + po);

	glEnd();


	if (washerDisplayOn) {
		GLfloat emission[] = {1.0f, 1.0f, 1.0f, 1.0f}; // screen emission color setup
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
	}
	
	glBegin(GL_QUADS);
	glColor3d(200.0 / 255.0, 200.0 / 255.0, 200.0 / 255.0);

	// TOP PANEL - FRONT (SCREEN - BACK WALL):
	glNormal3d(0, 0, 1);
	glVertex3d(x2 - n - pos - ems, y2 - n - ph + poh + emh, z2 + m + po - eg);
	glVertex3d(x2 - n - pos - ems, y2 - n - poh - emh, z2 + m + po - eg);
	glVertex3d(x2 - n - pos - es + ems, y2 - n - poh - emh, z2 + m + po - eg);
	glVertex3d(x2 - n - pos - es + ems, y2 - n - ph + poh + emh, z2 + m + po - eg);

	glEnd();

	if (washerDisplayOn) {
		GLfloat noEmission[] = {0.0f, 0.0f, 0.0f, 1.0f};
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, noEmission);
	}
	

	glBegin(GL_QUADS);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

	// TOP PANEL - FRONT (SCREEN - RIGHT WALL):
	computeNormal(x2 - n - pos, y2 - n - ph + poh, z2 + m + po, x2 - n - pos, y2 - n - poh, z2 + m + po, x2 - n - pos - ems, y2 - n - poh - emh, z2 + m + po - eg); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(x2 - n - pos, y2 - n - ph + poh, z2 + m + po);
	glVertex3d(x2 - n - pos, y2 - n - poh, z2 + m + po);
	glVertex3d(x2 - n - pos - ems, y2 - n - poh - emh, z2 + m + po - eg);
	glVertex3d(x2 - n - pos - ems, y2 - n - ph + poh + emh, z2 + m + po - eg);

	// TOP PANEL - FRONT (SCREEN - TOP WALL):
	computeNormal(x2 - n - pos - ems, y2 - n - poh - emh, z2 + m + po - eg, x2 - n - pos, y2 - n - poh, z2 + m + po, x2 - n - pos - es, y2 - n - poh, z2 + m + po); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(x2 - n - pos - ems, y2 - n - poh - emh, z2 + m + po - eg);
	glVertex3d(x2 - n - pos, y2 - n - poh, z2 + m + po);
	glVertex3d(x2 - n - pos - es, y2 - n - poh, z2 + m + po);
	glVertex3d(x2 - n - pos - es + ems, y2 - n - poh - emh, z2 + m + po - eg);

	// TOP PANEL - FRONT (SCREEN - LEFT WALL):
	computeNormal(x2 - n - pos - es + ems, y2 - n - ph + poh + emh, z2 + m + po - eg, x2 - n - pos - es + ems, y2 - n - poh - emh, z2 + m + po - eg, x2 - n - pos - es, y2 - n - poh, z2 + m + po); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(x2 - n - pos - es + ems, y2 - n - ph + poh + emh, z2 + m + po - eg);
	glVertex3d(x2 - n - pos - es + ems, y2 - n - poh - emh, z2 + m + po - eg);
	glVertex3d(x2 - n - pos - es, y2 - n - poh, z2 + m + po);
	glVertex3d(x2 - n - pos - es, y2 - n - ph + poh, z2 + m + po);

	// TOP PANEL - FRONT (SCREEN - BOTTOM WALL):
	computeNormal(x2 - n - pos, y2 - n - ph + poh, z2 + m + po, x2 - n - pos - ems, y2 - n - ph + poh + emh, z2 + m + po - eg, x2 - n - pos - es + ems, y2 - n - ph + poh + emh, z2 + m + po - eg); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(x2 - n - pos, y2 - n - ph + poh, z2 + m + po);
	glVertex3d(x2 - n - pos - ems, y2 - n - ph + poh + emh, z2 + m + po - eg);
	glVertex3d(x2 - n - pos - es + ems, y2 - n - ph + poh + emh, z2 + m + po - eg);
	glVertex3d(x2 - n - pos - es, y2 - n - ph + poh, z2 + m + po);


	// TOP PANEL - FRONT (DRUM - BACK WALL):
	glNormal3d(0, 0, 1);
	glVertex3d(x3 + n + pos + zs, y3 - n - ph + poh, z3 + m + po - zg);
	glVertex3d(x3 + n + pos + zs, y3 - n - poh, z3 + m + po - zg);
	glVertex3d(x3 + n + pos, y3 - n - poh, z3 + m + po - zg);
	glVertex3d(x3 + n + pos, y3 - n - ph + poh, z3 + m + po - zg);

	// TOP PANEL - FRONT (DRUM - RIGHT WALL):
	glNormal3d(-1, 0, 0);
	glVertex3d(x3 + n + pos + zs, y3 - n - ph + poh, z3 + m + po);
	glVertex3d(x3 + n + pos + zs, y3 - n - poh, z3 + m + po);
	glVertex3d(x3 + n + pos + zs, y3 - n - poh, z3 + m + po - zg);
	glVertex3d(x3 + n + pos + zs, y3 - n - ph + poh, z3 + m + po - zg);

	// TOP PANEL - FRONT (DRUM - TOP WALL):
	glNormal3d(0, -1, 0);
	glVertex3d(x3 + n + pos + zs, y3 - n - poh, z3 + m + po - zg);
	glVertex3d(x3 + n + pos + zs, y3 - n - poh, z3 + m + po);
	glVertex3d(x3 + n + pos, y3 - n - poh, z3 + m + po);
	glVertex3d(x3 + n + pos, y3 - n - poh, z3 + m + po - zg);

	// TOP PANEL - FRONT (DRUM - LEFT WALL):
	glNormal3d(1, 0, 0);
	glVertex3d(x3 + n + pos, y3 - n - ph + poh, z3 + m + po - zg);
	glVertex3d(x3 + n + pos, y3 - n - poh, z3 + m + po - zg);
	glVertex3d(x3 + n + pos, y3 - n - poh, z3 + m + po);
	glVertex3d(x3 + n + pos, y3 - n - ph + poh, z3 + m + po);
	
	// TOP PANEL - FRONT (DRUM - BOTTOM WALL):
	glNormal3d(0, 1, 0);
	glVertex3d(x3 + n + pos + zs, y3 - n - ph + poh, z3 + m + po);
	glVertex3d(x3 + n + pos + zs, y3 - n - ph + poh, z3 + m + po - zg);
	glVertex3d(x3 + n + pos, y3 - n - ph + poh, z3 + m + po - zg);
	glVertex3d(x3 + n + pos, y3 - n - ph + poh, z3 + m + po);


	// TOP PANEL - RIGHT EDGE:
	glNormal3d(1, 0, 0);
	glVertex3d(x2 - n, y2 - n - ph, z2 + m);
	glVertex3d(x2 - n, y2 - n, z2 + m);
	glVertex3d(x2 - n, y2 - n, z2 + m + po);
	glVertex3d(x2 - n, y2 - n - ph, z2 + m + po);

	// TOP PANEL - TOP EDGE:
	glNormal3d(0, 1, 0);
	glVertex3d(x2 - n, y2 - n, z2 + m + po);
	glVertex3d(x2 - n, y2 - n, z2 + m);
	glVertex3d(x3 + n, y3 - n, z3 + m);
	glVertex3d(x3 + n, y3 - n, z3 + m + po);

	// TOP PANEL - LEFT EDGE:
	glNormal3d(-1, 0, 0);
	glVertex3d(x3 + n, y3 - n - ph, z3 + m + po);
	glVertex3d(x3 + n, y3 - n, z3 + m + po);
	glVertex3d(x3 + n, y3 - n, z3 + m);
	glVertex3d(x3 + n, y3 - n - ph, z3 + m);

	// TOP PANEL - BOTTOM EDGE:
	glNormal3d(0, -1, 0);
	glVertex3d(x2 - n, y2 - n - ph, z2 + m);
	glVertex3d(x2 - n, y2 - n - ph, z2 + m + po);
	glVertex3d(x3 + n, y3 - n - ph, z3 + m + po);
	glVertex3d(x3 + n, y3 - n - ph, z3 + m);


	// RIGHT CENTER:
	glNormal3d(0, 0, 1);
	glVertex3d(x1 - n, y1 + n, z1 + m);
	glVertex3d(x2 - n, y2 - n - ph, z2 + m);
	glVertex3d(x2 - n - rRest, y2 - n - ph, z2 + m);
	glVertex3d(x1 - n - rRest, y1 + n, z1 + m);

	// TOP CENTER:
	glNormal3d(0, 0, 1);
	glVertex3d(x2 - n - rRest, y2 - n - rRest - y, z2 + m);
	glVertex3d(x2 - n - rRest, y2 - n - ph, z2 + m);
	glVertex3d(x3 + n + rRest, y3 - n - ph, z3 + m);
	glVertex3d(x3 + n + rRest, y3 - n - rRest - y, z3 + m);
	
	// LEFT CENTER:
	glNormal3d(0, 0, 1);
	glVertex3d(x4 + n + rRest, y4 + n, z4 + m);
	glVertex3d(x3 + n + rRest, y3 - n - ph, z3 + m);
	glVertex3d(x3 + n, y3 - n - ph, z3 + m);
	glVertex3d(x4 + n, y4 + n, z4 + m);
	
	// BOTTOM CENTER:
	glNormal3d(0, 0, 1);
	glVertex3d(x1 - n - rRest, y1 + n, z1 + m);
	glVertex3d(x1 - n - rRest, y1 + n + rRest - y, z1 + m);
	glVertex3d(x4 + n + rRest, y4 + n + rRest - y, z4 + m);
	glVertex3d(x4 + n + rRest, y4 + n, z4 + m);


	// CORNERS:

	// RIGHT BOTTOM:
	//computeNormal(x1, y1 - l, z1, x1 + l, y1 + n, z1 + l, x1 - n, y1 + n, z1 + m); // ABC
	glNormal3d(0.291386, -0.388514, 0.874157);
	glVertex3d(x1, y1 - l, z1);
	glVertex3d(x1 + l, y1 + n, z1 + l);
	glVertex3d(x1 - n, y1 + n, z1 + m);
	glVertex3d(x1 - n, y1 - l, z1 + l);

	// RIGHT TOP:
	//computeNormal(x2 + l, y2 - n, z2 + l, x2, y2 + l, z2, x2 - n, y2 + l, z2 + l); // ABC
	glNormal3d(0.408248, 0.408248, 0.816497);
	glVertex3d(x2 + l, y2 - n, z2 + l);
	glVertex3d(x2, y2 + l, z2);
	glVertex3d(x2 - n, y2 + l, z2 + l);
	glVertex3d(x2 - n, y2 - n, z2 + m);

	// LEFT TOP:
	//computeNormal(x3 + n, y3 - n, z3 + m, x3 + n, y3 + l, z3 + l, x3, y3 + l, z3); // ABC
	glNormal3d(-0.428571, 0.285714, 0.857143);
	glVertex3d(x3 + n, y3 - n, z3 + m);
	glVertex3d(x3 + n, y3 + l, z3 + l);
	glVertex3d(x3, y3 + l, z3);
	glVertex3d(x3 - l, y3 - n, z3 + l);

	// LEFT BOTTOM:
	//computeNormal(x4 + n, y4 - l, z4 + l, x4 + n, y4 + n, z4 + m, x4 - l, y4 + n, z4 + l); // ABC
	glNormal3d(-0.301511, -0.301511, 0.904534);
	glVertex3d(x4 + n, y4 - l, z4 + l);
	glVertex3d(x4 + n, y4 + n, z4 + m);
	glVertex3d(x4 - l, y4 + n, z4 + l);
	glVertex3d(x4, y4 - l, z4);


	// EDGES:

	// PRAWA:
	//computeNormal(x1 + l, y1 + n, z1 + l, x2 + l, y2 - n, z2 + l, x2 - n, y2 - n, z2 + m); // ABC
	glNormal3d(0.316228, 0, 0.948683);
	glVertex3d(x1 + l, y1 + n, z1 + l);
	glVertex3d(x2 + l, y2 - n, z2 + l);
	glVertex3d(x2 - n, y2 - n, z2 + m);
	glVertex3d(x1 - n, y1 + n, z1 + m);

	// TOP:
	//computeNormal(x2 - n, y2 - n, z2 + m, x2 - n, y2 + l, z2 + l, x3 + n, y3 + l, z3 + l); // ABC
	glNormal3d(0, 0.316228, 0.948683);
	glVertex3d(x2 - n, y2 - n, z2 + m);
	glVertex3d(x2 - n, y2 + l, z2 + l);
	glVertex3d(x3 + n, y3 + l, z3 + l);
	glVertex3d(x3 + n, y3 - n, z3 + m);

	// LEFT:
	//computeNormal(x4 + n, y4 + n, z4 + m, x3 + n, y3 - n, z3 + m, x3 - l, y3 - n, z3 + l); // ABC
	glNormal3d(-0.316228, 0, 0.948683);
	glVertex3d(x4 + n, y4 + n, z4 + m);
	glVertex3d(x3 + n, y3 - n, z3 + m);
	glVertex3d(x3 - l, y3 - n, z3 + l);
	glVertex3d(x4 - l, y4 + n, z4 + l);

	// BOTTOM:
	//computeNormal(x1 - n, y1 - l, z1 + l, x1 - n, y1 + n, z1 + m, x4 + n, y4 + n, z4 + m); // ABC
	glNormal3d(0, -0.316228, 0.948683);
	glVertex3d(x1 - n, y1 - l, z1 + l);
	glVertex3d(x1 - n, y1 + n, z1 + m);
	glVertex3d(x4 + n, y4 + n, z4 + m);
	glVertex3d(x4 + n, y4 - l, z4 + l);

	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);
	glNormal3d(0, 0, 1);

	// CORNERS:

	// RIGHT BOTTOM:
	glVertex3d(x1 - n - rRest, y1 + n + rRest - y, z1 + m);
	glVertex3d(r* sin(6 * (PI / angle)), (r* cos(6 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(7 * (PI / angle)), (r* cos(7 * (PI / angle))) - y, z2 + m);

	glVertex3d(x1 - n - rRest, y1 + n + rRest - y, z1 + m);
	glVertex3d(r* sin(7 * (PI / angle)), (r* cos(7 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(8 * (PI / angle)), (r* cos(8 * (PI / angle))) - y, z2 + m);

	glVertex3d(x1 - n - rRest, y1 + n + rRest - y, z1 + m);
	glVertex3d(r* sin(8 * (PI / angle)), (r* cos(8 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(9 * (PI / angle)), (r* cos(9 * (PI / angle))) - y, z2 + m);

	glVertex3d(x1 - n - rRest, y1 + n + rRest - y, z1 + m);
	glVertex3d(r* sin(9 * (PI / angle)), (r* cos(9 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(10 * (PI / angle)), (r* cos(10 * (PI / angle))) - y, z2 + m);

	glVertex3d(x1 - n - rRest, y1 + n + rRest - y, z1 + m);
	glVertex3d(r* sin(10 * (PI / angle)), (r* cos(10 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(11 * (PI / angle)), (r* cos(11 * (PI / angle))) - y, z2 + m);

	glVertex3d(x1 - n - rRest, y1 + n + rRest - y, z1 + m);
	glVertex3d(r* sin(11 * (PI / angle)), (r* cos(11 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(12 * (PI / angle)), (r* cos(12 * (PI / angle))) - y, z2 + m);

	// RIGHT TOP:
	glVertex3d(r * sin(6 * (PI / angle)), (r * cos(6 * (PI / angle))) - y, z2 + m);
	glVertex3d(x2 - n - rRest, y2 - n - rRest - y, z2 + m);
	glVertex3d(r * sin(5 * (PI / angle)), (r * cos(5 * (PI / angle))) - y, z2 + m);

	glVertex3d(r * sin(5 * (PI / angle)), (r * cos(5 * (PI / angle))) - y, z2 + m);
	glVertex3d(x2 - n - rRest, y2 - n - rRest - y, z2 + m);
	glVertex3d(r * sin(4 * (PI / angle)), (r * cos(4 * (PI / angle))) - y, z2 + m);
	
	glVertex3d(r * sin(4 * (PI / angle)), (r * cos(4 * (PI / angle))) - y, z2 + m);
	glVertex3d(x2 - n - rRest, y2 - n - rRest - y, z2 + m);
	glVertex3d(r * sin(3 * (PI / angle)), (r * cos(3 * (PI / angle))) - y, z2 + m);

	glVertex3d(r * sin(3 * (PI / angle)), (r * cos(3 * (PI / angle))) - y, z2 + m);
	glVertex3d(x2 - n - rRest, y2 - n - rRest - y, z2 + m);
	glVertex3d(r * sin(2 * (PI / angle)), (r * cos(2 * (PI / angle))) - y, z2 + m);

	glVertex3d(r * sin(2 * (PI / angle)), (r * cos(2 * (PI / angle))) - y, z2 + m);
	glVertex3d(x2 - n - rRest, y2 - n - rRest - y, z2 + m);
	glVertex3d(r * sin(1 * (PI / angle)), (r * cos(1 * (PI / angle))) - y, z2 + m);

	glVertex3d(r * sin(1 * (PI / angle)), (r * cos(1 * (PI / angle))) - y, z2 + m);
	glVertex3d(x2 - n - rRest, y2 - n - rRest - y, z2 + m);
	glVertex3d(r * sin(0 * (PI / angle)), (r * cos(0 * (PI / angle))) - y, z2 + m);

	// LEFT TOP:
	glVertex3d(r* sin(19 * (PI / angle)), (r* cos(19 * (PI / angle))) - y, z2 + m);
	glVertex3d(x3 + n + rRest, y3 - n - rRest - y, z3 + m);
	glVertex3d(r* sin(18 * (PI / angle)), (r* cos(18 * (PI / angle))) - y, z2 + m);

	glVertex3d(r* sin(20 * (PI / angle)), (r* cos(20 * (PI / angle))) - y, z2 + m);
	glVertex3d(x3 + n + rRest, y3 - n - rRest - y, z3 + m);
	glVertex3d(r* sin(19 * (PI / angle)), (r* cos(19 * (PI / angle))) - y, z2 + m);

	glVertex3d(r* sin(21 * (PI / angle)), (r* cos(21 * (PI / angle))) - y, z2 + m);
	glVertex3d(x3 + n + rRest, y3 - n - rRest - y, z3 + m);
	glVertex3d(r* sin(20 * (PI / angle)), (r* cos(20 * (PI / angle))) - y, z2 + m);

	glVertex3d(r* sin(22 * (PI / angle)), (r* cos(22 * (PI / angle))) - y, z2 + m);
	glVertex3d(x3 + n + rRest, y3 - n - rRest - y, z3 + m);
	glVertex3d(r* sin(21 * (PI / angle)), (r* cos(21 * (PI / angle))) - y, z2 + m);

	glVertex3d(r* sin(23 * (PI / angle)), (r* cos(23 * (PI / angle))) - y, z2 + m);
	glVertex3d(x3 + n + rRest, y3 - n - rRest - y, z3 + m);
	glVertex3d(r* sin(22 * (PI / angle)), (r* cos(22 * (PI / angle))) - y, z2 + m);

	glVertex3d(r* sin(24 * (PI / angle)), (r* cos(24 * (PI / angle))) - y, z2 + m);
	glVertex3d(x3 + n + rRest, y3 - n - rRest - y, z3 + m);
	glVertex3d(r* sin(23 * (PI / angle)), (r* cos(23 * (PI / angle))) - y, z2 + m);

	// LEFT BOTTOM:
	glVertex3d(r* sin(12 * (PI / angle)), (r* cos(12 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(13 * (PI / angle)), (r* cos(13 * (PI / angle))) - y, z2 + m);
	glVertex3d(x4 + n + rRest, y4 + n + rRest - y, z4 + m);

	glVertex3d(r* sin(13 * (PI / angle)), (r* cos(13 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(14 * (PI / angle)), (r* cos(14 * (PI / angle))) - y, z2 + m);
	glVertex3d(x4 + n + rRest, y4 + n + rRest - y, z4 + m);

	glVertex3d(r* sin(14 * (PI / angle)), (r* cos(14 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(15 * (PI / angle)), (r* cos(15 * (PI / angle))) - y, z2 + m);
	glVertex3d(x4 + n + rRest, y4 + n + rRest - y, z4 + m);

	glVertex3d(r* sin(15 * (PI / angle)), (r* cos(15 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(16 * (PI / angle)), (r* cos(16 * (PI / angle))) - y, z2 + m);
	glVertex3d(x4 + n + rRest, y4 + n + rRest - y, z4 + m);

	glVertex3d(r* sin(16 * (PI / angle)), (r* cos(16 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(17 * (PI / angle)), (r* cos(17 * (PI / angle))) - y, z2 + m);
	glVertex3d(x4 + n + rRest, y4 + n + rRest - y, z4 + m);

	glVertex3d(r* sin(17 * (PI / angle)), (r* cos(17 * (PI / angle))) - y, z2 + m);
	glVertex3d(r* sin(18 * (PI / angle)), (r* cos(18 * (PI / angle))) - y, z2 + m);
	glVertex3d(x4 + n + rRest, y4 + n + rRest - y, z4 + m);

	glEnd();
}

void drawWasherRightWall(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4) {
	double n = 0.1; // edge and corner width
	double m = 0.1; // center offset
	double l = 0.05; // variable to adjust rounding sharpness vs smoothness

	// CENTER EDGE VARIABLES:
	double ky = 0.1; // center edge height
	double kz = 0.2; // central edge width
	double kl = 0.04; // center edge inset

	glBegin(GL_QUADS);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);


	// CENTER:
	glNormal3d(1, 0, 0);

	// LOWER SQUARE CENTER:
	glVertex3d(x1 + m, y1 + n, z1 + n);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + kz);
	glVertex3d(x1 + m, y1 + n, z1 + n + kz);

	glVertex3d(x1 + m, y1 + n, z1 + n + kz);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + kz);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (2 * kz));
	glVertex3d(x1 + m, y1 + n, z1 + n + (2 * kz));

	glVertex3d(x1 + m, y1 + n, z1 + n + (2 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (2 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (3 * kz));
	glVertex3d(x1 + m, y1 + n, z1 + n + (3 * kz));

	glVertex3d(x1 + m, y1 + n, z1 + n + (3 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (3 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (4 * kz));
	glVertex3d(x1 + m, y1 + n, z1 + n + (4 * kz));

	glVertex3d(x1 + m, y1 + n, z1 + n + (4 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (4 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (5 * kz));
	glVertex3d(x1 + m, y1 + n, z1 + n + (5 * kz));

	glVertex3d(x1 + m, y1 + n, z1 + n + (5 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (5 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (6 * kz));
	glVertex3d(x1 + m, y1 + n, z1 + n + (6 * kz));

	glVertex3d(x1 + m, y1 + n, z1 + n + (6 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (6 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (7 * kz));
	glVertex3d(x1 + m, y1 + n, z1 + n + (7 * kz));

	glVertex3d(x1 + m, y1 + n, z1 + n + (7 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (7 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (8 * kz));
	glVertex3d(x1 + m, y1 + n, z1 + n + (8 * kz));

	glVertex3d(x1 + m, y1 + n, z1 + n + (8 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (8 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (9 * kz));
	glVertex3d(x1 + m, y1 + n, z1 + n + (9 * kz));


	// UPPER SQUARE CENTER:
	glVertex3d(x2 + m, y2 - n - ky, z2 + n);
	glVertex3d(x2 + m, y2 - n, z2 + n);
	glVertex3d(x2 + m, y2 - n, z2 + n + kz);
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + kz);

	glVertex3d(x2 + m, y2 - n - ky, z2 + n + kz);
	glVertex3d(x2 + m, y2 - n, z2 + n + kz);
	glVertex3d(x2 + m, y2 - n, z2 + n + (2 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (2 * kz));

	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (2 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (2 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (3 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (3 * kz));

	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (3 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (3 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (4 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (4 * kz));

	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (4 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (4 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (5 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (5 * kz));

	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (5 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (5 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (6 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (6 * kz));

	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (6 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (6 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (7 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (7 * kz));

	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (7 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (7 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (8 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (8 * kz));

	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (8 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (8 * kz));
	glVertex3d(x2 + m, y2 - n, z2 + n + (9 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (9 * kz));


	// CENTER OUTER EDGES (AROUND INDENTATIONS):
	glVertex3d(x1 + m, y1 + n + ky, z1 + n);
	glVertex3d(x2 + m, y2 - n - ky, z2 + n);
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + kz);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + kz);

	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (2 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (2 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (3 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (3 * kz));

	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (4 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (4 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (5 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (5 * kz));

	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (6 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (6 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (7 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (7 * kz));

	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (8 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (8 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (9 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (9 * kz));


	// CENTER INDENTATION 1:
	glNormal3d(1, 0, 0);
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + kz);
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + kz);
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (2 * kz));
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (2 * kz));

	glNormal3d(0, 0, 1);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + kz);
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + kz);
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + kz);
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + kz);

	glNormal3d(0, -1, 0);
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + kz);
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + kz);
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (2 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (2 * kz));

	glNormal3d(0, 0, -1);
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (2 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (2 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (2 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (2 * kz));

	glNormal3d(0, 1, 0);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + kz);
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + kz);
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + kz);
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + kz);


	// CENTER INDENTATION 2:
	glNormal3d(1, 0, 0);
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (3 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (3 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (4 * kz));
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (4 * kz));

	glNormal3d(0, 0, 1);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (3 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (3 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (3 * kz));
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (3 * kz));

	glNormal3d(0, -1, 0);
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (3 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (3 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (4 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (4 * kz));

	glNormal3d(0, 0, -1);
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (4 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (4 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (4 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (4 * kz));

	glNormal3d(0, 1, 0);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (3 * kz));
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (3 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (3 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (3 * kz));


	// CENTER INDENTATION 3:
	glNormal3d(1, 0, 0);
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (5 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (5 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (6 * kz));
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (6 * kz));

	glNormal3d(0, 0, 1);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (5 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (5 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (5 * kz));
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (5 * kz));

	glNormal3d(0, -1, 0);
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (5 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (5 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (6 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (6 * kz));

	glNormal3d(0, 0, -1);
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (6 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (6 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (6 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (6 * kz));

	glNormal3d(0, 1, 0);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (5 * kz));
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (5 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (5 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (5 * kz));


	// CENTER INDENTATION 4:
	glNormal3d(1, 0, 0);
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (7 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (7 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (8 * kz));
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (8 * kz));

	glNormal3d(0, 0, 1);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (7 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (7 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (7 * kz));
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (7 * kz));

	glNormal3d(0, -1, 0);
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (7 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (7 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (8 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (8 * kz));

	glNormal3d(0, 0, -1);
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (8 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (8 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (8 * kz));
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (8 * kz));

	glNormal3d(0, 1, 0);
	glVertex3d(x1 + m, y1 + n + ky, z1 + n + (7 * kz));
	glVertex3d(x1 + m - kl, y1 + n + ky, z1 + n + (7 * kz));
	glVertex3d(x2 + m - kl, y2 - n - ky, z2 + n + (7 * kz));
	glVertex3d(x2 + m, y2 - n - ky, z2 + n + (7 * kz));


	// CORNERS:

	// RIGHT BOTTOM:
	//computeNormal(x1 + l, y1 - l, z1 - l, x1 + l, y1 + n, z1 - l, x1 + m, y1 + n, z1 + n); // ABC
	glNormal3d(0.948683, 0, -0.316228);
	glVertex3d(x1 + l, y1 - l, z1 - l);
	glVertex3d(x1 + l, y1 + n, z1 - l);
	glVertex3d(x1 + m, y1 + n, z1 + n);
	glVertex3d(x1 + l, y1 - l, z1 + m);

	// RIGHT TOP:
	//computeNormal(x2 + l, y2 - n, z2 - l, x2 , y2 + l, z2 - l, x2 + l, y2 + l, z2 + n); // ABC
	glNormal3d(0.904534, 0.301511, -0.301511);
	glVertex3d(x2 + l, y2 - n, z2 - l);
	glVertex3d(x2 , y2 + l, z2 - l);
	glVertex3d(x2 + l, y2 + l, z2 + n);
	glVertex3d(x2 + m, y2 - n, z2 + n);

	// LEFT TOP:
	//computeNormal(x3 + m, y3 - n, z3 - n, x3 + l, y3 + l, z3 - n, x3, y3 + l, z3); // ABC
	glNormal3d(0.857143, 0.285714, 0.428571);
	glVertex3d(x3 + m, y3 - n, z3 - n);
	glVertex3d(x3 + l, y3 + l, z3 - n);
	glVertex3d(x3, y3 + l, z3);
	glVertex3d(x3 + l, y3 - n, z3 + l);

	// LEFT BOTTOM:
	//computeNormal(x4 + l, y4 - l, z4 - n, x4 + m, y4 + n, z4 - n, x4 + l, y4 + n, z4 + l); // ABC
	glNormal3d(0.904534, -0.301511, 0.301511);
	glVertex3d(x4 + l, y4 - l, z4 - n);
	glVertex3d(x4 + m, y4 + n, z4 - n);
	glVertex3d(x4 + l, y4 + n, z4 + l);
	glVertex3d(x4, y4 - l, z4);


	// EDGES:

	// RIGHT:
	//computeNormal(x1 + l, y1 + n, z1 - l, x2 + l, y2 - n, z2 - l, x2 + m, y2 - n, z2 + n); // ABC
	glNormal3d(0.948683, 0, -0.316228);
	glVertex3d(x1 + l, y1 + n, z1 - l);
	glVertex3d(x2 + l, y2 - n, z2 - l);
	glVertex3d(x2 + m, y2 - n, z2 + n);
	glVertex3d(x1 + m, y1 + n, z1 + n);

	// TOP:
	//computeNormal(x2 + m, y2 - n, z2 + n, x2 + l, y2 + l, z2 + n, x3 + l, y3 + l, z3 - n); // ABC
	glNormal3d(0.948683, 0.316228, 0);
	glVertex3d(x2 + m, y2 - n, z2 + n);
	glVertex3d(x2 + l, y2 + l, z2 + n);
	glVertex3d(x3 + l, y3 + l, z3 - n);
	glVertex3d(x3 + m, y3 - n, z3 - n);

	// LEFT:
	//computeNormal(x4 + m, y4 + n, z4 - n, x3 + m, y3 - n, z3 - n, x3 + l, y3 - n, z3 + l); // ABC
	glNormal3d(0.948683, 0, 0.316228);
	glVertex3d(x4 + m, y4 + n, z4 - n);
	glVertex3d(x3 + m, y3 - n, z3 - n);
	glVertex3d(x3 + l, y3 - n, z3 + l);
	glVertex3d(x4 + l, y4 + n, z4 + l);

	// BOTTOM:
	//computeNormal(x1 + l, y1 - l, z1 + n, x1 + m, y1 + n, z1 + n, x4 + m, y4 + n, z4 - n); // ABC
	glNormal3d(0.948683, -0.316228, 0);
	glVertex3d(x1 + l, y1 - l, z1 + n);
	glVertex3d(x1 + m, y1 + n, z1 + n);
	glVertex3d(x4 + m, y4 + n, z4 - n);
	glVertex3d(x4 + l, y4 - l, z4 - n);

	glEnd();
}

void drawWasherLeftWall(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4) {
	double n = 0.1; // edge and corner width
	double m = 0.1; // center offset
	double l = 0.05; // variable to adjust rounding sharpness vs smoothness
	
	// CENTER EDGE VARIABLES:
	double ky = 0.1; // center edge height
	double kz = 0.2; // central edge width
	double kl = 0.04; // center edge inset

	glBegin(GL_QUADS);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);


	// CENTER:
	glNormal3d(-1, 0, 0);

	// LOWER SQUARE CENTER:
	glVertex3d(x1 - m, y1 + n, z1 - n);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - kz);
	glVertex3d(x1 - m, y1 + n, z1 - n - kz);

	glVertex3d(x1 - m, y1 + n, z1 - n - kz);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - kz);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (2 * kz));
	glVertex3d(x1 - m, y1 + n, z1 - n - (2 * kz));

	glVertex3d(x1 - m, y1 + n, z1 - n - (2 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (2 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (3 * kz));
	glVertex3d(x1 - m, y1 + n, z1 - n - (3 * kz));

	glVertex3d(x1 - m, y1 + n, z1 - n - (3 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (3 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (4 * kz));
	glVertex3d(x1 - m, y1 + n, z1 - n - (4 * kz));

	glVertex3d(x1 - m, y1 + n, z1 - n - (4 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (4 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (5 * kz));
	glVertex3d(x1 - m, y1 + n, z1 - n - (5 * kz));

	glVertex3d(x1 - m, y1 + n, z1 - n - (5 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (5 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (6 * kz));
	glVertex3d(x1 - m, y1 + n, z1 - n - (6 * kz));

	glVertex3d(x1 - m, y1 + n, z1 - n - (6 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (6 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (7 * kz));
	glVertex3d(x1 - m, y1 + n, z1 - n - (7 * kz));

	glVertex3d(x1 - m, y1 + n, z1 - n - (7 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (7 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (8 * kz));
	glVertex3d(x1 - m, y1 + n, z1 - n - (8 * kz));

	glVertex3d(x1 - m, y1 + n, z1 - n - (8 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (8 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (9 * kz));
	glVertex3d(x1 - m, y1 + n, z1 - n - (9 * kz));


	// TOP SQUARE CENTER:
	glVertex3d(x2 - m, y2 - n - ky, z2 - n);
	glVertex3d(x2 - m, y2 - n, z2 - n);
	glVertex3d(x2 - m, y2 - n, z2 - n - kz);
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - kz);

	glVertex3d(x2 - m, y2 - n - ky, z2 - n - kz);
	glVertex3d(x2 - m, y2 - n, z2 - n - kz);
	glVertex3d(x2 - m, y2 - n, z2 - n - (2 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (2 * kz));

	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (2 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (2 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (3 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (3 * kz));

	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (3 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (3 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (4 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (4 * kz));

	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (4 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (4 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (5 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (5 * kz));

	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (5 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (5 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (6 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (6 * kz));

	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (6 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (6 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (7 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (7 * kz));

	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (7 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (7 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (8 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (8 * kz));

	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (8 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (8 * kz));
	glVertex3d(x2 - m, y2 - n, z2 - n - (9 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (9 * kz));


	// CENTER EXTERNAL EDGES (AROUND INSETS):
	glVertex3d(x1 - m, y1 + n + ky, z1 - n);
	glVertex3d(x2 - m, y2 - n - ky, z2 - n);
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - kz);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - kz);

	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (2 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (2 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (3 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (3 * kz));

	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (4 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (4 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (5 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (5 * kz));

	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (6 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (6 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (7 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (7 * kz));

	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (8 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (8 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (9 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (9 * kz));


	// CENTER INSET 1:
	glNormal3d(-1, 0, 0);
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - kz);
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - kz);
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (2 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (2 * kz));

	glNormal3d(0, 0, -1);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - kz);
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - kz);
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - kz);
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - kz);

	glNormal3d(0, -1, 0);
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - kz);
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - kz);
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (2 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (2 * kz));

	glNormal3d(0, 0, 1);
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (2 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (2 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (2 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (2 * kz));

	glNormal3d(0, 1, 0);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - kz);
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - kz);
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (2 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (2 * kz));


	// CENTER INSET 2:
	glNormal3d(-1, 0, 0);
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (3 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (3 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (4 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (4 * kz));

	glNormal3d(0, 0, -1);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (3 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (3 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (3 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (3 * kz));

	glNormal3d(0, -1, 0);
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (3 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (3 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (4 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (4 * kz));

	glNormal3d(0, 0, 1);
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (4 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (4 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (4 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (4 * kz));

	glNormal3d(0, 1, 0);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (3 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (3 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (4 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (4 * kz));


	// CENTER INSET 3:
	glNormal3d(-1, 0, 0);
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (5 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (5 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (6 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (6 * kz));

	glNormal3d(0, 0, -1);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (5 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (5 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (5 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (5 * kz));

	glNormal3d(0, -1, 0);
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (5 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (5 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (6 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (6 * kz));

	glNormal3d(0, 0, 1);
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (6 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (6 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (6 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (6 * kz));

	glNormal3d(0, 1, 0);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (5 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (5 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (6 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (6 * kz));


	// CENTER INSET 4:
	glNormal3d(-1, 0, 0);
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (7 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (7 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (8 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (8 * kz));

	glNormal3d(0, 0, -1);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (7 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (7 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (7 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (7 * kz));

	glNormal3d(0, -1, 0);
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (7 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (7 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (8 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (8 * kz));

	glNormal3d(0, 0, 1);
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (8 * kz));
	glVertex3d(x2 - m + kl, y2 - n - ky, z2 - n - (8 * kz));
	glVertex3d(x2 - m, y2 - n - ky, z2 - n - (8 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (8 * kz));

	glNormal3d(0, 1, 0);
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (7 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (7 * kz));
	glVertex3d(x1 - m + kl, y1 + n + ky, z1 - n - (8 * kz));
	glVertex3d(x1 - m, y1 + n + ky, z1 - n - (8 * kz));


	// CORNERS:

	// RIGHT BOTTOM:
	//computeNormal(x1, y1 - l, z1, x1 - l, y1 + n, z1 + l, x1 - m, y1 + n, z1 - n); // ABC
	glNormal3d(-0.874157, -0.388514, 0.291386);
	glVertex3d(x1, y1 - l, z1);
	glVertex3d(x1 - l, y1 + n, z1 + l);
	glVertex3d(x1 - m, y1 + n, z1 - n);
	glVertex3d(x1 - l, y1 - l, z1 - n);

	// RIGHT TOP:
	//computeNormal(x2 - l, y2 - n, z2 + l, x2, y2 + l, z2, x2 - l, y2 + l, z2 - n); // ABC
	glNormal3d(-0.816497, 0.408248, 0.408248);
	glVertex3d(x2 - l, y2 - n, z2 + l);
	glVertex3d(x2, y2 + l, z2);
	glVertex3d(x2 - l, y2 + l, z2 - n);
	glVertex3d(x2 - m, y2 - n, z2 - n);

	// LEFT TOP:
	//computeNormal(x3 - m, y3 - n, z3 + n, x3 - l, y3 + l, z3 + n, x3, y3 + l, z3 - l); // ABC
	glNormal3d(-0.904534, 0.301511, -0.301511);
	glVertex3d(x3 - m, y3 - n, z3 + n);
	glVertex3d(x3 - l, y3 + l, z3 + n);
	glVertex3d(x3, y3 + l, z3 - l);
	glVertex3d(x3 - l, y3 - n, z3 - l);

	// LEFT BOTTOM:
	//computeNormal(x4 - l, y4 - l, z4 + n, x4 - m, y4 + n, z4 + n, x4 - l, y4 + n, z4 - l); // ABC
	glNormal3d(-0.904534, -0.301511, -0.301511);
	glVertex3d(x4 - l, y4 - l, z4 + n);
	glVertex3d(x4 - m, y4 + n, z4 + n);
	glVertex3d(x4 - l, y4 + n, z4 - l);
	glVertex3d(x4 - l, y4 - l, z4 - l);


	// EDGES:

	// PRAWA:
	//computeNormal(x1 - l, y1 + n, z1 + l, x2 - l, y2 - n, z2 + l, x2 - m, y2 - n, z2 - n); // ABC
	glNormal3d(-0.948683, 0, 0.316228);
	glVertex3d(x1 - l, y1 + n, z1 + l);
	glVertex3d(x2 - l, y2 - n, z2 + l);
	glVertex3d(x2 - m, y2 - n, z2 - n);
	glVertex3d(x1 - m, y1 + n, z1 - n);

	// TOP:
	//computeNormal(x2 - m, y2 - n, z2 - n, x2 - l, y2 + l, z2 - n, x3 - l, y3 + l, z3 + n); // ABC
	glNormal3d(-0.948683, 0.316228, 0);
	glVertex3d(x2 - m, y2 - n, z2 - n);
	glVertex3d(x2 - l, y2 + l, z2 - n);
	glVertex3d(x3 - l, y3 + l, z3 + n);
	glVertex3d(x3 - m, y3 - n, z3 + n);

	// LEFT:
	//computeNormal(x4 - m, y4 + n, z4 + n, x3 - m, y3 - n, z3 + n, x3 - l, y3 - n, z3 - l); // ABC
	glNormal3d(-0.948683, 0, -0.316228);
	glVertex3d(x4 - m, y4 + n, z4 + n);
	glVertex3d(x3 - m, y3 - n, z3 + n);
	glVertex3d(x3 - l, y3 - n, z3 - l);
	glVertex3d(x4 - l, y4 + n, z4 - l);

	// BOTTOM:
	//computeNormal(x1 - l, y1 - l, z1 - n, x1 - m, y1 + n, z1 - n, x4 - m, y4 + n, z4 + n); // ABC
	glNormal3d(-0.948683, -0.316228, 0);
	glVertex3d(x1 - l, y1 - l, z1 - n);
	glVertex3d(x1 - m, y1 + n, z1 - n);
	glVertex3d(x4 - m, y4 + n, z4 + n);
	glVertex3d(x4 - l, y4 - l, z4 + n);

	glEnd();
}

void drawWasherBottomWall(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4) {
	double n = 0.1; // edge and corner width
	double m = 0.1; // center offset
	double l = 0.05; // variable to adjust rounding sharpness vs smoothness

	glBegin(GL_QUADS);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);


	// CENTER:
	glNormal3d(0, -1, 0);
	glVertex3d(x1 - n, y1 - m, z1 + n);
	glVertex3d(x2 - n, y2 - m, z2 - n);
	glVertex3d(x3 + n, y3 - m, z3 - n);
	glVertex3d(x4 + n, y4 - m, z4 + n);


	// EDGES:

	// RIGHT:
	//computeNormal(x1 + l, y1 - m + l, z1 + n, x2 + l, y2 - m + l, z2 - n, x2 - n, y2 - m, z2 - n); // ABC
	glNormal3d(0.316228, -0.948683, 0);
	glVertex3d(x1 + l, y1 - l, z1 + n);
	glVertex3d(x2 + l, y2 - l, z2 - n);
	glVertex3d(x2 - n, y2 - m, z2 - n);
	glVertex3d(x1 - n, y1 - m, z1 + n);

	// TOP:
	//computeNormal(x2 - n, y2 - m, z2 - n, x2 - n, y2 - m + l, z2 + l, x3 + n, y3 - m + l, z3 + l); // ABC
	glNormal3d(0, -0.948683, 0.316228);
	glVertex3d(x2 - n, y2 - m, z2 - n);
	glVertex3d(x2 - n, y2 - l, z2 + l);
	glVertex3d(x3 + n, y3 - l, z3 + l);
	glVertex3d(x3 + n, y3 - m, z3 - n);

	// LEFT:
	//computeNormal(x4 + n, y4 - m, z4 + n, x3 + n, y3 - m, z3 - n, x3 - l, y3 - m + l, z3 - n); // ABC
	glNormal3d(-0.316228, -0.948683, 0);
	glVertex3d(x4 + n, y4 - m, z4 + n);
	glVertex3d(x3 + n, y3 - m, z3 - n);
	glVertex3d(x3 - l, y3 - l, z3 - n);
	glVertex3d(x4 - l, y4 - l, z4 + n);

	// BOTTOM:
	//computeNormal(x1 - n, y1 - l, z1 - l, x1 - n, y1 - m, z1 + n, x4 + n, y4 - m, z4 + n); // ABC
	glNormal3d(0, -0.948683, -0.316228);
	glVertex3d(x1 - n, y1 - l, z1 - l);
	glVertex3d(x1 - n, y1 - m, z1 + n);
	glVertex3d(x4 + n, y4 - m, z4 + n);
	glVertex3d(x4 + n, y4 - l, z4 - l);

	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

	// CORNERS:

	// RIGHT BOTTOM 1:
	//computeNormal(x1 + l, y1 - l, z1 - l, x1 + l, y1 - l, z1 + n, x1 - n, y1 - m, z1 + n); // ABC
	glNormal3d(0.316228, -0.948683, 0);
	glVertex3d(x1 + l, y1 - l, z1 - l);
	glVertex3d(x1 + l, y1 - l, z1 + n);
	glVertex3d(x1 - n, y1 - m, z1 + n);

	// RIGHT BOTTOM 2:
	//computeNormal(x1 + l, y1 - l, z1 - l, x1 - n, y1 - m, z1 + n, x1 - n, y1 - l, z1 - l); // ABC
	glNormal3d(0, -0.948683, -0.316228);
	glVertex3d(x1 + l, y1 - l, z1 - l);
	glVertex3d(x1 - n, y1 - m, z1 + n);
	glVertex3d(x1 - n, y1 - l, z1 - l);

	// RIGHT TOP 1:
	//computeNormal(x2 + l, y2 - l, z2 - n, x2, y2 - l, z2, x2 - n, y2 - m, z2 - n); // ABC
	glNormal3d(0.312348, -0.937043, 0.156174);
	glVertex3d(x2 + l, y2 - l, z2 - n);
	glVertex3d(x2, y2 - l, z2);
	glVertex3d(x2 - n, y2 - m, z2 - n);

	// RIGHT TOP 2:
	//computeNormal(x2, y2 - l, z2, x2 - n, y2 - l, z2 + l, x2 - n, y2 - m, z2 - n); // ABC
	glNormal3d(0.156174, -0.937043, 0.312348);
	glVertex3d(x2, y2 - l, z2);
	glVertex3d(x2 - n, y2 - l, z2 + l);
	glVertex3d(x2 - n, y2 - m, z2 - n);


	// LEFT TOP 1:
	//computeNormal(x3 + n, y3 - m, z3 - n, x3 + n, y3 - l, z3 + l, x3, y3 - l, z3); // ABC
	glNormal3d(-0.156174, -0.937043, 0.312348);
	glVertex3d(x3 + n, y3 - m, z3 - n);
	glVertex3d(x3 + n, y3 - l, z3 + l);
	glVertex3d(x3, y3 - l, z3);

	// LEFT TOP 2:
	//computeNormal(x3 + n, y3 - m, z3 - n, x3, y3 - l, z3, x3 - l, y3 - l, z3 - n); // ABC
	glNormal3d(-0.312348, -0.937043, 0.156174);
	glVertex3d(x3 + n, y3 - m, z3 - n);
	glVertex3d(x3, y3 - l, z3);
	glVertex3d(x3 - l, y3 - l, z3 - n);


	// LEFT BOTTOM 1:
	//computeNormal(x4 + n, y4 - l, z4 - l, x4 + n, y4 - m, z4 + n, x4 - l, y4 - l, z4 - l); // ABC
	glNormal3d(0, -0.948683, -0.316228);
	glVertex3d(x4 + n, y4 - l, z4 - l);
	glVertex3d(x4 + n, y4 - m, z4 + n);
	glVertex3d(x4 - l, y4 - l, z4 - l);

	// LEFT BOTTOM 2:
	//computeNormal(x4 + n, y4 - m, z4 + n, x4 - l, y4 - l, z4 + n, x4 - l, y4 - l, z4 - l); // ABC
	glNormal3d(-0.316228, -0.948683, 0);
	glVertex3d(x4 + n, y4 - m, z4 + n);
	glVertex3d(x4 - l, y4 - l, z4 + n);
	glVertex3d(x4 - l, y4 - l, z4 - l);

	glEnd();
}

void drawWasherTopWall(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4) {
	double n = 0.1; // edge and corner width
	double m = 0.1; // center offset
	double l = 0.05; // variable to adjust rounding sharpness vs smoothness

	glBegin(GL_QUADS);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);


	// CENTER:
	glNormal3d(0, 1, 0);
	glVertex3d(x1 - n, y1 + m, z1 - n);
	glVertex3d(x2 - n, y2 + m, z2 + n);
	glVertex3d(x3 + n, y3 + m, z3 + n);
	glVertex3d(x4 + n, y4 + m, z4 - n);


	// EDGES:

	// RIGHT:
	//computeNormal(x1 + l, y1 + l, z1 - n, x2 + l, y2 + l, z2 + n, x2 - n, y2 + m, z2 + n); // ABC
	glNormal3d(0.316228, 0.948683, 0);
	glVertex3d(x1 + l, y1 + l, z1 - n);
	glVertex3d(x2 + l, y2 + l, z2 + n);
	glVertex3d(x2 - n, y2 + m, z2 + n);
	glVertex3d(x1 - n, y1 + m, z1 - n);

	// TOP:
	//computeNormal(x2 - n, y2 + m, z2 + n, x2 - n, y2 + l, z2 - l, x3 + n, y3 + l, z3 - l); // ABC
	glNormal3d(0, 0.948683, -0.316228);
	glVertex3d(x2 - n, y2 + m, z2 + n);
	glVertex3d(x2 - n, y2 + l, z2 - l);
	glVertex3d(x3 + n, y3 + l, z3 - l);
	glVertex3d(x3 + n, y3 + m, z3 + n);

	// LEFT:
	//computeNormal(x4 + n, y4 + m, z4 - n, x3 + n, y3 + m, z3 + n, x3 - l, y3 + l, z3 + n); // ABC
	glNormal3d(-0.316228, 0.948683, 0);
	glVertex3d(x4 + n, y4 + m, z4 - n);
	glVertex3d(x3 + n, y3 + m, z3 + n);
	glVertex3d(x3 - l, y3 + l, z3 + n);
	glVertex3d(x4 - l, y4 + l, z4 - n);

	// BOTTOM:
	//computeNormal(x1 - n, y1 + l, z1 + l, x1 - n, y1 + m, z1 - n, x4 + n, y4 + m, z4 - n); // ABC
	glNormal3d(0, 0.948683, 0.316228);
	glVertex3d(x1 - n, y1 + l, z1 + l);
	glVertex3d(x1 - n, y1 + m, z1 - n);
	glVertex3d(x4 + n, y4 + m, z4 - n);
	glVertex3d(x4 + n, y4 + l, z4 + l);

	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

	// CORNERS:

	// RIGHT BOTTOM 1:
	//computeNormal(x1, y1 + l, z1, x1 + l, y1 + l, z1 - n, x1 - n, y1 + m, z1 - n); // ABC
	glNormal3d(0.312348, 0.937043, 0.156174);
	glVertex3d(x1, y1 + l, z1);
	glVertex3d(x1 + l, y1 + l, z1 - n);
	glVertex3d(x1 - n, y1 + m, z1 - n);

	// RIGHT BOTTOM 2:
	//computeNormal(x1, y1 + l, z1, x1 - n, y1 + m, z1 - n, x1 - n, y1 + l, z1 + l); // ABC
	glNormal3d(0.156174, 0.937043, 0.312348);
	glVertex3d(x1, y1 + l, z1);
	glVertex3d(x1 - n, y1 + m, z1 - n);
	glVertex3d(x1 - n, y1 + l, z1 + l);

	// RIGHT TOP 1:
	//computeNormal(x2 + l, y2 + l, z2 + n, x2, y2 + l, z2 - l, x2 - n, y2 + m, z2 + n); // ABC
	glNormal3d(0.314485, 0.943456, -0.104828);
	glVertex3d(x2 + l, y2 + l, z2 + n);
	glVertex3d(x2, y2 + l, z2 - l);
	glVertex3d(x2 - n, y2 + m, z2 + n);

	// RIGHT TOP 2:
	//computeNormal(x2, y2 + l, z2 - l, x2 - n, y2 + l, z2 - l, x2 - n, y2 + m, z2 + n); // ABC
	glNormal3d(0, 0.948683, -0.316228);
	glVertex3d(x2, y2 + l, z2 - l);
	glVertex3d(x2 - n, y2 + l, z2 - l);
	glVertex3d(x2 - n, y2 + m, z2 + n);

	// LEFT TOP 1:
	//computeNormal(x3 + n, y3 + m, z3 + n, x3 + n, y3 + l, z3 - l, x3, y3 + l, z3 - l); // ABC
	glNormal3d(0, 0.948683, -0.316228);
	glVertex3d(x3 + n, y3 + m, z3 + n);
	glVertex3d(x3 + n, y3 + l, z3 - l);
	glVertex3d(x3, y3 + l, z3 - l);

	// LEFT TOP 2:
	//computeNormal(x3 + n, y3 + m, z3 + n, x3, y3 + l, z3 - l, x3 - l, y3 + l, z3 + n); // ABC
	glNormal3d(-0.314485, 0.943456, -0.104828);
	glVertex3d(x3 + n, y3 + m, z3 + n);
	glVertex3d(x3, y3 + l, z3 - l);
	glVertex3d(x3 - l, y3 + l, z3 + n);

	// LEFT BOTTOM 1:
	//computeNormal(x4 + n, y4 + l, z4 + l, x4 + n, y4 + m, z4 - n, x4, y4 + l, z4); // ABC
	glNormal3d(-0.156174, 0.937043, 0.312348);
	glVertex3d(x4 + n, y4 + l, z4 + l);
	glVertex3d(x4 + n, y4 + m, z4 - n);
	glVertex3d(x4, y4 + l, z4);

	// LEFT BOTTOM 2:
	//computeNormal(x4 + n, y4 + m, z4 - n, x4 - l, y4 + l, z4 - n, x4, y4 + l, z4); // ABC
	glNormal3d(-0.312348, 0.937043, 0.156174);
	glVertex3d(x4 + n, y4 + m, z4 - n);
	glVertex3d(x4 - l, y4 + l, z4 - n);
	glVertex3d(x4, y4 + l, z4);

	glEnd();
}

void drawWasherBackWall(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4) {
	double n = 0.1; // edge and corner width
	double m = 0.0; // center offset
	double l = 0.05; // variable to adjust rounding sharpness vs smoothness

	glBegin(GL_QUADS);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);


	// CENTER:
	glNormal3d(0, 0, -1);
	glVertex3d(x1 + n, y1 + n, z1 - m);
	glVertex3d(x2 + n, y2 - n, z2 - m);
	glVertex3d(x3 - n, y3 - n, z3 - m);
	glVertex3d(x4 - n, y4 + n, z4 - m);


	// CORNERS:

	// RIGHT BOTTOM:
	//computeNormal(x1 - l, y1 - l, z1 - l, x1 - l, y1 + n, z1 - l, x1 + n, y1 + n, z1 - m); // ABC
	glNormal3d(0.316228, 0, -0.948683);
	glVertex3d(x1 - l, y1 - l, z1 - l);
	glVertex3d(x1 - l, y1 + n, z1 - l);
	glVertex3d(x1 + n, y1 + n, z1 - m);
	glVertex3d(x1 + n, y1 - l, z1 - l);

	// RIGHT TOP:
	//computeNormal(x2 - l, y2 - n, z2 - l, x2, y2 + l, z2 - l, x2 + n, y2 + l, z2 - l); // ABC
	glNormal3d(0, 0, -1);
	glVertex3d(x2 - l, y2 - n, z2 - l);
	glVertex3d(x2, y2 + l, z2 - l);
	glVertex3d(x2 + n, y2 + l, z2 - l);
	glVertex3d(x2 + n, y2 - n, z2 - m);

	// LEFT TOP:
	//computeNormal(x3 - n, y3 - n, z3 - m, x3 - n, y3 + l, z3 - l, x3, y3 + l, z3 - l); // ABC
	glNormal3d(0, -0.316228, -0.948683);
	glVertex3d(x3 - n, y3 - n, z3 - m);
	glVertex3d(x3 - n, y3 + l, z3 - l);
	glVertex3d(x3, y3 + l, z3 - l);
	glVertex3d(x3 + l, y3 - n, z3 - l);

	// LEFT BOTTOM:
	//computeNormal(x4 - n, y4 - l, z4 - l, x4 - n, y4 + n, z4 - m, x4 + l, y4 + n, z4 - l); // ABC
	glNormal3d(-0.301511, 0.301511, -0.904534);
	glVertex3d(x4 - n, y4 - l, z4 - l);
	glVertex3d(x4 - n, y4 + n, z4 - m);
	glVertex3d(x4 + l, y4 + n, z4 - l);
	glVertex3d(x4 + l, y4 - l, z4 - l);


	// EDGES:

	// RIGHT:
	//computeNormal(x1 - l, y1 + n, z1 - l, x2 - l, y2 - n, z2 - l, x2 + n, y2 - n, z2 - m); // ABC
	glNormal3d(0.316228, 0, -0.948683);
	glVertex3d(x1 - l, y1 + n, z1 - l);
	glVertex3d(x2 - l, y2 - n, z2 - l);
	glVertex3d(x2 + n, y2 - n, z2 - m);
	glVertex3d(x1 + n, y1 + n, z1 - m);

	// TOP:
	//computeNormal(x2 + n, y2 - n, z2 - m, x2 + n, y2 + l, z2 - l, x3 - n, y3 + l, z3 - l); // ABC
	glNormal3d(0, -0.316228, -0.948683);
	glVertex3d(x2 + n, y2 - n, z2 - m);
	glVertex3d(x2 + n, y2 + l, z2 - l);
	glVertex3d(x3 - n, y3 + l, z3 - l);
	glVertex3d(x3 - n, y3 - n, z3 - m);

	// LEFT:
	//computeNormal(x4 - n, y4 + n, z4 - m, x3 - n, y3 - n, z3 - m, x3 + l, y3 - n, z3 - l); // ABC
	glNormal3d(-0.316228, 0, -0.948683);
	glVertex3d(x4 - n, y4 + n, z4 - m);
	glVertex3d(x3 - n, y3 - n, z3 - m);
	glVertex3d(x3 + l, y3 - n, z3 - l);
	glVertex3d(x4 + l, y4 + n, z4 - l);

	// BOTTOM:
	//computeNormal(x1 + n, y1 - l, z1 - l, x1 + n, y1 + n, z1 - m, x4 - n, y4 + n, z4 - m); // ABC
	glNormal3d(0, 0.316228, -0.948683);
	glVertex3d(x1 + n, y1 - l, z1 - l);
	glVertex3d(x1 + n, y1 + n, z1 - m);
	glVertex3d(x4 - n, y4 + n, z4 - m);
	glVertex3d(x4 - n, y4 - l, z4 - l);

	glEnd();
}