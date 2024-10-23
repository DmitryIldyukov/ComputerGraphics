#include "Sky.h"

Sky::Sky(float radius)
	: m_radius(radius)
{
}

void Sky::SetTexture(TextureHandle& texture)
{
    m_texture = texture;
}

void Sky::Draw() const
{
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<unsigned int> indices;
    const unsigned int segments = 36;
    const unsigned int rings = 18;

    for (unsigned int ring = 0; ring <= rings; ++ring) {
        m_texture.Bind();
        float phi = static_cast<float>(ring) * glm::pi<float>() / static_cast<float>(rings);
        float sinPhi = std::sin(phi);
        float cosPhi = std::cos(phi);
        for (unsigned int segment = 0; segment <= segments; ++segment) {
            float theta = static_cast<float>(segment) * 2.0f * glm::pi<float>() / static_cast<float>(segments);
            float sinTheta = std::sin(theta);
            float cosTheta = std::cos(theta);
            glm::vec3 vertex(sinTheta * sinPhi, cosPhi, cosTheta * sinPhi);
            glm::vec2 uv(static_cast<float>(segment) / segments, static_cast<float>(ring) / rings);
            vertices.push_back(vertex * m_radius);
            uvs.push_back(uv);
        }
    }

    for (unsigned int ring = 0; ring < rings; ++ring) {
        for (unsigned int segment = 0; segment < segments; ++segment) {
            indices.push_back((ring + 1) * (segments + 1) + segment);
            indices.push_back(ring * (segments + 1) + segment);
            indices.push_back(ring * (segments + 1) + segment + 1);

            indices.push_back((ring + 1) * (segments + 1) + segment);
            indices.push_back(ring * (segments + 1) + segment + 1);
            indices.push_back((ring + 1) * (segments + 1) + segment + 1);
        }
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices.data());

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, uvs.data());

    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, indices.data());

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}
