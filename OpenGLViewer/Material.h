#pragma once
#include <glm/glm.hpp>
#include "Shader.h"
#include "Texture.h"

struct Material
{
	Material();
	void LinkTextures();
	void Draw();

private:
	Texture m_diffuseTexture, m_overlayTexture;
};