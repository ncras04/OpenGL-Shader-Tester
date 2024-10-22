#include "Viewport.h"
#include "Vertex.h"

void HandleFramebufferSize(GLFWwindow* _window, int _width, int _height)
{
	glViewport(0, 0, _width, _height);
}

int Viewport::Initialize(void)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_pWindow = glfwCreateWindow(1000, 1000, "Texmex", NULL, NULL);
	glfwSetFramebufferSizeCallback(m_pWindow, HandleFramebufferSize);

	if (!m_pWindow)
	{
		std::cout << "ERROR: GLFW Window Creation failed!" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(m_pWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "ERROR: GLAD Initialisation failed" << std::endl;
		return -2;
	}

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	return 0;
}

int Viewport::Update(void)
{
	return 0;
}

int Viewport::Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	return 0;
}

int Viewport::LateDraw(void)
{
	glfwPollEvents();
	glfwSwapBuffers(m_pWindow);
	return 0;
}

void Viewport::Finalize(void)
{
	glfwTerminate();
}
