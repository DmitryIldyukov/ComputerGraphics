#include "Cottage.h"

Cottage::Cottage()
	: m_section1({ -6, -2, 0 }, 4)
	, m_section2({ -2, -2, 0 }, 4)
	, m_section3({ 2, -1.5f, 0 }, 3)
	, m_window1({ -0.5f, -2.1f, 2 }, { 1, 0, 0 }, { 0, 0, -1 })
	, m_window2({ -4.5f, -2.1f, 2 }, { 1, 0, 0 }, { 0, 0, -1 })
	, m_door({ -2.5f, -2.1f, 2 }, { 1, 0, 0 }, { 0, 0, -2 })
	, m_garageDoor({ 2.3f, -1.6f, 2.5f }, { 2.2f, 0, 0 }, { 0, 0, -2.5f })
	, m_roofFront({ -6, -2, 4 }, { 0, 2, 3 }, { 8, 0, 0 })
	, m_roofBack({ -6, 0, 7 }, { 0, 2, -3 }, { 8, 0, 0 })
	, m_roofLeft({ -6, 2, 4 }, { -6, -2, 4 }, { -6, 0, 7 })
	, m_roofRight({ 2, -2, 4 }, { 2, 2, 4 }, { 2, 0, 7 })
{

}

void Cottage::Draw() const
{
	m_section1.Draw();
	m_section2.Draw();
	m_section3.Draw();

	m_window1.Draw();
	m_window2.Draw();

	m_door.Draw();

	m_garageDoor.Draw();

	m_roofFront.Draw();
	m_roofBack.Draw();
	m_roofLeft.Draw();
	m_roofRight.Draw();
}

void Cottage::SetWallTexture(TextureHandle& const texture)
{
	m_section1.SetTexture(texture);
}

void Cottage::SetWindowTexture(TextureHandle& const texture)
{
	m_window1.SetTexture(texture);
}

void Cottage::SetDoorTexture(TextureHandle& const door)
{
	m_door.SetTexture(door);
}

void Cottage::SetGarageDoorTexture(TextureHandle& const texture)
{
	m_garageDoor.SetTexture(texture);
}

void Cottage::SetRoofTexture(TextureHandle& const texture)
{
	m_roofFront.SetTexture(texture);
	m_roofBack.SetTexture(texture);
	m_roofLeft.SetTexture(texture);
	m_roofRight.SetTexture(texture);
}