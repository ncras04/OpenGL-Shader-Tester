#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>
struct Vertex
{
	Vertex(glm::vec3 _pos, glm::vec4 _col, glm::vec3 _nor, glm::vec2 _uv) : position{ _pos }, color{ _col }, normal{ _nor }, uvs{ _uv } {};

	glm::vec3 position;
	glm::vec4 color;
	glm::vec3 normal;
	glm::vec2 uvs;
};
#endif //!VERTEX_H

