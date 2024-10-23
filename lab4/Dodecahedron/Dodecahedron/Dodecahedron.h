#pragma once
#include "include.h"
//сделать 2 додэкэдра, вращение точкой между ними
//на что влияет обход вершин 
class Dodecahedron
{
public:
	Dodecahedron(glm::vec3& center, bool reduced);

	void DrawSolidParts() const;
	void DrawTransparentParts() const;

	void SetSideColor(std::size_t side, glm::vec4 const& color);
private:
	void DrawOutline() const;
	void DrawFaces(GLenum face) const;

	static inline double GOLDEN_RATIO = 2 / (1 + std::sqrt(5));
	//вершины
	static inline double const VERTICES[20][3] = {
		{ 1, 1, 1 },
		{ 1, 1, -1 },
		{ 1, -1, 1 },
		{ 1, -1, -1 },
		{ -1, 1, 1 },
		{ -1, 1, -1 },
		{ -1, -1, 1 },
		{ -1, -1, -1 },

		{ 0, (1 - GOLDEN_RATIO * GOLDEN_RATIO), (1 + GOLDEN_RATIO) },
		{ 0, (1 - GOLDEN_RATIO * GOLDEN_RATIO), -(1 + GOLDEN_RATIO) },
		{ 0, -(1 - GOLDEN_RATIO * GOLDEN_RATIO), (1 + GOLDEN_RATIO) },
		{ 0, -(1 - GOLDEN_RATIO * GOLDEN_RATIO), -(1 + GOLDEN_RATIO) },

		{ (1 - GOLDEN_RATIO * GOLDEN_RATIO), (1 + GOLDEN_RATIO), 0 },
		{ (1 - GOLDEN_RATIO * GOLDEN_RATIO), -(1 + GOLDEN_RATIO), 0 },
		{ -(1 - GOLDEN_RATIO * GOLDEN_RATIO), (1 + GOLDEN_RATIO), 0 },
		{ -(1 - GOLDEN_RATIO * GOLDEN_RATIO), -(1 + GOLDEN_RATIO), 0 },

		{ (1 + GOLDEN_RATIO), 0, (1 - GOLDEN_RATIO * GOLDEN_RATIO) },
		{ (1 + GOLDEN_RATIO), 0, -(1 - GOLDEN_RATIO * GOLDEN_RATIO) },
		{ -(1 + GOLDEN_RATIO), 0, (1 - GOLDEN_RATIO * GOLDEN_RATIO) },
		{ -(1 + GOLDEN_RATIO), 0, -(1 - GOLDEN_RATIO * GOLDEN_RATIO) }
	};



	//грани
	static constexpr int FACES[12][5] = {
		{ 8, 10, 2, 16, 0 },
		{ 12, 14, 4, 8, 0 },
		{ 16, 17, 1, 12, 0 },
		{ 17, 3, 11, 9, 1 },
		{ 9, 5, 14, 12, 1 },
		{ 10, 6, 15, 13, 2 },
		{ 13, 3, 17, 16, 2 },
		{ 13, 15, 7, 11, 3 },
		{ 18, 6, 10, 8, 4 },
		{ 14, 5, 19, 18, 4 },
		{ 9, 11, 7, 19, 5 },
		{ 6, 18, 19, 7, 15 },
	};

	static size_t constexpr FACE_COUNT = 12;

	glm::vec3 m_center;
	glm::vec4 m_colors[12];
	glm::vec4 m_specularColor = { 0.3f, 0.3f, 0.3f, 1 };

	bool m_reduced;
	float m_shininess = 1;
};