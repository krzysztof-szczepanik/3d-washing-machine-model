#include "scene.hpp"
#include "globals.hpp"

#include <GLFW/glfw3.h>



// ==================== FUNCTIONS ====================

void drawFloor() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIDs[0]);
	glBegin(GL_QUADS);

	glNormal3d(0, 1, 0);
	glTexCoord2d(1, 0); glVertex3d(viewSize, 0, viewSize);
	glTexCoord2d(1, 1); glVertex3d(viewSize, 0, -viewSize);
	glTexCoord2d(0, 1); glVertex3d(-viewSize, 0, -viewSize);
	glTexCoord2d(0, 0); glVertex3d(-viewSize, 0, viewSize);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawBackWall() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIDs[1]);
	glBegin(GL_QUADS);

	glNormal3d(0, 0, 1);
	glTexCoord2d(1, 0); glVertex3d(viewSize, -viewSize, 0);
	glTexCoord2d(1, 1); glVertex3d(viewSize, viewSize, 0);
	glTexCoord2d(0, 1); glVertex3d(-viewSize, viewSize, 0);
	glTexCoord2d(0, 0); glVertex3d(-viewSize, -viewSize, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}