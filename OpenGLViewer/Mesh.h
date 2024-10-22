#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Vertex.h"
#include "Shader.h"
#include "Material.h"
#include "Buffer.h"

struct Mesh
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	void Init(unsigned int, std::vector<Vertex> = std::vector<Vertex>{}, std::vector<unsigned int> = std::vector<unsigned int>{});
	void Update();
	void Draw();

	void CreateBuffers(unsigned int _shaderID);
	void LinkAttributes(unsigned int _shaderID);

private:
	Buffer m_vertexBuf{}, m_indexBuf{};
	unsigned int m_vao{};
};

#endif //!MESH_H

