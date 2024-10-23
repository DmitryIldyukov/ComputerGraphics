#pragma once
#include "include.h"
class DirectLight
{
public:
	explicit DirectLight(glm::vec3 direction);

	void SetDirection(glm::vec3 direction);
	void SetDiffuseIntensity(glm::vec4 color);
	void SetAmbientIntensity(glm::vec4 color);
	void SetSpecularIntensity(glm::vec4 color);

	void Apply(GLenum light)const;
private:
	glm::vec4 m_direction;
	glm::vec4 m_diffuseColor{ 0.8f, 0.8f, 0.8f, 1.0f };
	glm::vec4 m_ambientColor{ 0.2f, 0.2f, 0.2f, 1.0f };
	glm::vec4 m_specularColor{ 0.5f, 0.5f, 0.5f, 1.0f };
};