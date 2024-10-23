#include "Window.h"
#include "DirectLight.h"

namespace
{
	// Угол обзора по вертикали
	constexpr double FIELD_OF_VIEW = 60 * std::numbers::pi / 180.0;
	// Размер стороны куба

	constexpr double Z_NEAR = 0.1;
	constexpr double Z_FAR = 30;

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

	glm::vec4 ColorToVector(int color, float alpha)
	{
		auto const red = static_cast<float>((color >> 16) & 0xff) / 255.0f;
		auto const green = static_cast<float>((color >> 8) & 0xff) / 255.0f;
		auto const blue = static_cast<float>(color & 0xff) / 255.0f;

		return { red, green, blue, alpha };
	}
} // namespace

Window::Window(int w, int h, char const* title)
	: BaseWindow(w, h, title)
	, m_sky(15)
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

	m_cameraMatrix = Orthonormalize(m_cameraMatrix); //заменяет первые три столбца и строки исходной матрицы
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

void Window::OnKey(int key)
{
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		m_fogEnabled = false;
		m_fogColor = NO_FOG;
		break;
	case GLFW_KEY_SPACE:
		m_fogEnabled = true;
		m_fogColor = PLAIN_FOG;
		break;
	default:
		break;
	}
}

void Window::OnRunStart()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Включаем режим отбраковки граней
	glEnable(GL_CULL_FACE);
	// Отбраковываться будут нелицевые стороны граней
	glCullFace(GL_BACK);
	// Сторона примитива считается лицевой, если при ее рисовании
	// обход верших осуществляется против часовой стрелки
	glFrontFace(GL_CCW);

	// Включаем тест глубины для удаления невидимых линий и поверхностей
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Направление на источник света (совпадает с позицией наблюдателя)
	DirectLight light{ { 0.0f, 10.0f, 0.0f } };
	light.Apply(GL_LIGHT0);

	SetupTextures();
}

void Window::Draw(int width, int height)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SetupCameraMatrix();
	Fog();

	m_ground.Draw();
	m_cottage.Draw();
	m_sky.Draw();
}

void Window::SetupCameraMatrix()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(&m_cameraMatrix[0][0]);
}

void Window::Fog() const
{
	glClearColor(m_fogColor[0], m_fogColor[1], m_fogColor[2], m_fogColor[3]);
	glFogfv(GL_FOG_COLOR, glm::value_ptr(m_fogColor)); //цвет тумана
	glFogi(GL_FOG_MODE, GL_EXP); // вид тумана
	glFogf(GL_FOG_DENSITY, 0.1f); // плотность

	if (m_fogEnabled)
	{
		glEnable(GL_FOG);
	}
	else
	{
		glDisable(GL_FOG);
	}
}

void Window::SetupTextures()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_MAX_ANISOTROPY_EXT);

	m_groundTexture = m_textureLoader.LoadTexture("../Images/grass.png");
	m_ground.SetGroundTexture(m_groundTexture);

	m_wallTexture = m_textureLoader.LoadTexture("../Images/bricks.png");
	m_cottage.SetWallTexture(m_wallTexture);

	m_windowTexture = m_textureLoader.LoadTexture("../Images/glass.png");
	m_cottage.SetWindowTexture(m_windowTexture);

	m_door = m_textureLoader.LoadTexture("../Images/door.png");
	m_cottage.SetDoorTexture(m_door);

	m_garageDoorTexture = m_textureLoader.LoadTexture("../Images/garage_door.png");
	m_cottage.SetGarageDoorTexture(m_garageDoorTexture);

	m_roofTexture = m_textureLoader.LoadTexture("../Images/roof.png");
	m_cottage.SetRoofTexture(m_roofTexture);

	m_skyTexture = m_textureLoader.LoadTexture("../Images/sky.png");
	m_sky.SetTexture(m_skyTexture);
}