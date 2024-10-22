#include "Material.h"
#include "Time.h"
void Material::CreateTextures(unsigned int _shaderID)
{
	m_diffuseTexture.Init("container.jpg", _shaderID, "diffuseTexture", 0);
	m_overlayTexture.Init("saelogo.png", _shaderID, "overlayTexture", 1);
}

void Material::LinkTextures(unsigned int _shaderID)
{
	m_diffuseTexture.LinkTexture(_shaderID, "diffuseTexture");
	m_overlayTexture.LinkTexture(_shaderID, "overlayTexture");
}

void Material::Update(unsigned int _shaderID)
{
	
}

void Material::Draw()
{
	m_diffuseTexture.Draw();
	m_overlayTexture.Draw();
}