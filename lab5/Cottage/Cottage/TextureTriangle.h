#pragma once

#include "TextureHandle.h"

class TextureTriangle
{
public:
	TextureTriangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3);

	void Draw() const;

	void SetTexture(TextureHandle& texture);
	void SetTextureScale(float scale);

private:
	glm::vec3 m_vertex1;
	glm::vec3 m_vertex2;
	glm::vec3 m_vertex3;

	float m_textureScale = 1;

	TextureHandle m_texture;
};