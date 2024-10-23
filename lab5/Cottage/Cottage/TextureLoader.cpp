#include "TextureLoader.h"

TextureHandle TextureLoader::LoadTexture(std::string const& filename, GLuint textureName, GLuint level) const
{
	int width, height, nrChannels;
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrChannels, STBI_rgb);

	if (!data)
	{
		throw std::runtime_error("Failed to load texture");
	}

	GLfloat maxAnisotropy;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);

	GLuint texture = 0;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAnisotropy);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//разобраться с mipmap
	//GL_TEXTURE_MAG_FILTER
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);



	glTexImage2D(GL_TEXTURE_2D, level, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	stbi_image_free(data);

	return TextureHandle(texture);
}

/*Непрерывный режим фильтрации (GL_NEAREST):
Этот режим использует ближайший texel для интерполяции цвета текстуры. Он обеспечивает более четкое изображение, но может привести к ступенчатым краям и пикселизации, особенно при увеличении масштаба текстуры.
Линейный режим фильтрации (GL_LINEAR):
Этот режим использует среднее значение соседних texels для интерполяции. Он обеспечивает более плавное изображение, чем режим GL_NEAREST, но может привести к размытости текстур, особенно при увеличении масштаба.
Мип-мап фильтрация (Mipmapping):
Mipmapping представляет собой технику, при которой создаются предварительно вычисленные уменьшенные версии текстур (mipmaps). При увеличении масштаба текстуры используется более низкое разрешение, что может помочь уменьшить артефакты и повысить производительность.
Анизотропная фильтрация (Anisotropic Filtering):
Анизотропная фильтрация - это расширение механизма фильтрации текстур, которое учитывает направления на поверхности текстуры. Она обеспечивает более точную фильтрацию текстур вдоль угловых направлений, что позволяет сохранить детали текстуры при разных углах обзора.
Она особенно полезна для уменьшения артефактов, таких как мерцание или искажение текстур при наблюдении под углами, например, на поверхности с наклонными или кривыми объектами.*/