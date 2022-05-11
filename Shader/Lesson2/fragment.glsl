#version 400 core

out vec4 faColor;
uniform vec4 vertexColor;

void main()
{
    faColor = vertexColor;
}
