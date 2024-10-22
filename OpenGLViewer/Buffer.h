#pragma once
#include <GLAD/glad.h>

struct Buffer
{
	void CreateBufferObject();
	void SetAttributeID(const char*, unsigned int);
	void Bind(GLenum);
	void BufferFill(GLsizeiptr, const void*, GLenum);
	void LinkAttribute(unsigned int, GLenum, bool, GLsizei, const void*);
	void EnableAttribute();
	void Finalize();

private:

	unsigned int m_bufferID;
	unsigned int m_attributeID;
	GLenum m_target;

};

