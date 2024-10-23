#pragma once

#include "include.h"

class TextureHandle
{
public:
	TextureHandle() = default;
	TextureHandle(GLuint& texture);

	//����� ��� �������������
	void Delete();
	//���������� ����� �� ������, ��������������� ���� �������
	void Bind() const;
	GLuint GetTexture();
private:
	GLuint m_texture = 0;
};