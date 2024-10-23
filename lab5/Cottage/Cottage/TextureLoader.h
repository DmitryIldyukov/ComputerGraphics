#pragma once

#include "TextureHandle.h"
#include "stb_image.h"

class TextureLoader
{
public:
	TextureHandle LoadTexture(std::string const& filename, GLuint textureName = 0, GLuint level = 0) const;

private:

};