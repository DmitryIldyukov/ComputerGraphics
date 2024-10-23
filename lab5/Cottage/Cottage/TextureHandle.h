#pragma once

#include "include.h"

class TextureHandle
{
public:
	TextureHandle() = default;
	TextureHandle(GLuint& texture);

	//класс был некопируемымы
	void Delete();
	//доработать чтобы он удалял, воспользовалсчя этим методом
	void Bind() const;
	GLuint GetTexture();
private:
	GLuint m_texture = 0;
};