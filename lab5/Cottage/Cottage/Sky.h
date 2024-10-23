#pragma once
#include "TextureCube.h"
class Sky
{
public:
	Sky(float radius);
	void SetTexture(TextureHandle& texture);
	void Draw() const;
private:
	float m_radius;
	TextureHandle m_texture;
};