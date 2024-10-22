#pragma once
#include <glm/glm.hpp>
#include "Shader.h"
#include "Texture.h"

struct Material
{
	void CreateTextures(unsigned int _shaderID);
	void LinkTextures(unsigned int _shaderID);
	void Update(unsigned int _shaderID);
	void Draw();

private:
	Texture m_diffuseTexture{}, m_overlayTexture{};
};