#include "Buffer.h"
#include <GLAD/glad.h>

void Buffer::CreateBufferObject()
{
	glGenBuffers(1, &m_bufferID);
}

void Buffer::SetAttributeID(const char* _name, GLuint _id)
{
	m_attributeID = _id;
}

void Buffer::Bind(GLenum _target)
{
	m_target = _target;
	glBindBuffer(m_target, m_bufferID);
}

void Buffer::BufferFill(GLsizeiptr _size, const void* _data, GLenum _usage)
{
	glBufferData(m_target, _size, _data, _usage);
}

void Buffer::LinkAttribute(GLuint _size, GLenum _type, bool _normalized, GLsizei _stride, const void* _pointer)
{
	glVertexAttribPointer(m_attributeID, _size, _type, _normalized, _stride, _pointer);
}

void Buffer::EnableAttribute()
{
	glEnableVertexAttribArray(m_attributeID);
}

void Buffer::Finalize()
{
	glDeleteBuffers(1, &m_bufferID);
}