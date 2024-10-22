#include "Material.h"
#include "Time.h"

Material::Material() : m_diffuseTexture{ "container.jpg", "diffuseTexture", 0 }, m_overlayTexture{ "saelogo.png", "overlayTexture", 1 } {}

void Material::LinkTextures()
{
	m_diffuseTexture.LinkTexture("diffuseTexture");
	m_overlayTexture.LinkTexture("overlayTexture");
}

void Material::Draw()
{
	m_diffuseTexture.Draw();
	m_overlayTexture.Draw();
}