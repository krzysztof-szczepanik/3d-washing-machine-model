#include "console.hpp"
#include "globals.hpp"

#include <GLFW/glfw3.h>
#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;



// ================ HELPER FUNCTIONS =================

static void setConsoleColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

static void printShortcuts() {
	 cout << "======================================================== SHORTCUTS =========================================================" << endl;
	 cout << "                                                                                                                            " << endl;
	 cout << "  [ESC] - exit program                                     |                      ===== CAMERA =====                        " << endl;
	 cout << "                                                           |                                                                " << endl;
	 cout << "  PROJECTION MODE:             SCALE MODE:                 |   TRANSLATION IN X, Y:           TRANSLATION IN Z:             " << endl;
	 cout << "  [F1] - "; setConsoleColor((projectionMode == ORTO) ? 10 : 7); cout << "ORTO"; setConsoleColor(7); cout << "                  [F3] - "; setConsoleColor((scaleMode == FULL_WINDOW) ? 10 : 7); cout << "FULL_WINDOW"; setConsoleColor(7); cout << "          |   [CTRL + W] - UP                [CTRL + (NUMPAD +)] - CLOSER  " << endl;
	 cout << "  [F2] - "; setConsoleColor((projectionMode == FRUST) ? 10 : 7); cout << "FRUST"; setConsoleColor(7); cout << "                 [F4] - "; setConsoleColor((scaleMode == ASPECT_1_1) ? 10 : 7); cout << "ASPECT_1_1"; setConsoleColor(7); cout << "           |   [CTRL + S] - DOWN              [CTRL + (NUMPAD -)] - FARTHER " << endl;
	 cout << "                                                           |   [CTRL + A] - LEFT                                            " << endl;
	 cout << " ----------------------------------------------------------|   [CTRL + D] - RIGHT                                           " << endl;
	 cout << "                                                           |                                                                " << endl;
	 cout << "                                                           |                                                                " << endl;
	 cout << "  RENDER OPTIONS:                                          |   ROTATION:                                                    " << endl;
	 cout << "  [M] - "; setConsoleColor(iCull ? 10 : 12);    cout << "ICULL"; setConsoleColor(7);    cout << " (BACK-FACE CULLING)                         ";                                                                                       cout << " |   [CTRL + NUMPAD 7] - TILT LEFT                                " << endl;
	 cout << "  [N] - "; setConsoleColor(iDepth ? 10 : 12);   cout << "IDEPTH"; setConsoleColor(7);   cout << " (DEPTH TEST)     ";                                                                                        cout << "                           |   [CTRL + NUMPAD 9] - TILT RIGHT                               " << endl;
	 cout << "  [B] - "; setConsoleColor(iOutline ? 10 : 12); cout << "IOUTLINE"; setConsoleColor(7); cout << " (WIREFRAME PREVIEW)";                                                                                          cout << "                       |   [CTRL + NUMPAD 8] - ROTATE UP                                " << endl;
	 cout << "  [V] - "; setConsoleColor(iFill ? 10 : 12);    cout << "IFILL"; setConsoleColor(7);    cout << " (FLAT / SMOOTH SHADING)                   ";                                                                                       cout << "   |   [CTRL + NUMPAD 2] - ROTATE DOWN                              " << endl;
	 cout << "  [C] - "; setConsoleColor(iClock ? 10 : 12);   cout << "ICLOCK"; setConsoleColor(7);   cout << " (CLOCKWISE VERTEX ORDER)        ";                                                                                        cout << "            |   [CTRL + NUMPAD 4] - ROTATE LEFT                              " << endl;
	 cout << "                                                           |   [CTRL + NUMPAD 6] - ROTATE RIGHT                             " << endl;
	 cout << "                                                           |                                                                " << endl;
	 cout << " ----------------------------------------------------------|--------------------------------------------------------------- " << endl;
	 cout << "                                                           |                                                                " << endl;
	 cout << "                  ===== WASHER =====                       |                     ===== LIGHTING =====                       " << endl;
	 cout << "                                                           |                                                                " << endl;
	 cout << "  TRANSLATION IN X, Y:         TRANSLATION IN Z:           |   TRANSLATION IN X, Y:           TRANSLATION IN Z:             " << endl;
	 cout << "  [W] - UP                     [NUMPAD +] - CLOSER         |   [ALT + W] - UP                 [ALT + (NUMPAD +)] - CLOSER   " << endl;
	 cout << "  [S] - DOWN                   [NUMPAD -] - FARTHER        |   [ALT + S] - DOWN               [ALT + (NUMPAD -)] - FARTHER  " << endl;
	 cout << "  [A] - LEFT                                               |   [ALT + A] - LEFT                                             " << endl;
	 cout << "  [D] - RIGHT                                              |   [ALT + D] - RIGHT                                            " << endl;
	 cout << "                                                           |                                                                " << endl;
	 cout << "  ROTATION:                                                |   LIGHTING OPTIONS:                                            " << endl;
	 cout << "  [NUMPAD 7] - TILT LEFT                                   |   [~] - "; setConsoleColor(lightingEnabled ? 10 : 12); cout << "GLOBAL LIGHT     "; setConsoleColor(7); cout << "        SELECT LIGHT:                 " << endl;
	 cout << "  [NUMPAD 9] - TILT RIGHT                                  |   [0] - "; setConsoleColor(lightEnabled0 ? 10 : 12); cout << "DEFAULT LIGHT   "; setConsoleColor(7);   cout << "         [ALT + 0] - LIGHT0            " << endl;
	 cout << "  [NUMPAD 8] - ROTATE UP                                   |   [1] - "; setConsoleColor(lightEnabled1 ? 10 : 12); cout << "LIGHT1 (DIRECTIONAL)  "; setConsoleColor(7);   cout << "   [ALT + 1] - LIGHT1            " << endl;
	 cout << "  [NUMPAD 2] - ROTATE DOWN                                 |   [2] - "; setConsoleColor(lightEnabled2 ? 10 : 12); cout << "LIGHT2   "; setConsoleColor(7);   cout << "                [ALT + 2] - LIGHT2            " << endl;
	 cout << "  [NUMPAD 4] - ROTATE LEFT                                 |                                                                " << endl;
	 cout << "  [NUMPAD 6] - ROTATE RIGHT                                |   LIGHT INTENSITY:                                             " << endl;
	 cout << "                                                           |   [ALT + (>)] - INCREASE                                       " << endl;
	 cout << "  OTHER OPTIONS:                                           |   [ALT + (<)] - DECREASE                                       " << endl;
	 cout << "  [R] - "; setConsoleColor(washerAutoRotateEnabled ? 10 : 12); cout << "AUTO-ROTATION"; setConsoleColor(7); cout << "                                      |                                                                " << endl;
	 cout << "  [P] - WASHER DOOR ANIMATION                              |                                                                " << endl;
	 cout << "  [O] - WASHER TANK ANIMATION                              |   CURRENT LIGHT:                 "; setConsoleColor(6); cout << ((selectedLight == 0) ? "LIGHT0" : ((selectedLight == 1) ? "LIGHT1" : "LIGHT2")); setConsoleColor(7); cout << "                        " << endl;
	 cout << "  [I] - WASHER DISPLAY ANIMATION                           |                                                                " << endl;
	 cout << "                                                                                                                            " << endl;
	 cout << "============================================================================================================================" << endl;
}

