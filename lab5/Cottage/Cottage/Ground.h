#pragma once
#include "TextureRectangle.h"
class Ground
{
public:
	Ground();
	void Draw() const;
	void SetGroundTexture(TextureHandle& texture);
private:
	TextureRectangle m_ground;
};