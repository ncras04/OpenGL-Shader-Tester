#pragma once
#include <GLAD/glad.h>

struct Buffer
{
	void CreateBufferObject();
	void SetAttributeID(const char*, GLuint);
	void Bind(GLenum);
	void BufferFill(GLsizeiptr, const void*, GLenum);
	void LinkAttribute(GLuint, GLenum, bool, GLsizei, const void*);
	void EnableAttribute();
	void Finalize();

private:
	GLenum m_target{};
	GLuint m_bufferID{}, m_attributeID{};

};

