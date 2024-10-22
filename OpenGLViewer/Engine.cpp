#include "Engine.h"
#include "Shader.h"
#include "Mesh.h"
#include "Material.h"
#include "Time.h"

int Engine::Initialize(void)
{
	if (!glfwInit())
		return -1;

	m_pWindow = glfwCreateWindow(1000, 1000, "Texmex", NULL, NULL);

	if (!m_pWindow)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(m_pWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return -2;

	int texUnits{};
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &texUnits);
	std::cout << texUnits << std::endl;

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	return 0;
}

int Engine::Run(void)
{
	const char* vertexPath{ "Vertex.glsl" };
	const char* fragmentPath{ "Fragment.glsl" };

	Shader shaderProgram{ vertexPath, fragmentPath };
	Material material{};
	Mesh mesh{};

	while (!glfwWindowShouldClose(m_pWindow))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		Time::Update();

		if (glfwGetKey(m_pWindow, GLFW_KEY_SPACE) == GLFW_PRESS)
		{
			shaderProgram.Delete();
			shaderProgram = Shader(vertexPath, fragmentPath);
			mesh.LinkAttributes();
			material.LinkTextures();
		}

		material.Draw();
		mesh.Draw();

		glfwSwapBuffers(m_pWindow);
		glfwPollEvents();
	}

	glfwTerminate();

	m_pWindow = nullptr;

	return 0;
}