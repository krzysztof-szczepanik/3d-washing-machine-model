#include "projection.hpp"
#include "globals.hpp"

#include <GLFW/glfw3.h>



// ==================== FUNCTIONS ====================

void applyProjection(int width, int height) {
    if (projectionMode == ORTO) {
        if (scaleMode == ASPECT_1_1) {
            if (width < height && width > 0) {
                glOrtho(-viewSize, viewSize, -viewSize * height / width, viewSize * height / width, -viewSize, viewSize);
            }
            else {
                if (width >= height && height > 0) {
                    glOrtho(-viewSize * width / height, viewSize * width / height, -viewSize, viewSize, -viewSize, viewSize);
                }
            }
        }
        else {
            glOrtho(-viewSize, viewSize, -viewSize, viewSize, -viewSize, viewSize);
        }
    }

    if (projectionMode == FRUST) {
        if (scaleMode == ASPECT_1_1) {
            if (width < height && width > 0) {
                glFrustum(-viewSize, viewSize, -viewSize * height / width, viewSize * height / width, nearPlane, farPlane);
            }
            else {
                if (width >= height && height > 0) {
                    glFrustum(-viewSize * width / height, viewSize * width / height, -viewSize, viewSize, nearPlane, farPlane);
                }
            }
        }
        else {
            glFrustum(-viewSize, viewSize, -viewSize, viewSize, nearPlane, farPlane);
        }
    }
}