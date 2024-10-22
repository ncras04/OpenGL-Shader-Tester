#include "Shader.h"

GLuint Shader::shaderID{};

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream;
		std::stringstream fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR: Shader not read" << std::endl;
	}

	const char* vshaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	unsigned int vertex{};
	unsigned int fragment{};
	int success{};

	char infolog[512]{};

	vertex = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertex, 1, &vshaderCode, NULL);
	glCompileShader(vertex);

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infolog);
		std::cout << "SHADER COMPILATION FAILED" << std::endl
			<< infolog << std::endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infolog);
		std::cout << "SHADER COMPILATION FAILED" << std::endl
			<< infolog << std::endl;
	}

	shaderID = glCreateProgram();

	glAttachShader(shaderID, vertex);
	glAttachShader(shaderID, fragment);
	glLinkProgram(shaderID);

	glGetProgramiv(shaderID, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shaderID, 512, NULL, infolog);
		std::cout << "SHADER LINKING FAILED" << std::endl
			<< infolog << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	glUseProgram(shaderID);
}

void Shader::Delete()
{
	glDeleteProgram(shaderID);
}