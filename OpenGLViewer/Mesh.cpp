#include "Mesh.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include<glm/gtx/transform.hpp>
#include <iostream>
#include "Time.h"
#include "Meshdata.h"

Mesh::Mesh()
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	m_vertexBuf.CreateBufferObject();
	m_vertexBuf.Bind(GL_ARRAY_BUFFER);
	m_vertexBuf.BufferFill(sizeof(Vertex) * vertices.size(), &vertices.front(), GL_STATIC_DRAW);

	m_indexBuf.CreateBufferObject();
	m_indexBuf.Bind(GL_ELEMENT_ARRAY_BUFFER);
	m_indexBuf.BufferFill(sizeof(unsigned int) * indices.size(), &indices.front(), GL_STATIC_DRAW);

	LinkAttributes();
}

Mesh::~Mesh()
{
	m_vertexBuf.Finalize(); 
	m_indexBuf.Finalize();
	glDeleteVertexArrays(1, &m_vao);
}

void Mesh::Draw()
{
	glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::LinkAttributes()
{
	const char* attributeName = "_pos";
	unsigned int attributeID = glGetAttribLocation(Shader::shaderID, attributeName);
	m_vertexBuf.SetAttributeID(attributeName, attributeID);
	m_vertexBuf.LinkAttribute(3, GL_FLOAT, false, sizeof(Vertex), 0);
	m_vertexBuf.EnableAttribute();

	attributeName = "_col";
	attributeID = glGetAttribLocation(Shader::shaderID, attributeName);
	m_vertexBuf.SetAttributeID(attributeName, attributeID);
	m_vertexBuf.LinkAttribute(4, GL_FLOAT, false, sizeof(Vertex), (void*)(sizeof(Vertex::position)));
	m_vertexBuf.EnableAttribute();

}
