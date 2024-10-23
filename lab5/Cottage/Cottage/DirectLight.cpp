#include "DirectLight.h"

DirectLight::DirectLight(glm::vec3 direction)
	: m_direction{ direction, 0.0f }
{
}

void DirectLight::SetDirection(glm::vec3 direction)
{
	m_direction = { direction, 1.0f }; 
}

void DirectLight::SetDiffuseIntensity(glm::vec4 color)
{
	m_diffuseColor = color;
}

void DirectLight::SetAmbientIntensity(glm::vec4 color)
{
	m_ambientColor = color;
}

void DirectLight::SetSpecularIntensity(glm::vec4 color)
{
	m_specularColor = color;
}

void DirectLight::Apply(GLenum light) const
{
	glLightfv(light, GL_POSITION, glm::value_ptr(m_direction));
	glLightfv(light, GL_AMBIENT, glm::value_ptr(m_ambientColor));
	glLightfv(light, GL_DIFFUSE, glm::value_ptr(m_diffuseColor));
	glLightfv(light, GL_SPECULAR, glm::value_ptr(m_specularColor));
}