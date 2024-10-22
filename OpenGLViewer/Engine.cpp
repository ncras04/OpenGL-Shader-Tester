#include "Engine.h"
#include "Shader.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Material.h"
#include "Time.h"
#include "Meshdata.h"

int Engine::Initialize(void)
{
    if (!glfwInit())
        return -1;

    m_viewport.Initialize();
    Time::Init();

    int texUnits{};
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &texUnits);
    std::cout << texUnits << std::endl;

    return 0;
}

int Engine::Run(void)
{
    Shader shaderProgram = Shader("Vertex.glsl", "Fragment.glsl");

    Material material{};
    material.CreateTextures(shaderProgram.id);

    Mesh mesh{};
    mesh.Init(shaderProgram.id, quadverts, quadindices);

    while (!glfwWindowShouldClose(m_viewport.GetWindow()))
    {
        Time::Update();
        
        if (glfwGetKey(m_viewport.GetWindow(), GLFW_KEY_SPACE) == GLFW_PRESS)
        {
            shaderProgram.Delete();
            shaderProgram = Shader("Vertex.glsl", "Fragment.glsl");
            mesh.LinkAttributes(shaderProgram.id);
            material.LinkTextures(shaderProgram.id);
        }

        m_viewport.Update();
        material.Update(shaderProgram.id);

        m_viewport.Draw();
        material.Draw();
        mesh.Draw();

		m_viewport.LateDraw();
    }

    return 0;
}