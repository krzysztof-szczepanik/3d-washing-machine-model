#include "math.hpp"
#include <cmath>



// ==================== VARIABLES ====================

// Computed normal vector components:
double computedNormalX;
double computedNormalY;
double computedNormalZ;



// ==================== FUNCTIONS ====================

// Compute normal vector for triangle ABC:
void computeNormal(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {
	
	// POINTS:
	// A = (x1, y1, z1)
	// B = (x2, y2, z2)
	// C = (x3, y3, z3)
	
	// VECTOR: [u = B - A]
	double ux = x2 - x1;
	double uy = y2 - y1;
	double uz = z2 - z1;

	// VECTOR: [v = C - A]
	double vx = x3 - x1;
	double vy = y3 - y1;
	double vz = z3 - z1;

	// CROSS PRODUCT: [n = u × v]
	double nx = uy * vz - uz * vy;
	double ny = uz * vx - ux * vz;
	double nz = ux * vy - uy * vx;

	// NORMALIZATION:
	double length  = sqrt(nx * nx + ny * ny + nz * nz);

	if (length == 0.0) {
		return;
	}

	nx /= length;
	ny /= length;
	nz /= length;

	// STORE RESULT:
	computedNormalX = nx;
	computedNormalY = ny;
	computedNormalZ = nz;
}