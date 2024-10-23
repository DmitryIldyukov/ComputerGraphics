#pragma once
#include "BaseWindow.h"
#include "Dodecahedron.h"

struct ObjectDistancePair {
	const Dodecahedron* object;
	float distanceFromCamera;
};

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

	void OnRunStart() override;

	void Draw(int width, int height) override;

	void SetupCameraMatrix();

	glm::vec3 m_centerFirst = { 2.0f, 1.0f, 0.5f };
	glm::vec3 m_centerSecond = { 0.0f, 0.0f, 0.0f };

	Dodecahedron m_dodecahedronFirst;
	Dodecahedron m_dodecahedronSecond;

	// ?????????? ?? ?????? ?? ????? ????????
	static constexpr double DISTANCE_TO_ORIGIN = 9;
	static constexpr float SHAPE_ALPHA = 0.7f;

	bool m_leftButtonPressed = false;
	glm::dvec2 m_mousePos = {};
	glm::dmat4x4 m_cameraMatrix = glm::lookAt(
		glm::dvec3{ 1, 0.5, DISTANCE_TO_ORIGIN },
		glm::dvec3{ 1, 0.5, 0.25 },
		glm::dvec3{ 0.0, 1.0, 0.0 });

};