#ifndef SSHADER_H
#define SSHADER_H

#include <GLAD/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

struct Shader
{
	unsigned int id{};
	inline Shader() {};
	Shader(const char* vertexPath, const char* fragmentPath);

	void Delete();

};
#endif //!SSHADER_H

