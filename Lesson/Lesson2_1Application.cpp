
//
//  Lesson2_1Application.cpp
//  Common
//
//  Created by HCM-B0233 on 2022/5/9.
//  Copyright © 2022 KuaiShou. All rights reserved.
//

#include "Lesson2_1Application.h"

BaseApplication *app = new Lesson2_1Application;

const std::vector<Program::ShaderConfig> Lesson2_1Application::getShaderConfigs() const
{
    return {
        {
            GL_VERTEX_SHADER,
            "Shader/Lesson2_1/vertex.glsl"
        },
        {
            GL_FRAGMENT_SHADER,
            "Shader/Lesson2_1/fragment.glsl"
        }
    };
}

void Lesson2_1Application::setup(GLFWwindow *window)
{
    BaseApplication::setup(window);
    GLfloat firstTriangle[] = {
        // 位置              // 颜色
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
    };
    
    // 创建VAO
    glGenVertexArrays(1, &vao);
    // 创建VBO
    glGenBuffers(1, &vbo);
    
    // 绑定VAO
    glBindVertexArray(vao);
    // 绑定VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // 把具体数据复制到当前的顶点缓冲对象中
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    // 定义如何解析顶点数据
    glVertexAttribPointer(vPosition, 3, GL_FLOAT,GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    // 以顶点属性位置值作为参数，启用顶点属性(顶点属性默认是禁用的)
    glEnableVertexAttribArray(vPosition);
    
    // 定义如何解析顶点数据
    glVertexAttribPointer(1, 3, GL_FLOAT,GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    // 以顶点属性位置值作为参数，启用顶点属性(顶点属性默认是禁用的)
    glEnableVertexAttribArray(1);
}


void Lesson2_1Application::draw()
{
    auto nowTime = glfwGetTime();
    printf("%f\n", nowTime);
    
    static const GLfloat black[] = { 0.2f, 0.2f, 0.2f, 0.0f };
    // 设置清空颜色缓冲区时使用的颜色为黑色。GL_COLOR、GL_DEPTH、GL_STENCIL
    glClearBufferfv(GL_COLOR, 0, black);
    // 清空颜色缓冲区
    glClear(GL_COLOR);
    
    glBindVertexArray(vao);
    // 绘制三角形，第一个参数为顶点绘制顺序，GL_TRIANGLE_FAN： 绘制各三角形形成一个扇形序列
    glDrawArrays(GL_TRIANGLES, 0,  vertexCount);
}


