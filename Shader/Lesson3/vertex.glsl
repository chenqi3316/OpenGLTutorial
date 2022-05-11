#version 400 core

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vColor;

out vec3 vertexColor;
uniform float offsetX;
void main()
{
    gl_Position = vec4(vPosition.x + offsetX,-vPosition.y,vPosition.z,1.0);
    vertexColor = vColor;
}
