//
//  Lesson1_1Application.hpp
//  绘制三角形
//
//  Created by HCM-B0233 on 2022/5/9.
//  Copyright © 2022 KuaiShou. All rights reserved.
//

#ifndef Lesson1_1Application_h
#define Lesson1_1Application_h

#include "Share/BaseApplication.h"

class Lesson1_1Application : public BaseApplication {
public:
    virtual void setup(GLFWwindow *window) override;
    virtual void draw() override;
    
protected:
    GLuint vao;
    GLuint vbo;
    
    enum Attrib_IDs { vPosition = 0 };

    int vertexCount = 3; // 顶点数量
    
protected:
    virtual const std::vector<Program::ShaderConfig> getShaderConfigs() const override;
};

#endif /* Lesson1Application_h */
