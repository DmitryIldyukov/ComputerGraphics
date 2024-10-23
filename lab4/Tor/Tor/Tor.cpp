#include "Tor.h"

Tor::Tor(glm::vec3& center, bool rotate)
	:m_center(center)
	,m_rotate(rotate)
{
}

glm::vec3 Tor::CalculatePoint(double angleMajor, double angleMinor) const
{
    double x = (m_radiusMajor + m_radiusMinor * cos(angleMajor)) * cos(angleMinor) + m_center.x;
    double y = (m_radiusMajor + m_radiusMinor * cos(angleMajor)) * sin(angleMinor) + m_center.y;
    double z = m_radiusMinor * sin(angleMajor) + m_center.z;

    return { x, y, z };
}

void Tor::NormalizeAndSetNormal(glm::vec3 &point) const
{
    double normalizeX = point.x - m_center.x;
    double normalizeY = point.y - m_center.y;
    double normalizeZ = point.z - m_center.z;


    double length = sqrt(normalizeX * normalizeX + normalizeY * normalizeY + normalizeZ * normalizeZ);
    normalizeX /= length;
    normalizeY /= length;
    normalizeZ /= length;

    glNormal3f(float(normalizeX), float(normalizeY), float(normalizeZ));
}

void Tor::Draw() {
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    if (m_rotate) {
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
    }

    for (size_t i = 0; i <= m_segmentsMajor; i++) {
        glBegin(GL_TRIANGLE_STRIP);
        for (size_t m = 0; m <= m_segmentsMinor; m++) {
            double angleMajor = 2 * M_PI * i / m_segmentsMajor;
            double angleMinor = 2 * M_PI * m / m_segmentsMinor;

            glm::vec3 point = CalculatePoint(angleMajor, angleMinor);

            //устранить дублирование кода
            NormalizeAndSetNormal(point);
            
            glColor3f(float(abs(point.x / 2.5)), float(abs(point.y / 2.5)), float(abs(point.z / 2.5)));
            glVertex3f(float(point.x), float(point.y), float(point.z));

            angleMajor = 2 * M_PI * (i + 1) / m_segmentsMajor;
            angleMinor = 2 * M_PI * (m + 1) / m_segmentsMinor;
            //разобраться для чего важна нормализация нормалей
            //Нормализация нормалей - это процесс приведения векторов нормалей к единичной длине, то есть деление каждого компонента вектора на его евклидову норму
            //освещение, отражение света, тени
            //как найти угол между 2 векторами
            point = CalculatePoint(angleMajor, angleMinor);

            NormalizeAndSetNormal(point);

            glColor3f(float(abs(point.x / 2.5)), float(abs(point.y / 2.5)), float(abs(point.z / 2.5)));
            glVertex3f(float(point.x), float(point.y), float(point.z));
        }
        glEnd();
    }


    if (m_showNormal) {
        glColor3f(1.0f, 1.0f, 1.0f); // Белый цвет для нормалей
        glBegin(GL_LINES);
        for (size_t i = 0; i <= m_segmentsMajor; i++) {
            for (size_t m = 0; m <= m_segmentsMinor; m++) {
                double angleMajor = 2 * M_PI * i / m_segmentsMajor;
                double angleMinor = 2 * M_PI * m / m_segmentsMinor;
                    
                glm::vec3 point = CalculatePoint(angleMajor, angleMinor);

                DrawNormal(point);

                angleMajor = 2 * M_PI * (i + 1) / m_segmentsMajor;
                angleMinor = 2 * M_PI * (m + 1) / m_segmentsMinor;

                point = CalculatePoint(angleMajor, angleMinor);
                
                DrawNormal(point);
            }
        }
        glEnd();
    }

    if (m_rotate) {
        glPopMatrix();
    }
}

void Tor::DrawNormal(glm::vec3& point) const
{
    double normalizeX = point.x - 1.5f;
    double normalizeY = point.y;
    double normalizeZ = point.z ;

    double length = sqrt(normalizeX * normalizeX + normalizeY * normalizeY + normalizeZ * normalizeZ);
    normalizeX /= length;
    normalizeY /= length;
    normalizeZ /= length;

    glVertex3f(float(point.x), float(point.y), float(point.z));
    glVertex3f(float(point.x + normalizeX * m_normalLength), float(point.y + normalizeY * m_normalLength), float(point.z + normalizeZ * m_normalLength));
}



void Tor::SetShowNormal()
{
	if (m_showNormal)
	{
		m_showNormal = false;
	}
	else
	{
		m_showNormal = true;
	}
}

bool Tor::GetShowNormal()
{
	return m_showNormal;
}
