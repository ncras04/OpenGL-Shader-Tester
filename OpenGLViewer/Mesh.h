#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Vertex.h"
#include "Shader.h"
#include "Material.h"
#include "Buffer.h"
#include "Meshdata.h"

struct Mesh
{
	std::vector<Vertex> vertices{ quadverts };
	std::vector<unsigned int> indices{ quadindices };

	Mesh();
	~Mesh();
	void LinkAttributes();
	void Draw();

private:
	GLuint m_vao{};
	Buffer m_vertexBuf{}, m_indexBuf{};
};

#endif //!MESH_H

