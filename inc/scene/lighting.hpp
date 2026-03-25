#pragma once

#include <GLFW/glfw3.h>



// ==================== VARIABLES ====================

// LIGHT0:
extern GLfloat light_ambient0[];
extern GLfloat light_diffuse0[];
extern GLfloat light_specular0[];
extern GLfloat light_position0[];

// LIGHT1 (DIRECTIONAL):
extern GLfloat light_ambient1[];
extern GLfloat light_diffuse1[];
extern GLfloat light_specular1[];
extern GLfloat light_position1[];
extern GLfloat light_direction1[];

// LIGHT2:
extern GLfloat light_ambient2[];
extern GLfloat light_diffuse2[];
extern GLfloat light_specular2[];
extern GLfloat light_position2[];

// MATERIAL PROPERTIES:
extern const GLfloat mat_ambient[];
extern const GLfloat mat_diffuse[];
extern const GLfloat mat_specular[];
extern const GLfloat high_shininess[];



// ==================== FUNCTIONS ====================

// Update selected light parameters:
void updateLight(int selectedLight);