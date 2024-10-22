#version 400 core

in vec3 _pos;

void main()
{
	gl_Position = vec4(_pos, 1.0);
}