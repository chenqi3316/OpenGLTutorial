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
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    auto r = 1.f;
    auto points = new GLfloat[circlePointsNumber * 2 ];
    auto d = 2 * acos(-1) / circlePointsNumber;
    for (int i = 0; i < circlePointsNumber; ++i) {
        points[i * 2] = cosf(i * d) * r;
        points[i * 2 + 1] = sinf(i * d) * r;
    }
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 2 * circlePointsNumber * sizeof(GLfloat), points, GL_STATIC_DRAW);
    
    glVertexAttribPointer(vPosition, 2, GL_FLOAT,
                          GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(vPosition);
}


void Lesson1Application::draw()
{
    auto nowTime = glfwGetTime();
    printf("%f\n", nowTime);
    
    static const GLfloat black[] = { 0.2f, 0.2f, 0.2f, 0.0f };
    
    glClearBufferfv(GL_COLOR, 0, black);
    glClear(GL_COLOR);
    
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_FAN, 0,  circlePointsNumber);
}
