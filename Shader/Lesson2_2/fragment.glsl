#version 400 core

in vec3 vertexColor;
out vec3 faColor;

void main()
{
    faColor = vertexColor;
}
