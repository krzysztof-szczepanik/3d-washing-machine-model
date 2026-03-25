#include "input.hpp"
#include "globals.hpp"
#include "lighting.hpp"
#include "console.hpp"

#include <GLFW/glfw3.h>
#include <cmath>



// ================ HELPER FUNCTIONS =================


// GLOBALS:

static void handleExitKey(GLFWwindow* window, int key) {
    if (key == GLFW_KEY_ESCAPE) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}


// PROJECTION:

static void handleProjectionKeys(int key) {
    switch (key) {
		case GLFW_KEY_F1:
			projectionMode = ORTO;
			washerPosZ = -3;
			globalPosZ = -3;
			renderConsole();
			break;

		case GLFW_KEY_F2:
			projectionMode = FRUST;
			washerPosZ = -13;
			globalPosZ = -13;
			renderConsole();
			break;
    }
}

static void handleScaleKeys(int key) {
    switch (key) {
		case GLFW_KEY_F3:
			scaleMode = FULL_WINDOW;
			renderConsole();
			break;

		case GLFW_KEY_F4:
			scaleMode = ASPECT_1_1;
			renderConsole();
			break;
    }
}


// WASHER:

static void handleWasherKeys(int key, int mods) {

    // TRANSLATION:
    if (!(mods & GLFW_MOD_CONTROL) && !(mods & GLFW_MOD_ALT)) {
        switch (key) {
			case GLFW_KEY_W:
				washerPosY += washerMoveStep;
				renderConsole();
				return;

			case GLFW_KEY_A:
				washerPosX -= washerMoveStep;
				renderConsole();
				return;
				
			case GLFW_KEY_S:
				washerPosY -= washerMoveStep;
				renderConsole();
				return;

			case GLFW_KEY_D:
				washerPosX += washerMoveStep;
				renderConsole();
				return;

			case GLFW_KEY_KP_SUBTRACT:
				washerPosZ -= washerMoveStep;
				renderConsole();
				return;

			case GLFW_KEY_KP_ADD:
				washerPosZ += washerMoveStep;
				renderConsole();
				return;
        }
    }


    // ROTATION:
    if (!(mods & GLFW_MOD_CONTROL)) {
        switch (key) {
			case GLFW_KEY_KP_8:
				washerRotX -= washerRotateStep;
				return;

			case GLFW_KEY_KP_2:
				washerRotX += washerRotateStep;
				return;

			case GLFW_KEY_KP_6:
				washerRotY += washerRotateStep;
				return;

			case GLFW_KEY_KP_4:
				washerRotY -= washerRotateStep;
				return;

			case GLFW_KEY_KP_9:
				washerRotZ -= washerRotateStep;
				return;

			case GLFW_KEY_KP_7:
				washerRotZ += washerRotateStep;
				return;
        }
    }


    // AUTO-ROTATION:
    if (key == GLFW_KEY_R) {
        washerAutoRotateEnabled = !washerAutoRotateEnabled;
        renderConsole();
        return;
    }

    // DOOR ANIMATION:
    if (key == GLFW_KEY_P) {
        washerDoorAnimEnabled = true;
        washerDoorOpen = !washerDoorOpen;
        renderConsole();
        return;
    }

    // TANK ANIMATION:
    if (key == GLFW_KEY_O) {
        washerTankAnimEnabled = true;
        washerTankOpen = !washerTankOpen;
        renderConsole();
        return;
    }

    // DISPLAY ANIMATION:
    if (key == GLFW_KEY_I) {
        washerDisplayOn = !washerDisplayOn;
        renderConsole();
        return;
    }
}


// CAMERA:

static void handleCameraKeys(int key, int mods) {

    // TRANSLATION:
    if (mods & GLFW_MOD_CONTROL) {
        switch (key) {
			case GLFW_KEY_W:
				cameraPosY += cameraMoveStep;
				renderConsole();
				return;

			case GLFW_KEY_A:
				cameraPosX -= cameraMoveStep;
				renderConsole();
				return;
			
			case GLFW_KEY_S:
				cameraPosY -= cameraMoveStep;
				renderConsole();
				return;

			case GLFW_KEY_D:
				cameraPosX += cameraMoveStep;
				renderConsole();
				return;

			case GLFW_KEY_KP_SUBTRACT:
				cameraPosZ -= cameraMoveStep;
				renderConsole();
				return;
				
			case GLFW_KEY_KP_ADD:
				cameraPosZ += cameraMoveStep;
				renderConsole();
				return;
        }
    }


    // ROTATION:
    if (mods & GLFW_MOD_CONTROL) {
        switch (key) {
			case GLFW_KEY_KP_8:
				cameraRotX -= cameraRotateStep;
				return;

			case GLFW_KEY_KP_2:
				cameraRotX += cameraRotateStep;
				return;

			case GLFW_KEY_KP_6:
				cameraRotY += cameraRotateStep;
				return;

			case GLFW_KEY_KP_4:
				cameraRotY -= cameraRotateStep;
				return;

			case GLFW_KEY_KP_9:
				cameraRotZ -= cameraRotateStep;
				return;

			case GLFW_KEY_KP_7:
				cameraRotZ += cameraRotateStep;
				return;
        }
    }
}


