#include "ImageLoader.h"
#include "picoPNG.h"
#include "File.h"
#include "Error.h"

#include <iostream>

namespace lame {

	Texture ImageLoader::loadPNG(std::string filepath)
	{
		Texture texture = {};

		std::vector<unsigned char> in;
		std::vector<unsigned char> out;
		unsigned long width, height;

		if (File::readFileToBuffer(filepath, in) == false)
		{
			fatalError("Failed to load PNG file to buffer!");
		}

		int error = decodePNG(out, width, height, &(in[0]), in.size());
		if (error != 0)
		{
			fatalError("Decode PNG failed with error: " + std::to_string(error));
		}

		glGenTextures(1, &(texture.m_texture));

		glBindTexture(GL_TEXTURE_2D, texture.m_texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);

		texture.m_width = width;
		texture.m_height = height;

		return texture;
	}

}
