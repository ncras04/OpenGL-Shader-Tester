#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Shader.h"
#include "stb_image.h"

struct Texture
{
	Texture(const std::string& _path, const char* _uName, int _unit);
	~Texture();
	void LinkTexture(const char* _uniformname);
	void Draw();

private:
	GLuint m_id{}, m_texUniform{};
	int m_width{}, m_height{}, m_bitsPerPixel{}, m_unit{};
};
