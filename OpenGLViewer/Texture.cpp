#include "Texture.h"

void Texture::Init(const std::string& _path, unsigned int _shaderID, const char* _uniformname, int _unit)
{
	m_unit = _unit;

	stbi_set_flip_vertically_on_load(true);
	unsigned char* buffer = stbi_load(_path.c_str(), &m_width, &m_height, &m_bitsPerPixel, 4);

	if (buffer)
	{
		glGenTextures(1, &m_id);
		glBindTexture(GL_TEXTURE_2D, m_id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);

		stbi_image_free(buffer);
		LinkTexture(_shaderID, _uniformname);
	}
}

void Texture::LinkTexture(unsigned int _shaderID, const char* _uniformname)
{
	m_texUniform = glGetUniformLocation(_shaderID, _uniformname);
	glUniform1i(m_texUniform, m_unit);
}

void Texture::Draw()
{
	if (m_id)
	{
		glActiveTexture(GL_TEXTURE0 + m_unit);
		glBindTexture(GL_TEXTURE_2D, m_id);
	}
}


