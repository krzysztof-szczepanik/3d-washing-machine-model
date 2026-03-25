#include "globals.hpp"

#include <GLFW/glfw3.h>


// ================== RENDER FLAGS ===================

int iCull = false;
int iDepth = true;
int iOutline = false;
int iFill = false;
int iClock = false;



// ============== PROJECTION PARAMETERS ==============

GLint scaleMode = FULL_WINDOW; // FULL_WINDOW, ASPECT_1_1
GLint projectionMode = FRUST;  // ORTHO, FRUSTUM

GLfloat viewSize = 5.0;        // half-size of view volume
GLfloat nearPlane = 10.0;      // near clipping plane
GLfloat farPlane = 16.0;       // far clipping plane



// ==================== LIGHTING =====================

// GLOBAL LIGHTING TOGGLE:
bool lightingEnabled = true;

// INDIVIDUAL LIGHT ENABLE FLAGS:
bool lightEnabled0 = true;
bool lightEnabled1 = false;
bool lightEnabled2 = false;

// CONTROL STEPS:
float lightMoveStep = 1.0f;
float lightIntensityStep = 0.1f;

// SELECTED LIGHT INDEX:
int selectedLight = 0; // 0 - light0 (default)
                       // 1 - light1
					   // 2 - light2

// LIGHT ARRAY:
Light lights[3] = {
	{2.0f, 5.0f, 5.0f, 1.0f, 1.0f, 1.0f, 1.0f},  // light0
	{0.0f, 4.0f, -8.0f, 0.0f, 0.0f, 1.0f, 1.0f}, // light1
	{-2.0f, 8.0f, 5.0f, 1.0, 0.0f, 0.0f, 1.0f}   // light2
};



// ===================== CAMERA ======================

// TRANSLATION:
double cameraPosX = 0.0;
double cameraPosY = 0.0;
double cameraPosZ = 0.0;

// ROTATION:
double cameraRotX = 0.0;
double cameraRotY = 0.0;
double cameraRotZ = 0.0;

// CONTROL STEP:
double cameraMoveStep = 1.0;   // how much camera moves per input
double cameraRotateStep = 5.0; // how much camera rotates per input



// ===================== GLOBAL ======================

// TRANSLATION:
double globalPosX = 0.0;
double globalPosY = 0.0;
double globalPosZ = -13.0;



// ===================== WASHER ======================

// TRANSLATION:
double washerPosX = 0.0;
double washerPosY = 0.0;
double washerPosZ = -13.0;

// ROTATION:
double washerRotX = 0.0;
double washerRotY = 0.0;
double washerRotZ = 0.0;

// CONTROL STEP:
double washerMoveStep = 1.0;   // how much washer moves per input
double washerRotateStep = 5.0; // how much washer rotates per input

// AUTO-ROTATION:
bool washerAutoRotateEnabled = false;



// ================== WASHER DOOR ====================

// ANIMATION:
bool washerDoorAnimEnabled = false; // animate door
bool washerDoorOpen = false;        // false - closing, true - opening

double washerDoorAngle = 0.0;       // current angle
double washerDoorAngleMin = 0.0;    // min angle
double washerDoorAngleMax = -90.0;  // max angle



// =================== WASHER TANK ===================

// ANIMATION:
bool washerTankAnimEnabled = false;  // animate detergent tank
bool washerTankOpen = false;         // false - closing, true - opening

double washerTankOffset = 0.825;     // current offset
double washerTankOffsetMin = 0.825;  // min offset
double washerTankOffsetMax = 1.3;    // max offset
double washerTankOffsetStep = 0.005; // movement step



// ================= WASHER DISPLAY ==================

bool washerDisplayOn = false; // display on/off



// ===================== TEXTURES ======================

// IDs:
unsigned int textureIDs[TEXTURE_COUNT];

// FILE PATHS:
const char* textureFiles[TEXTURE_COUNT] = {
    "textures/floor.jpg",
    "textures/wall.jpg"
};

// DIMENSIONS:
int textureWidth[TEXTURE_COUNT];
int textureHeight[TEXTURE_COUNT];