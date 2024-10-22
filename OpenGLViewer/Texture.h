#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Shader.h"
#include "stb_image.h"

struct Texture
{
	void Init(const std::string& _path, unsigned int, const char* _uName, int _unit);
	void Draw();
	void LinkTexture(unsigned int _shaderID, const char* _uniformname);

private:
	unsigned int m_id{};
	unsigned int m_texUniform{};
	int m_width{}, m_height{}, m_bitsPerPixel{}, m_unit{};

};
