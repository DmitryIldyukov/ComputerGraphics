#include "Window.h"
#include "DirectLight.h"
//ортонормированная матрица
namespace
{
	// Угол обзора по вертикали
	constexpr double FIELD_OF_VIEW = 60 * std::numbers::pi / 180.0;
	// Размер стороны куба

	constexpr double Z_NEAR = 0.1;
	constexpr double Z_FAR = 15;

	// Ортонормируем матрицу 4*4 (это должна быть аффинная матрица)
	glm::dmat4x4 Orthonormalize(glm::dmat4x4 const& m)
	{
		// Извлекаем подматрицу 3*3 из матрицы m и ортонормируем её
		auto const normalizedMatrix = glm::orthonormalize(glm::dmat3x3{ m });
		// Заменяем 3 столбца исходной матрицы
		return {
			glm::dvec4{ normalizedMatrix[0], 0.0 },
			glm::dvec4{ normalizedMatrix[1], 0.0 },
			glm::dvec4{ normalizedMatrix[2], 0.0 },
			m[3]
		};
	}
} // namespace

Window::Window(int w, int h, char const* title)
	: BaseWindow(w, h, title)
	, m_torFirst(m_centerFirst, false)
	, m_torSecond(m_centerSecond, true)
	, m_torThree(m_centerThree, true)
{

}

void Window::OnMouseButton(int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_1)
	{
		m_leftButtonPressed = (action & GLFW_PRESS) != 0;
	}
}

void Window::OnMouseMove(double x, double y)
{
	const glm::dvec2 mousePos{ x, y };
	if (m_leftButtonPressed)
	{
		auto const windowSize = GetFramebufferSize();

		auto const mouseDelta = mousePos - m_mousePos;
		double const xAngle = mouseDelta.y * std::numbers::pi / windowSize.y;
		double const yAngle = mouseDelta.x * std::numbers::pi / windowSize.x;
		RotateCamera(xAngle, yAngle);
	}
	m_mousePos = mousePos;
}

void Window::OnKeyDown(int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		m_torFirst.SetShowNormal();
		m_torSecond.SetShowNormal();
		m_torThree.SetShowNormal();
	}
}

// Вращаем камеру вокруг начала координат
void Window::RotateCamera(double xAngleRadians, double yAngleRadians)
{
	// Извлекаем из 1 и 2 строки матрицы камеры направления осей вращения,
	// совпадающих с экранными осями X и Y.
	// Строго говоря, для этого надо извлекать столбцы их обратной матрицы камеры, но так как
	// матрица камеры ортонормированная, достаточно транспонировать её подматрицу 3*3
	const glm::dvec3 xAxis{
		m_cameraMatrix[0][0], m_cameraMatrix[1][0], m_cameraMatrix[2][0]
	};
	const glm::dvec3 yAxis{
		m_cameraMatrix[0][1], m_cameraMatrix[1][1], m_cameraMatrix[2][1]
	};
	m_cameraMatrix = glm::rotate(m_cameraMatrix, xAngleRadians, xAxis);
	m_cameraMatrix = glm::rotate(m_cameraMatrix, yAngleRadians, yAxis);

	m_cameraMatrix = Orthonormalize(m_cameraMatrix);
}

void Window::OnResize(int width, int height)
{
	glViewport(0, 0, width, height);

	// Вычисляем соотношение сторон клиентской области окна
	double aspect = double(width) / double(height);

	glMatrixMode(GL_PROJECTION);
	auto const proj = glm::perspective(FIELD_OF_VIEW, aspect, Z_NEAR, Z_FAR);
	glLoadMatrixd(&proj[0][0]);
	glMatrixMode(GL_MODELVIEW);
}

void Window::OnRunStart()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Включаем режим отбраковки граней
	glEnable(GL_CULL_FACE);
	// Отбраковываться будут нелицевые стороны граней
	glCullFace(GL_FRONT);
	// Сторона примитива считается лицевой, если при ее рисовании
	// обход верших осуществляется против часовой стрелки
	glFrontFace(GL_CCW);

	// Включаем тест глубины для удаления невидимых линий и поверхностей
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	DirectLight light{ { 0.0f, 0.0f, 8.0f } };
	light.Apply(GL_LIGHT0);
}

void Window::Draw(int width, int height)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SetupCameraMatrix();

	m_torFirst.Draw();
	m_torSecond.Draw();
	m_torThree.Draw();
}

void Window::SetupCameraMatrix()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(&m_cameraMatrix[0][0]);
}
