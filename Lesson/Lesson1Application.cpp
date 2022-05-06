//
//  Lesson1Application.cpp
//  Common
//
//  Created by HCM-B0233 on 2022/5/5.
//  Copyright © 2022 KuaiShou. All rights reserved.
//

#include "Lesson1Application.h"

BaseApplication *app = new Lesson1Application;

const std::vector<Program::ShaderConfig> Lesson1Application::getShaderConfigs() const
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

void Lesson1Application::setup(GLFWwindow *window)
{
    BaseApplication::setup(window);
    // 创建VAO
    glGenVertexArrays(1, &vao);
    // 绑定VAO
    glBindVertexArray(vao);
    
    auto r = 1.f;
    auto points = new GLfloat[circlePointsNumber * 2 ];
    auto d = 2 * acos(-1) / circlePointsNumber;
    for (int i = 0; i < circlePointsNumber; ++i) {
        points[i * 2] = cosf(i * d) * r;
        points[i * 2 + 1] = sinf(i * d) * r;
    }
    // 创建VBO
    glGenBuffers(1, &vbo);
    // 绑定VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // 把具体数据复制到当前的顶点缓冲对象中
    glBufferData(GL_ARRAY_BUFFER, 2 * circlePointsNumber * sizeof(GLfloat), points, GL_STATIC_DRAW);
    // 定义如何解析顶点数据
    glVertexAttribPointer(vPosition, 2, GL_FLOAT,
                          GL_FALSE, 0, nullptr);
    // 以顶点属性位置值作为参数，启用顶点属性(顶点属性默认是禁用的)
    glEnableVertexAttribArray(vPosition);
}


void Lesson1Application::draw()
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
    glDrawArrays(GL_TRIANGLE_FAN, 0,  circlePointsNumber);
}
