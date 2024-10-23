#pragma once
#include "TextureHandle.h"
#include <array>
class TextureCube
{
public:
	TextureCube(glm::vec3 position, float size);
	void Draw() const;
	void SetTexture(TextureHandle& texture);
private:
	struct CubeFace
	{
		unsigned char vertex0;
		unsigned char vertex1;
		unsigned char vertex2;
		unsigned char vertex3;
		GLfloat tex0s, tex0t;
		GLfloat tex1s, tex1t;
		GLfloat tex2s, tex2t;
		GLfloat tex3s, tex3t;
	};

	static constexpr float VERTICES[8][3] = {
		{ -1, -1, -1 }, // 0
		{ +1, -1, -1 }, // 1
		{ +1, +1, -1 }, // 2
		{ -1, +1, -1 }, // 3
		{ -1, -1, +1 }, // 4
		{ +1, -1, +1 }, // 5
		{ +1, +1, +1 }, // 6
		{ -1, +1, +1 }, // 7
	};

	static constexpr CubeFace FACES[] = {
		{ 4, 7, 3, 0, 0, 0, 4, 0, 4, 4, 0, 4 }, // x<0
		{ 5, 1, 2, 6, 0, 4, 0, 0, 4, 0, 4, 4 }, // x>0
		{ 4, 0, 1, 5, 0, 4, 0, 0, 4, 0, 4, 4 }, // y<0
		{ 7, 6, 2, 3, 0, 0, 4, 0, 4, 4, 0, 4 }, // y>0
		{ 0, 3, 2, 1, 0, 4, 0, 0, 4, 0, 4, 4 }, // z<0
		{ 4, 5, 6, 7, 0, 0, 4, 0, 4, 4, 0, 4 }, // z>0
	};

	static unsigned constexpr FACE_COUNT = 6;

	std::array<std::array<float, 3>, 8> m_vertices;
	glm::vec3 m_position;
	float m_size;
	TextureHandle m_texture;
};