// LIGHTING:

static void handleLightKeys(int key, int mods) {

    // TRANSLATION:
    if (mods & GLFW_MOD_ALT) {
        switch (key) {
            case GLFW_KEY_W:
                lights[selectedLight].y += lightMoveStep;
                updateLight(selectedLight);
                renderConsole();
                return;

            case GLFW_KEY_A:
                lights[selectedLight].x -= lightMoveStep;
                updateLight(selectedLight);
                renderConsole();
                return;

            case GLFW_KEY_S:
                lights[selectedLight].y -= lightMoveStep;
                updateLight(selectedLight);
                renderConsole();
                return;

            case GLFW_KEY_D:
                lights[selectedLight].x += lightMoveStep;
                updateLight(selectedLight);
                renderConsole();
                return;

            case GLFW_KEY_KP_SUBTRACT:
                lights[selectedLight].z -= lightMoveStep;
                updateLight(selectedLight);
                renderConsole();
                return;

            case GLFW_KEY_KP_ADD:
                lights[selectedLight].z += lightMoveStep;
                updateLight(selectedLight);
                renderConsole();
                return;
        }
    }
}

static void handleLightIntensity(int key, int mods) {

    if (!(mods & GLFW_MOD_ALT)) {
        return; // intensity changes only with ALT
	}

    switch (key) {
		case GLFW_KEY_COMMA:  // decrease intensity
			if (lights[selectedLight].intensity - lightIntensityStep >= -1e-6f) {
				lights[selectedLight].intensity -= lightIntensityStep;

				// normalize to exact zero when value is close to zero to avoid -0.0 in console:
				if (fabs(lights[selectedLight].intensity) < 1e-6f) {
					lights[selectedLight].intensity = 0.0f;
				}

				updateLight(selectedLight);
				renderConsole();
			}
			return;

		case GLFW_KEY_PERIOD: // increase intensity
			if (lights[selectedLight].intensity + lightIntensityStep <= 1.0f || lights[selectedLight].intensity + lightIntensityStep > 1.0f) {
				lights[selectedLight].intensity += lightIntensityStep;

				// clamp if overshoot:
				if (lights[selectedLight].intensity > 1.0f) {
					lights[selectedLight].intensity = 1.0f;
				}

				updateLight(selectedLight);
				renderConsole();
			}
			return;
    }
}

static void handleLightingOptions(int key, int mods) {
    switch (key) {

		// GLOBAL LIGHTING:
		case GLFW_KEY_GRAVE_ACCENT:
			lightingEnabled = !lightingEnabled;
			renderConsole();
			return;
		

		// LIGHT0:
		case GLFW_KEY_0:
			if (mods & GLFW_MOD_ALT) {
				selectedLight = 0;
			} else {
				lightEnabled0 = !lightEnabled0;
			}
			renderConsole();
			return;


		// LIGHT1:
		case GLFW_KEY_1:
			if (mods & GLFW_MOD_ALT) {
				selectedLight = 1;
			} else {
				lightEnabled1 = !lightEnabled1;
			}
			renderConsole();
			return;


		// LIGHT2:
		case GLFW_KEY_2:
			if (mods & GLFW_MOD_ALT) {
				selectedLight = 2;
			} else {
				lightEnabled2 = !lightEnabled2;
			}
			renderConsole();
			return;
    }
}


// RENDER:

static void handleRenderOptions(int key) {
    switch (key) {
		case GLFW_KEY_M: // CULLING
			iCull = !iCull;
			renderConsole();
			return;

		case GLFW_KEY_N: // DEPTH TEST
			iDepth = !iDepth;
			renderConsole();
			return;

		case GLFW_KEY_B: // OUTLINE MODE
			iOutline = !iOutline;
			renderConsole();
			return;

		case GLFW_KEY_V: // FLAT / SMOOTH SHADING
			iFill = !iFill;
			renderConsole();
			return;

		case GLFW_KEY_C: // CLOCKWISE / COUNTERCLOCKWISE
			iClock = !iClock;
			renderConsole();
			return;
    }
}



// ==================== FUNCTIONS ====================

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (action != GLFW_PRESS) return;

	handleExitKey(window, key);
    handleProjectionKeys(key);
    handleScaleKeys(key);

	handleCameraKeys(key, mods);
	handleLightKeys(key, mods);
	handleWasherKeys(key, mods);

	handleRenderOptions(key);

	handleLightingOptions(key, mods);
	handleLightIntensity(key, mods);
}