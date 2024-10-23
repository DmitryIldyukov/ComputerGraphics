#pragma once
#include "include.h"
class Tor
{
public:
	Tor(glm::vec3& center, bool rotate);
	void Draw();
	void SetShowNormal();
	bool GetShowNormal();
	~Tor() = default;
private:
	glm::vec3 CalculatePoint(double angleMajor, double angleMinor) const;
	void NormalizeAndSetNormal(glm::vec3& point) const;
	void DrawNormal(glm::vec3& point) const;
	float m_radiusMinor = 1.0f, m_radiusMajor = 2.0f;
	int m_segmentsMinor = 100, m_segmentsMajor = 200;
	bool m_showNormal = false, m_rotate;
	float m_normalLength = 0.3f;
	glm::vec3 m_center;
};