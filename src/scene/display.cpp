#include "display.hpp"
#include "globals.hpp"
#include "control_knob.hpp"
#include "door_hinge.hpp"
#include "door.hpp"
#include "tank.hpp"
#include "washer.hpp"
#include "scene.hpp"

#include <GLFW/glfw3.h>



// ================ HELPER FUNCTIONS =================


// RENDER STATE:

static void applyRenderFlags() {
    if (iCull)    glEnable(GL_CULL_FACE);          else glDisable(GL_CULL_FACE);
	if (iDepth)   glEnable(GL_DEPTH_TEST);         else glDisable(GL_DEPTH_TEST);
	if (iOutline) glPolygonMode(GL_BACK, GL_LINE); else glPolygonMode(GL_BACK, GL_FILL);
	if (iFill)    glShadeModel(GL_FLAT);           else glShadeModel(GL_SMOOTH);
	if (iClock)   glFrontFace(GL_CW);              else glFrontFace(GL_CCW);
}


// LIGHTING STATE:

static void applyLightingFlags() {
    if (lightingEnabled) glEnable(GL_LIGHTING); else glDisable(GL_LIGHTING);

	if (lightEnabled0)   glEnable(GL_LIGHT0);   else glDisable(GL_LIGHT0);
	if (lightEnabled1)   glEnable(GL_LIGHT1);   else glDisable(GL_LIGHT1);
	if (lightEnabled2)   glEnable(GL_LIGHT2);   else glDisable(GL_LIGHT2);
}


// CAMERA:

static void applyCameraTransform() {
    glTranslated(0, 0, globalPosZ);

    glRotated(cameraRotX, 1, 0, 0);
    glRotated(cameraRotY, 0, 1, 0);
    glRotated(cameraRotZ, 0, 0, 1);

    glTranslated(0, 0, -globalPosZ);

    glTranslated(cameraPosX, cameraPosY, cameraPosZ);
}


// SCENE:

static void renderFloor() {
    glPushMatrix();
		if (projectionMode == FRUST) {
			glTranslated(globalPosX, globalPosY - viewSize, globalPosZ);
		}
		
		if (projectionMode == ORTO) {
			glTranslated(globalPosX, globalPosY - viewSize + 1, globalPosZ);
			glRotated(20, 1, 0, 0);
		}

		drawFloor();
    glPopMatrix();
}

static void renderBackWall() {
    glPushMatrix();
		if (projectionMode == FRUST) {
			glTranslated(globalPosX, globalPosY, -farPlane + 1);
		}
		
		if (projectionMode == ORTO) {
			glTranslated(globalPosX, globalPosY, -viewSize + 1);
		}

		drawBackWall();
    glPopMatrix();
}


// WASHER:

static void applyWasherTransform(double time) {
	glTranslated(washerPosX, washerPosY, washerPosZ);

	if (washerAutoRotateEnabled) {
		glRotated(10 * time, 0, 1, 0.2);
		washerRotX = 0.0;
		washerRotY = 0.0;
		washerRotZ = 0.0;
	} else {
		glRotated(washerRotX, 1, 0, 0);
		glRotated(washerRotY, 0, 1, 0);
		glRotated(washerRotZ, 0, 0, 1);
	}
	
	glLineWidth(2);
	glScaled(1.3, 1.3, 1.3);
}

static void renderWasherBody() {
    drawWasher();
}


// WASHER DOOR HINGE:

static void renderWasherDoorHinge() {
    glPushMatrix();
		glTranslated(-0.6, -0.2, 1.15);
		drawDoorHinge();
    glPopMatrix();
}


// WASHER DOOR:

static void updateWasherDoorAnimation() {
    if (!washerDoorAnimEnabled) return;

    if (washerDoorOpen) { // OPENING:
        washerDoorAngle -= 1.0;
        if (washerDoorAngle <= washerDoorAngleMax) { // '<=' (inverted logic because max angle is -90 while moving from 0)
            washerDoorAngle = washerDoorAngleMax;
            washerDoorAnimEnabled = false;
        }
    } else { // CLOSING:
        washerDoorAngle += 1.0;
        if (washerDoorAngle >= washerDoorAngleMin) { // '>=' (inverted logic because min angle is 0 while moving from -90)
            washerDoorAngle = washerDoorAngleMin;
            washerDoorAnimEnabled = false;
        }
    }
}

static void renderWasherDoor() {
	glPushMatrix();
		updateWasherDoorAnimation();
		
		glTranslated(-0.55, -0.2, 1.17);
		glRotated(washerDoorAngle, 0, 1, 0);
		glTranslated(0.55, 0, 0);
		drawDoor();
	glPopMatrix();
}


// WASHER TANK:

static double computeTankOffsetY() {
	// (y3 - n - ph + poh) - (((1.0 - n - ph + poh) - (1.0 - n - poh)) / 2.0)
	return (1.0 - 0.1 - ((0.9 - (0.5 + 0.1)) + 0.1 + 0.025) + 0.1)
		 - (((1.0 - 0.1 - ((0.9 - (0.5 + 0.1)) + 0.1 + 0.025) + 0.1)
		 - (1.0 - 0.1 - 0.1)) / 2.0);
}

static void updateWasherTankAnimation() {
    if (!washerTankAnimEnabled) return;

    if (washerTankOpen) { // OPENING:
        washerTankOffset += washerTankOffsetStep;
        if (washerTankOffset >= washerTankOffsetMax) {
            washerTankOffset = washerTankOffsetMax;
            washerTankAnimEnabled = false;
        }
    } else { // CLOSING:
        washerTankOffset -= washerTankOffsetStep;
        if (washerTankOffset <= washerTankOffsetMin) {
            washerTankOffset = washerTankOffsetMin;
            washerTankAnimEnabled = false;
        }
    }
}

static void renderWasherTank() {
    double y = computeTankOffsetY();

    glPushMatrix();
		glTranslated(-0.55, y, washerTankOffset);
		drawTank();
    glPopMatrix();
}


// WASHER CONTROL KNOB:

static void renderWasherButton() {
    double y = computeTankOffsetY();

    glPushMatrix();
		glTranslated(0, y, 0.02);
		drawControlKnob();
    glPopMatrix();
}


// WASHER:

static void renderWasher(double time) {
	glPushMatrix();
		applyWasherTransform(time);
		renderWasherBody();

		renderWasherDoorHinge();
		renderWasherDoor();

		updateWasherTankAnimation();
		renderWasherTank();

		renderWasherButton();
	glPopMatrix();
}



// ==================== FUNCTIONS ====================

void display(float size) {
	const double time = glfwGetTime();

	applyRenderFlags();
    applyLightingFlags();

	glPushMatrix();
		applyCameraTransform();

		renderFloor();
		renderBackWall();
		renderWasher(time);
	glPopMatrix();
}