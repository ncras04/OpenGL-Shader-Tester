#include "Mesh.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include<glm/gtx/transform.hpp>
#include <iostream>
#include "Time.h"

void Mesh::Init(unsigned int _shaderID, std::vector<Vertex> _vectices, std::vector<unsigned int> _indices)
{
	vertices = _vectices;
	indices = _indices;

	CreateBuffers(_shaderID);
}

void Mesh::Update()
{
	
}

void Mesh::Draw()
{
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::CreateBuffers(unsigned int _shaderID)
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	m_vertexBuf.CreateBufferObject();
	m_vertexBuf.Bind(GL_ARRAY_BUFFER);
	m_vertexBuf.BufferFill(sizeof(Vertex) * vertices.size(), &vertices.front(), GL_STATIC_DRAW);
	
	m_indexBuf.CreateBufferObject();
	m_indexBuf.Bind(GL_ELEMENT_ARRAY_BUFFER);
	m_indexBuf.BufferFill(sizeof(unsigned int) * indices.size(), &indices.front(), GL_STATIC_DRAW);

	LinkAttributes(_shaderID);
}

void Mesh::LinkAttributes(unsigned int _shaderID)
{
	const char* attributeName = "_pos";
	unsigned int attributeID = glGetAttribLocation(_shaderID, attributeName);
	m_vertexBuf.SetAttributeID(attributeName, attributeID);
	m_vertexBuf.LinkAttribute(3, GL_FLOAT, false, sizeof(Vertex), 0);
	m_vertexBuf.EnableAttribute();

	attributeName = "_uv";
	attributeID = glGetAttribLocation(_shaderID, attributeName);
	m_vertexBuf.SetAttributeID(attributeName, attributeID);
	m_vertexBuf.LinkAttribute(2, GL_FLOAT, false, sizeof(Vertex), (void*)(sizeof(Vertex::position) + sizeof(Vertex::color) + sizeof(Vertex::normal)));
	m_vertexBuf.EnableAttribute();

}
