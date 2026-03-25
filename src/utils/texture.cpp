#include "texture.hpp"
#include "globals.hpp"
#include "stb_image.h"

#include <GLFW/glfw3.h>



// ==================== FUNCTIONS ====================

void loadTextures() {
    glGenTextures(TEXTURE_COUNT, textureIDs); // create texture objects (IDs stored in textureIDs[])

	for (int i = 0; i < TEXTURE_COUNT; i++) {
		GLint iWidth, iHeight, nrChannels;

        // Activate texture slot and bind texture ID:
		glBindTexture(GL_TEXTURE_2D, textureIDs[i]);

        // Texture wrapping mode (clamp edges instead of repeating):
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); // if texture coordinates exceed 1.0, texture repeats horizontally
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); // if texture coordinates exceed 1.0, texture repeats vertically

        // Texture filtering:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // pixelated when scaled down
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);  // smooth when scaled up

        // Flip image vertically to match OpenGL coordinate system:
		stbi_set_flip_vertically_on_load(true);

        // Load texture file into memory:
		unsigned char* data = stbi_load(textureFiles[i], &iWidth, &iHeight, &nrChannels, 0);

		textureWidth[i] = iWidth;
		textureHeight[i] = iHeight;

        // Upload texture data to GPU:
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iWidth, iHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        // Free CPU memory after upload:
		stbi_image_free(data);
	}
}