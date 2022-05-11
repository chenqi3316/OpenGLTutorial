//
//  Lesson1_2Application.cpp
//  Common
//
//  Created by HCM-B0233 on 2022/5/9.
//  Copyright © 2022 KuaiShou. All rights reserved.
//

#include "Lesson1_2Application.h"

BaseApplication *app = new Lesson1_2Application;

const std::vector<Program::ShaderConfig> Lesson1_2Application::getShaderConfigs() const
{
    return {
        {
            GL_VERTEX_SHADER,
            "Shader/Lesson1/vertex.glsl"
        },
        {
            GL_FRAGMENT_SHADER,
            "Shader/Lesson1/fragment.glsl"
        }
    };
}

void Lesson1_2Application::setup(GLFWwindow *window)
{
    BaseApplication::setup(window);
    GLfloat firstTriangle[] = {
        -0.9f, -0.5f, 0.0f,  // left
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top
    };
    GLfloat secondTriangle[] = {
        0.0f, -0.5f, 0.0f,  // left
        0.9f, -0.5f, 0.0f,  // right
        0.45f, 0.5f, 0.0f   // top
    };
    
    // 创建VAO
    glGenVertexArrays(2, vaoList);
    // 创建VBO
    glGenBuffers(2, vboList);
    
    // 绑定VAO
    glBindVertexArray(vaoList[0]);
    // 绑定VBO
    glBindBuffer(GL_ARRAY_BUFFER, vboList[0]);
    // 把具体数据复制到当前的顶点缓冲对象中
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    // 定义如何解析顶点数据
    glVertexAttribPointer(vPosition, 3, GL_FLOAT,GL_FALSE, 0, nullptr);
    // 以顶点属性位置值作为参数，启用顶点属性(顶点属性默认是禁用的)
    glEnableVertexAttribArray(vPosition);
    
    
    // 绑定VAO
    glBindVertexArray(vaoList[1]);
    // 绑定VBO
    glBindBuffer(GL_ARRAY_BUFFER, vboList[1]);
    // 把具体数据复制到当前的顶点缓冲对象中
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
    // 定义如何解析顶点数据
    glVertexAttribPointer(vPosition, 3, GL_FLOAT,GL_FALSE, 0, nullptr);
    // 以顶点属性位置值作为参数，启用顶点属性(顶点属性默认是禁用的)
    glEnableVertexAttribArray(vPosition);
}


void Lesson1_2Application::draw()
{
    auto nowTime = glfwGetTime();
    printf("%f\n", nowTime);
    
    static const GLfloat black[] = { 0.2f, 0.2f, 0.2f, 0.0f };
    // 设置清空颜色缓冲区时使用的颜色为黑色。GL_COLOR、GL_DEPTH、GL_STENCIL
    glClearBufferfv(GL_COLOR, 0, black);
    // 清空颜色缓冲区
    glClear(GL_COLOR);
    
    glBindVertexArray(vaoList[0]);
    // 绘制三角形，第一个参数为顶点绘制顺序，GL_TRIANGLE_FAN： 绘制各三角形形成一个扇形序列
    glDrawArrays(GL_TRIANGLES, 0,  vertexCount);
    
    glBindVertexArray(vaoList[1]);
    glDrawArrays(GL_TRIANGLES, 0,  vertexCount);
}


