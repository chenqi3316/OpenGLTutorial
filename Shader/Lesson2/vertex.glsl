#version 400 core

layout(location = 0) in vec4 vPosition;
out vec4 vertexColor;
void main()
{
    gl_Position = vPosition;
    vertexColor = vec4(0.0, 1.0, 1.0, 1.0);
}
