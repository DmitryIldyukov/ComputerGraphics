#include "Ground.h"

Ground::Ground()
	:m_ground({ -8, -8, 0 }, { 0, 16, 0 }, { 16, 0, 0 })
{
}

void Ground::Draw() const
{
	m_ground.Draw();
}

void Ground::SetGroundTexture(TextureHandle& texture)
{
	m_ground.SetTexture(texture);
}
