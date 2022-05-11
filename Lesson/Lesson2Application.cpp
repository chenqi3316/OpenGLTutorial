//
//  Lesson2Application.cpp
//  Common
//
//  Created by HCM-B0233 on 2022/5/9.
//  Copyright © 2022 KuaiShou. All rights reserved.
//

#include "Lesson2Application.h"

BaseApplication *app = new Lesson2Application;

const std::vector<Program::ShaderConfig> Lesson2Application::getShaderConfigs() const
{
    return {
        {
            GL_VERTEX_SHADER,
            "Shader/Lesson2/vertex.glsl"
        },
        {
            GL_FRAGMENT_SHADER,
            "Shader/Lesson2/fragment.glsl"
        }
    };
}

void Lesson2Application::setup(GLFWwindow *window)
{
    BaseApplication::setup(window);
    // 创建VAO
    glGenVertexArrays(1, &vao);
    // 绑定VAO
    glBindVertexArray(vao);
    // 一个三角形
    GLfloat points[] = {
        -0.5f, -0.5f, 0.0f, // left
        0.5f, -0.5f, 0.0f, // right
        0.0f,  0.5f, 0.0f  // top
    };
    vertexCount = 3;
    
    // 两个三角形
//    GLfloat points[] = {
//        -0.5f, -0.5f, 0.0f, // left
//        0.0f, -0.5f, 0.0f, // right
//        -0.25f,  0.5f, 0.0f,  // top
//        0.0f, -0.5f, 0.0f, // left
//        0.5f, -0.5f, 0.0f, // right
//        0.25f,  0.5f, 0.0f  // top
//    };
//    vertexCount = 6;
    
    // 创建VBO
    glGenBuffers(1, &vbo);
    // 绑定VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // 把具体数据复制到当前的顶点缓冲对象中
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
    // 定义如何解析顶点数据
    glVertexAttribPointer(vPosition, 3, GL_FLOAT,GL_FALSE, 0, nullptr);
    // 以顶点属性位置值作为参数，启用顶点属性(顶点属性默认是禁用的)
    glEnableVertexAttribArray(vPosition);
}


void Lesson2Application::draw()
{
    auto nowTime = glfwGetTime();
    printf("%f\n", nowTime);
    
    float greenValue = (sin(nowTime) / 2.0f) + 0.5f;
    int vertexColorLocation = _program.getUniform("vertexColor");
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
    
    static const GLfloat black[] = { 0.2f, 0.2f, 0.2f, 0.0f };
    // 设置清空颜色缓冲区时使用的颜色为黑色。GL_COLOR、GL_DEPTH、GL_STENCIL
    glClearBufferfv(GL_COLOR, 0, black);
    // 清空颜色缓冲区
    glClear(GL_COLOR);
    
    glBindVertexArray(vao);
    // 绘制三角形，第一个参数为顶点绘制顺序，GL_TRIANGLE_FAN： 绘制各三角形形成一个扇形序列
    glDrawArrays(GL_TRIANGLES, 0,  vertexCount);
}