static void printWasherAndLightPositions() {
	cout << endl << fixed << setprecision(1) << left;
	cout << "   |=== COORDINATES [WASHER] ===|=== COORDINATES [LIGHT0] ===|=== COORDINATES [LIGHT1] ===|=== COORDINATES [LIGHT2] ===|" << endl;
	cout << "   | X: " << setw(6) << washerPosX << "                  |" << " X: " << setw(6) << lights[0].x << "                  |" << " X: " << setw(6) << lights[1].x << "                  |" << " X: " << setw(6) << lights[2].x << "                  |" << endl;
	cout << "   | Y: " << setw(6) << washerPosY << "                  |" << " Y: " << setw(6) << lights[0].y << "                  |" << " Y: " << setw(6) << lights[1].y << "                  |" << " Y: " << setw(6) << lights[2].y << "                  |" << endl;
	cout << "   | Z: " << setw(6) << washerPosZ << "                  |" << " Z: " << setw(6) << lights[0].z << "                  |" << " Z: " << setw(6) << lights[1].z << "                  |" << " Z: " << setw(6) << lights[2].z << "                  |" << endl;
	cout << "   |                            |" << " INTENSITY:    " << setw(6) << lights[0].intensity << "       |" << " INTENSITY:    " << setw(6) << lights[1].intensity << "       |" << " INTENSITY:    " << setw(6) << lights[2].intensity << "       |" << endl;
	cout << "   |============================|============================|============================|============================|" << endl;
}

static void printLoadedTextures() {
	cout << endl << "LOADED TEXTURES:" << endl;

	for (int i = 0; i < TEXTURE_COUNT; i++) {
		cout << textureWidth[i] << " x " << textureHeight[i] << "\tindex: " << i << "\t [" << textureFiles[i] << "]" << endl;
	}

	cout << endl;
}



// ==================== FUNCTIONS ====================

void renderConsole() {
	system("cls");
	printShortcuts();
	printWasherAndLightPositions();
	printLoadedTextures();
}