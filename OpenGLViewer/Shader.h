#ifndef SSHADER_H
#define SSHADER_H

#include <GLAD/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

struct Shader
{
	Shader(const char* vertexPath = "Vertex.glsl", const char* fragmentPath = "Fragment.glsl");
	void Delete();

	static GLuint shaderID;

};
#endif //!SSHADER_H

