#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "Shader.h"

struct Viewport
{															
	inline Viewport() {}
	inline GLFWwindow* GetWindow(void) { return m_pWindow; }

	int Initialize(void);
	int Update(void);
	int Draw(void);
	int LateDraw(void);
	void Finalize(void);

private:
	GLFWwindow* m_pWindow{};
	Shader m_shaderProgram{};
};
#endif // !VIEWPORT_H
