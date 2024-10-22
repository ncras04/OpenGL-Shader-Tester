#ifndef ENGINE_H
#define ENGINE_H

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

struct Engine
{
	int Initialize(void);												
	int Run(void);

private:
	GLFWwindow* m_pWindow{};
};

#endif // !ENGINE_H

