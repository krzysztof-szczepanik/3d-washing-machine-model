#include "tank.hpp"
#include "globals.hpp"
#include "math.hpp"

#include <GLFW/glfw3.h>



// ==================== FUNCTIONS ====================

void drawTank() {
	double n = 0.1; // edge and corner width
	double m = 0.1; // center offset

	// DRUM VARIABLES:
	double r = 0.5 + m; // drum radius
	double rRest = 0.9 - r; // remainder after subtracting drum radius from center wall width

	// TOP PANEL VARIABLES:
	double ph = rRest + m + 0.025; // top panel height
	double po = 0.025; // top panel offset from center wall
	double poh = 0.1; // height offset
	double pos = 0.1; // width offset

	// DRUM VARIABLES:
	double zs = 0.5 / 2.0; // drum width
	double zh = -((1.0 - n - ph + poh) - (1.0 - n - poh)) / 2.0;
	double zg = 0.6 / 2.0; // drum depth

	// DRUM VARIABLES - INNER WALLS:
	double zo = 0.05; // inner wall offset from outer wall
	double zo2 = 0.05; // extra offset for front inner wall
	double zohw = 0.02; // internal drum wall height drop

	// DRUM VARIABLES - FRONT WALL:
	double zohp = 0.07; // front outer wall offset
	double zms = 0.035; // margin for front wall cavity width
	double zmh = 0.035; // margin for front wall cavity height
	double zgp = 0.03; // front wall cavity depth

	glBegin(GL_QUADS);
	glColor3d(240.0 / 255.0, 240.0 / 255.0, 240.0 / 255.0);

	// FRONT OUTER WALL - RIGHT:
	glNormal3d(0, 0, 1);
	glVertex3d(zs, -zh + zohp, zg);
	glVertex3d(zs, zh - zohp, zg);
	glVertex3d(zs - zohp, zh - zohp, zg);
	glVertex3d(zs - zohp, -zh + zohp, zg);

	// FRONT OUTER WALL - TOP:
	glNormal3d(0, 0, 1);
	glVertex3d(zs, zh - zohp, zg);
	glVertex3d(zs, zh, zg);
	glVertex3d(-zs, zh, zg);
	glVertex3d(-zs, zh - zohp, zg);

	// FRONT OUTER WALL - LEFT:
	glNormal3d(0, 0, 1);
	glVertex3d(-zs + zohp, -zh + zohp, zg);
	glVertex3d(-zs + zohp, zh - zohp, zg);
	glVertex3d(-zs, zh - zohp, zg);
	glVertex3d(-zs, -zh + zohp, zg);

	// FRONT OUTER WALL - BOTTOM:
	glNormal3d(0, 0, 1);
	glVertex3d(zs, -zh, zg);
	glVertex3d(zs, -zh + zohp, zg);
	glVertex3d(-zs, -zh + zohp, zg);
	glVertex3d(-zs, -zh, zg);


	// FRONT OUTER WALL - CENTER (CAVITY):
	glNormal3d(0, 0, 1);
	glVertex3d(zs - zohp - zms, -zh + zohp + zmh, zg - zgp);
	glVertex3d(zs - zohp - zms, zh - zohp, zg - zgp);
	glVertex3d(-zs + zohp + zms, zh - zohp, zg - zgp);
	glVertex3d(-zs + zohp + zms, -zh + zohp + zmh, zg - zgp);

	// FRONT OUTER WALL - CENTER (RIGHT):
	computeNormal(zs - zohp, -zh + zohp, zg, zs - zohp, zh - zohp, zg, zs - zohp - zms, zh - zohp, zg - zgp); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(zs - zohp, -zh + zohp, zg);
	glVertex3d(zs - zohp, zh - zohp, zg);
	glVertex3d(zs - zohp - zms, zh - zohp, zg - zgp);
	glVertex3d(zs - zohp - zms, -zh + zohp + zmh, zg - zgp);

	// FRONT OUTER WALL - CENTER (TOP):
	computeNormal(zs - zohp, zh - zohp, zg, zs - zohp - zms, zh - zohp - zmh, zg - zgp, -zs + zohp + zms, zh - zohp - zmh, zg - zgp); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(zs - zohp, zh - zohp, zg);
	glVertex3d(zs - zohp - zms, zh - zohp, zg - zgp);
	glVertex3d(-zs + zohp + zms, zh - zohp, zg - zgp);
	glVertex3d(-zs + zohp, zh - zohp, zg);

	// FRONT OUTER WALL - CENTER (LEFT):
	computeNormal(-zs + zohp + zms, -zh + zohp + zmh, zg - zgp, -zs + zohp + zms, zh - zohp, zg - zgp, -zs + zohp, zh - zohp, zg); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(-zs + zohp + zms, -zh + zohp + zmh, zg - zgp);
	glVertex3d(-zs + zohp + zms, zh - zohp, zg - zgp);
	glVertex3d(-zs + zohp, zh - zohp, zg);
	glVertex3d(-zs + zohp, -zh + zohp, zg);

	// FRONT OUTER WALL - CENTER (BOTTOM):
	computeNormal(zs - zohp, -zh + zohp, zg, zs - zohp - zms, -zh + zohp + zmh, zg - zgp, -zs + zohp + zms, -zh + zohp + zmh, zg - zgp); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(zs - zohp, -zh + zohp, zg);
	glVertex3d(zs - zohp - zms, -zh + zohp + zmh, zg - zgp);
	glVertex3d(-zs + zohp + zms, -zh + zohp + zmh, zg - zgp);
	glVertex3d(-zs + zohp, -zh + zohp, zg);


	// OUTER WALL - RIGHT:
	glNormal3d(1, 0, 0);
	glVertex3d(zs, -zh, -zg);
	glVertex3d(zs, zh, -zg);
	glVertex3d(zs, zh, zg);
	glVertex3d(zs, -zh, zg);

	// OUTER WALL - LEFT:
	glNormal3d(-1, 0, 0);
	glVertex3d(-zs, -zh, zg);
	glVertex3d(-zs, zh, zg);
	glVertex3d(-zs, zh, -zg);
	glVertex3d(-zs, -zh, -zg);

	// OUTER WALL - BACK:
	glNormal3d(0, 0, -1);
	glVertex3d(-zs, -zh, -zg);
	glVertex3d(-zs, zh, -zg);
	glVertex3d(zs, zh, -zg);
	glVertex3d(zs, -zh, -zg);

	// OUTER WALL - BOTTOM:
	glNormal3d(0, -1, 0);
	glVertex3d(zs, -zh, -zg);
	glVertex3d(zs, -zh, zg);
	glVertex3d(-zs, -zh, zg);
	glVertex3d(-zs, -zh, -zg);


	// INNER WALL - FRONT RIGHT:
	glNormal3d(0, 0, -1);
	glVertex3d(-zs + zo, -zh + zo, zg - zo - zo2);
	glVertex3d(-zs + zo, zh - zohw, zg - zo - zo2);
	glVertex3d(0 - (zo / 2.0), zh - zohw, zg - zo - zo2);
	glVertex3d(0 - (zo / 2.0), -zh + zo, zg - zo - zo2);
	

	// INNER WALL - FRONT LEFT:
	glNormal3d(0, 0, -1);
	glVertex3d(0 + (zo / 2.0), -zh + zo, zg - zo - zo2);
	glVertex3d(0 + (zo / 2.0), zh - zohw, zg - zo - zo2);
	glVertex3d(zs - zo, zh - zohw, zg - zo - zo2);
	glVertex3d(zs - zo, -zh + zo, zg - zo - zo2);

	// INNER WALL - RIGHT:
	glNormal3d(-1, 0, 0);
	glVertex3d(zs - zo, -zh + zo, zg - zo);
	glVertex3d(zs - zo, zh - zohw, zg - zo);
	glVertex3d(zs - zo, zh - zohw, -zg + zo);
	glVertex3d(zs - zo, -zh + zo, -zg + zo);

	// INNER WALL - LEFT:
	glNormal3d(1, 0, 0);
	glVertex3d(-zs + zo, -zh + zo, -zg + zo);
	glVertex3d(-zs + zo, zh - zohw, -zg + zo);
	glVertex3d(-zs + zo, zh - zohw, zg - zo);
	glVertex3d(-zs + zo, -zh + zo, zg - zo);

	// INNER WALL - BACK RIGHT:
	glNormal3d(0, 0, 1);
	glVertex3d(zs - zo, -zh + zo, -zg + zo);
	glVertex3d(zs - zo, zh - zohw, -zg + zo);
	glVertex3d(0 + (zo / 2.0), zh - zohw, -zg + zo);
	glVertex3d(0 + (zo / 2.0), -zh + zo, -zg + zo);

	// INNER WALL - BACK LEFT:
	glNormal3d(0, 0, 1);
	glVertex3d(0 - (zo / 2.0), -zh + zo, -zg + zo);
	glVertex3d(0 - (zo / 2.0), zh - zohw, -zg + zo);
	glVertex3d(-zs + zo, zh - zohw, -zg + zo);
	glVertex3d(-zs + zo, -zh + zo, -zg + zo);

	// INNER WALL - BOTTOM RIGHT:
	glNormal3d(0, 1, 0);
	glVertex3d(zs - zo, -zh + zo, zg - zo - zo2);
	glVertex3d(zs - zo, -zh + zo, -zg + zo);
	glVertex3d(0 + (zo / 2.0), -zh + zo, -zg + zo);
	glVertex3d(0 + (zo / 2.0), -zh + zo, zg - zo - zo2);

	// INNER WALL - BOTTOM LEFT:
	glNormal3d(0, 1, 0);
	glVertex3d(0 - (zo / 2.0), -zh + zo, zg - zo - zo2);
	glVertex3d(0 - (zo / 2.0), -zh + zo, -zg + zo);
	glVertex3d(-zs + zo, -zh + zo, -zg + zo);
	glVertex3d(-zs + zo, -zh + zo, zg - zo - zo2);

	// INNER WALL - CENTER FACING RIGHT:
	glNormal3d(1, 0, 0);
	glVertex3d(0 + (zo / 2.0), -zh + zo, -zg + zo);
	glVertex3d(0 + (zo / 2.0), zh - zohw, -zg + zo);
	glVertex3d(0 + (zo / 2.0), zh - zohw, zg - zo - zo2);
	glVertex3d(0 + (zo / 2.0), -zh + zo, zg - zo - zo2);

	// INNER WALL - CENTER FACING LEFT:
	glNormal3d(-1, 0, 0);
	glVertex3d(0 - (zo / 2.0), -zh + zo, zg - zo - zo2);
	glVertex3d(0 - (zo / 2.0), zh - zohw, zg - zo - zo2);
	glVertex3d(0 - (zo / 2.0), zh - zohw, -zg + zo);
	glVertex3d(0 - (zo / 2.0), -zh + zo, -zg + zo);



	// OUTER TOP WALL - RIGHT:
	computeNormal(zs, zh, zg, zs, zh, -zg, zs - zo, zh - zohw, -zg + zo); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(zs, zh, zg);
	glVertex3d(zs, zh, -zg);
	glVertex3d(zs - zo, zh - zohw, -zg + zo);
	glVertex3d(zs - zo, zh - zohw, zg - zo);

	// OUTER TOP WALL - TOP:
	computeNormal(zs - zo, zh - zohw, -zg + zo, zs, zh, -zg, -zs, zh, -zg); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(zs - zo, zh - zohw, -zg + zo);
	glVertex3d(zs, zh, -zg);
	glVertex3d(-zs, zh, -zg);
	glVertex3d(-zs + zo, zh - zohw, -zg + zo);

	// OUTER TOP WALL - LEFT:
	computeNormal(-zs + zo, zh - zohw, zg - zo, -zs + zo, zh - zohw, -zg + zo, -zs, zh, -zg); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(-zs + zo, zh - zohw, zg - zo);
	glVertex3d(-zs + zo, zh - zohw, -zg + zo);
	glVertex3d(-zs, zh, -zg);
	glVertex3d(-zs, zh, zg);

	// OUTER TOP WALL - BOTTOM:
	computeNormal(zs, zh, zg, zs - zo, zh - zohw, zg - zo - zo2, -zs + zo, zh - zohw, zg - zo - zo2); // ABC
	glNormal3d(computedNormalX, computedNormalY, computedNormalZ);
	glVertex3d(zs, zh, zg);
	glVertex3d(zs - zo, zh - zohw, zg - zo - zo2);
	glVertex3d(-zs + zo, zh - zohw, zg - zo - zo2);
	glVertex3d(-zs, zh, zg);

	// OUTER TOP WALL - CENTER:
	glNormal3d(0, 1, 0);
	glVertex3d(0 + (zo / 2.0), zh - zohw, zg - zo - zo2);
	glVertex3d(0 + (zo / 2.0), zh - zohw, -zg + zo);
	glVertex3d(0 - (zo / 2.0), zh - zohw, -zg + zo);
	glVertex3d(0 - (zo / 2.0), zh - zohw, zg - zo - zo2);

	glEnd();
}