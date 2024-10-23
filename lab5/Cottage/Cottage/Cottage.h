#pragma once

#include "TextureCube.h"
#include "TextureRectangle.h"
#include "TextureTriangle.h"

//выяснить почему на одном уровне текстура не будет отображаться
class Cottage
{
public:
	Cottage();

	void Draw() const;

	void SetWallTexture(TextureHandle& const texture);
	void SetWindowTexture(TextureHandle& const texture);
	void SetDoorTexture(TextureHandle& const door);
	void SetGarageDoorTexture(TextureHandle& const texture);
	void SetRoofTexture(TextureHandle& const texture);

private:
	TextureCube m_section1;
	TextureCube m_section2;
	TextureCube m_section3;

	TextureRectangle m_window1;
	TextureRectangle m_window2;

	TextureRectangle m_door;

	TextureRectangle m_garageDoor;

	TextureRectangle m_roofFront;
	TextureRectangle m_roofBack;

	TextureTriangle m_roofLeft;
	TextureTriangle m_roofRight;
};