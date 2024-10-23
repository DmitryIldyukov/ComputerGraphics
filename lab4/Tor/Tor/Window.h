#pragma once
#include "BaseWindow.h"
#include "Tor.h"

class Window : public BaseWindow
{
public:
	Window(int w, int h, char const* title);

private:
	void OnMouseButton(int button, int action, [[maybe_unused]] int mods) override;

	void OnMouseMove(double x, double y) override;

	void OnKeyDown(int key, int scancode, int action, int mods) override;

	// ??????? ?????? ?????? ?????? ?????????
	void RotateCamera(double xAngleRadians, double yAngleRadians);

	void OnResize(int width, int height) override;

	void OnRunStart() override;

	void Draw(int width, int height) override;

	void SetupCameraMatrix();

	glm::vec3 m_centerFirst = { 0, 0, 0 }, m_centerSecond = { 3, 0, 0 }, m_centerThree = { -3, 0, 0 };

	Tor m_torFirst, m_torSecond, m_torThree;
	// ?????????? ?? ?????? ?? ????? ????????
	static constexpr double DISTANCE_TO_ORIGIN = 8;
	static constexpr float SHAPE_ALPHA = 0.7f;

	bool m_leftButtonPressed = false;
	glm::dvec2 m_mousePos = {};
	glm::dmat4x4 m_cameraMatrix = glm::lookAt(
		glm::dvec3{ 0.0, 0.0, DISTANCE_TO_ORIGIN },
		glm::dvec3{ 0.0, 0.0, 0.0 },
		glm::dvec3{ 0.0, 1.0, 1.0 });
};