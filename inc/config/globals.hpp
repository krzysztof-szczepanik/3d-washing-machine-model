#pragma once

#include <GLFW/glfw3.h>

#define PI 3.14159265359



// ================== RENDER FLAGS ===================

extern int iCull;
extern int iDepth;
extern int iOutline;
extern int iFill;
extern int iClock;



// ================ PROJECTION MODES =================

enum {
    FULL_WINDOW,
    ASPECT_1_1,
    ORTO,
    FRUST
};



// ============== PROJECTION PARAMETERS ==============

// MODES:
extern GLint scaleMode;      // FULL_WINDOW, ASPECT_1_1
extern GLint projectionMode; // ORTHO, FRUSTUM

// PARAMETERS:
extern GLfloat viewSize;     // half-size of view volume
extern GLfloat nearPlane;    // near clipping plane
extern GLfloat farPlane;     // far clipping plane



// ==================== LIGHTING =====================

// GLOBAL LIGHTING TOGGLE:
extern bool lightingEnabled;

// INDIVIDUAL LIGHT ENABLE FLAGS:
extern bool lightEnabled0;
extern bool lightEnabled1;
extern bool lightEnabled2;

// CONTROL STEPS:
extern float lightMoveStep;
extern float lightIntensityStep;

// SELECTED LIGHT INDEX:
extern int selectedLight; // 0 - light0 (default)
                          // 1 - light1
						  // 2 - light2

// LIGHT STRUCTURE:
struct Light {
    float x, y, z;
    float r, g, b;
    float intensity;
};

// LIGHT ARRAY:
extern Light lights[3];



// ===================== CAMERA ======================

// TRANSLATION:
extern double cameraPosX;
extern double cameraPosY;
extern double cameraPosZ;

// ROTATION:
extern double cameraRotX;
extern double cameraRotY;
extern double cameraRotZ;

// CONTROL STEP:
extern double cameraMoveStep;   // how much camera moves per input
extern double cameraRotateStep; // how much camera rotates per input



// ===================== GLOBAL ======================

// TRANSLATION:
extern double globalPosX;
extern double globalPosY;
extern double globalPosZ;



// ===================== WASHER ======================

// TRANSLATION:
extern double washerPosX;
extern double washerPosY;
extern double washerPosZ;

// ROTATION:
extern double washerRotX;
extern double washerRotY;
extern double washerRotZ;

// CONTROL STEP:
extern double washerMoveStep;   // how much washer moves per input
extern double washerRotateStep; // how much washer rotates per input

// AUTO-ROTATION:
extern bool washerAutoRotateEnabled;



// ================== WASHER DOOR ====================

// ANIMATION:
extern bool washerDoorAnimEnabled; // animate door
extern bool washerDoorOpen;        // false - closing, true - opening

extern double washerDoorAngle;     // current angle
extern double washerDoorAngleMin;  // min angle
extern double washerDoorAngleMax;  // max angle



// =================== WASHER TANK ===================

// ANIMATION:
extern bool washerTankAnimEnabled;  // animate detergent tank
extern bool washerTankOpen;         // false - closing, true - opening

extern double washerTankOffset;     // current offset
extern double washerTankOffsetMin;  // min offset
extern double washerTankOffsetMax;  // max offset
extern double washerTankOffsetStep; // movement step



// ================= WASHER DISPLAY ==================

extern bool washerDisplayOn; // display on/off



// ===================== TEXTURES ======================

#define TEXTURE_COUNT 2

// IDs:
extern unsigned int textureIDs[TEXTURE_COUNT];

// FILE PATHS:
extern const char* textureFiles[TEXTURE_COUNT];

// DIMENSIONS:
extern int textureWidth[TEXTURE_COUNT];
extern int textureHeight[TEXTURE_COUNT];