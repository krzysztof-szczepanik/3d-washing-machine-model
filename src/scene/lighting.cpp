#include "lighting.hpp"
#include "globals.hpp"

#include <GLFW/glfw3.h>



// ==================== VARIABLES ====================

// LIGHT0:
GLfloat light_ambient0[]  = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat light_diffuse0[]  = {lights[0].r * lights[0].intensity,
	                         lights[0].g * lights[0].intensity,
							 lights[0].b * lights[0].intensity, 1.0f};
GLfloat light_specular0[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat light_position0[] = {lights[0].x, lights[0].y, lights[0].z, 0.0f};

// LIGHT1 (DIRECTIONAL):
GLfloat light_ambient1[]   = {0.25f, 0.25f, 0.25f, 1.0f};
GLfloat light_diffuse1[]   = {lights[1].r * lights[1].intensity,
	                          lights[1].g * lights[1].intensity,
							  lights[1].b * lights[1].intensity, 1.0f};
GLfloat light_specular1[]  = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat light_position1[]  = {lights[1].x, lights[1].y, lights[1].z, 1.0f};
GLfloat light_direction1[] = {0.0f, -1.0f, -1.0f, 0.0f};

// LIGHT2:
GLfloat light_ambient2[]  = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat light_diffuse2[]  = {lights[2].r * lights[2].intensity,
	                         lights[2].g * lights[2].intensity,
							 lights[2].b * lights[2].intensity, 1.0f};
GLfloat light_specular2[] = {1.0f, 0.0f, 0.0f, 1.0f};
GLfloat light_position2[] = {lights[2].x, lights[2].y, lights[2].z, 0.0f};

// MATERIAL PROPERTIES:
const GLfloat mat_ambient[]    = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat mat_diffuse[]    = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat mat_specular[]   = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat high_shininess[] = {100.0f};



// ==================== FUNCTIONS ====================

// Update selected light parameters:
void updateLight(int selectedLight) {

	if (selectedLight == 0) {
		light_position0[0] = lights[selectedLight].x;
		light_position0[1] = lights[selectedLight].y;
		light_position0[2] = lights[selectedLight].z;

		light_diffuse0[0] = lights[selectedLight].r * lights[selectedLight].intensity;
		light_diffuse0[1] = lights[selectedLight].g * lights[selectedLight].intensity;
		light_diffuse0[2] = lights[selectedLight].b * lights[selectedLight].intensity;

	} else if (selectedLight == 1) {
		light_position1[0] = lights[selectedLight].x;
		light_position1[1] = lights[selectedLight].y;
		light_position1[2] = lights[selectedLight].z;

		light_diffuse1[0] = lights[selectedLight].r * lights[selectedLight].intensity;
		light_diffuse1[1] = lights[selectedLight].g * lights[selectedLight].intensity;
		light_diffuse1[2] = lights[selectedLight].b * lights[selectedLight].intensity;

	} else if (selectedLight == 2) {
		light_position2[0] = lights[selectedLight].x;
		light_position2[1] = lights[selectedLight].y;
		light_position2[2] = lights[selectedLight].z;

		light_diffuse2[0] = lights[selectedLight].r * lights[selectedLight].intensity;
		light_diffuse2[1] = lights[selectedLight].g * lights[selectedLight].intensity;
		light_diffuse2[2] = lights[selectedLight].b * lights[selectedLight].intensity;
	}
}