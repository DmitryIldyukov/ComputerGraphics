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
	//����������� � mipmap
	//GL_TEXTURE_MAG_FILTER
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);



	glTexImage2D(GL_TEXTURE_2D, level, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	stbi_image_free(data);

	return TextureHandle(texture);
}

/*����������� ����� ���������� (GL_NEAREST):
���� ����� ���������� ��������� texel ��� ������������ ����� ��������. �� ������������ ����� ������ �����������, �� ����� �������� � ����������� ����� � ������������, �������� ��� ���������� �������� ��������.
�������� ����� ���������� (GL_LINEAR):
���� ����� ���������� ������� �������� �������� texels ��� ������������. �� ������������ ����� ������� �����������, ��� ����� GL_NEAREST, �� ����� �������� � ���������� �������, �������� ��� ���������� ��������.
���-��� ���������� (Mipmapping):
Mipmapping ������������ ����� �������, ��� ������� ��������� �������������� ����������� ����������� ������ ������� (mipmaps). ��� ���������� �������� �������� ������������ ����� ������ ����������, ��� ����� ������ ��������� ��������� � �������� ������������������.
������������ ���������� (Anisotropic Filtering):
������������ ���������� - ��� ���������� ��������� ���������� �������, ������� ��������� ����������� �� ����������� ��������. ��� ������������ ����� ������ ���������� ������� ����� ������� �����������, ��� ��������� ��������� ������ �������� ��� ������ ����� ������.
��� �������� ������� ��� ���������� ����������, ����� ��� �������� ��� ��������� ������� ��� ���������� ��� ������, ��������, �� ����������� � ���������� ��� ������� ���������.*/