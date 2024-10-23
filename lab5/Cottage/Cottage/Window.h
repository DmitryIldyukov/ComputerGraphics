#pragma once
#include "BaseWindow.h"
#include "Cottage.h"
#include "TextureHandle.h"
#include "Ground.h"
#include "TextureLoader.h"
#include "Sky.h"
#include "include.h"
//разобрать с режимом фильтрации текстур и устранить мелт€шение путем использованием анизотропной фильтрации и уметь объ€снить дл€ чего, виды фильтрации, особенности
//разобратьс€ туманом
class Window : public BaseWindow
{
public:
	Window(int w, int h, char const* title);

private:
	void OnMouseButton(int button, int action, [[maybe_unused]] int mods) override;

	void OnMouseMove(double x, double y) override;

	// ??????? ?????? ?????? ?????? ?????????
	void RotateCamera(double xAngleRadians, double yAngleRadians);

	void OnResize(int width, int height) override;

	void OnKey(int key) override;

	void OnRunStart() override;

	void Draw(int width, int height) override;

	void SetupCameraMatrix();

	void Fog() const;

	void SetupTextures();


	// ?????????? ?? ?????? ?? ????? ????????
	static constexpr double DISTANCE_TO_ORIGIN = 12;
	static constexpr float SHAPE_ALPHA = 0.7f;

	static constexpr glm::vec4 NO_FOG = { 1, 1, 1, 1 };
	static constexpr glm::vec4 PLAIN_FOG = { 0.3f, 0.3f, 0.3f, 1 };

	bool m_leftButtonPressed = false;
	glm::dvec2 m_mousePos = {};
	glm::dmat4x4 m_cameraMatrix = glm::lookAt(
		glm::dvec3{ 1.5, 0.0, DISTANCE_TO_ORIGIN },
		glm::dvec3{ 1.5, 0.0, 0.0 },
		glm::dvec3{ 0.0, 1.0, 0.0 });
	bool m_fogEnabled = false;
	glm::vec4 m_fogColor = NO_FOG;

	Cottage m_cottage;
	Ground m_ground;
	Sky m_sky;

	TextureLoader m_textureLoader;
	TextureHandle m_groundTexture;

	TextureHandle m_wallTexture;
	TextureHandle m_windowTexture;
	TextureHandle m_door;

	TextureHandle m_garageDoorTexture;
	TextureHandle m_roofTexture;

	TextureHandle m_skyTexture;
};