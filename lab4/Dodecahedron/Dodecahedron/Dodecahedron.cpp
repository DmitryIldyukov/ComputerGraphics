#include "Dodecahedron.h"
Dodecahedron::Dodecahedron(glm::vec3& center, bool reduced)
	:m_center(center)
	,m_reduced(reduced)
{
	constexpr glm::vec4 defaultColor{ 1, 1, 1, 1 };
	for (std::size_t i = 0; i < FACE_COUNT; ++i)
	{
		SetSideColor(i, defaultColor);
	}
}

void Dodecahedron::DrawSolidParts() const
{
	if (m_reduced) 
	{
		glPushMatrix();
		glScalef(0.3f, 0.3f, 0.3f);
	}
	DrawOutline();
	if (m_reduced)
	{
		glPopMatrix();
	}
}


void Dodecahedron::DrawTransparentParts() const
{
	if (m_reduced)
	{
		glPushMatrix();
		glScalef(0.3f, 0.3f, 0.3f);
	}
	DrawFaces(GL_FRONT);
	DrawFaces(GL_BACK);
	if (m_reduced)
	{
		glPopMatrix();
	}
}

void Dodecahedron::SetSideColor(std::size_t side, glm::vec4 const& color)
{
	m_colors[side] = color;
}

void Dodecahedron::DrawOutline() const
{
	glEnable(GL_COLOR_MATERIAL);

	for (auto facePoints : FACES)
	{
		glColor4f(0, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
		for (std::size_t i = 0; i < 5; ++i)
		{
			double newX = VERTICES[facePoints[i]][0] + m_center.x;
			double newY = VERTICES[facePoints[i]][1] + m_center.y;
			double newZ = VERTICES[facePoints[i]][2] + m_center.z;
			glVertex3d(newX, newY, newZ);
		}
		glEnd();
	}
}

void Dodecahedron::DrawFaces(GLenum face) const
{
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, glm::value_ptr(m_specularColor)); //цвет отражение
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m_shininess); //кф блеска

	glCullFace(face); //отсекание граней

	for (std::size_t face = 0; face < FACE_COUNT; ++face)
	{
		auto const facePoints = FACES[face];
		auto const p0 = glm::make_vec3(VERTICES[facePoints[0]]);
		auto const p1 = glm::make_vec3(VERTICES[facePoints[1]]);
		auto const p2 = glm::make_vec3(VERTICES[facePoints[2]]);


		auto const v01 = p1 - p0;
		auto const v02 = p2 - p0;
		auto const normal = glm::normalize(glm::cross(v01, v02));

		glNormal3dv(glm::value_ptr(normal));

		glColor4fv(glm::value_ptr(m_colors[face]));
		glBegin(GL_TRIANGLE_FAN);
		for (std::size_t i = 0; i < 5; ++i)
		{
			double newX = VERTICES[facePoints[i]][0] + m_center.x;
			double newY = VERTICES[facePoints[i]][1] + m_center.y;
			double newZ = VERTICES[facePoints[i]][2] + m_center.z;
			glVertex3d(newX, newY, newZ);
		}
		glEnd();
	}
}
