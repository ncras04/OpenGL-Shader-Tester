#ifndef MESHDATA_H
#define MESHDATA_H
#include <vector>
#include <glm/glm.hpp>
#include "Vertex.h"

static std::vector<Vertex> quadverts{
	//			pos						color					normal			uv
		{{-1.0f, -1.0f, 0.0f},	{0.0f,0.5f,0.1f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
		{{-1.0f,  1.0f, 0.0f},	{1.0f,0.5f,0.1f,1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
		{{ 1.0f,  1.0f, 0.0f},	{0.5f,0.5f,0.1f,1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
		{{ 1.0f, -1.0f, 0.0f},	{0.0f,0.5f,1.0f,1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
};

static std::vector<unsigned int> quadindices{ 0,3,2,0,2,1 };
#endif //!MESHDATA_H