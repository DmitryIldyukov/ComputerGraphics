#include "TextureHandle.h"

TextureHandle::TextureHandle(GLuint& texture)
	:m_texture(texture)
{
}

void TextureHandle::Delete()
{
	if (m_texture)
	{
		glDeleteTextures(1, &m_texture);
	}
}

void TextureHandle::Bind() const
{
	if (m_texture)
	{
		glBindTexture(GL_TEXTURE_2D, m_texture);
	}
}

GLuint TextureHandle::GetTexture()
{
	return m_texture;
}




