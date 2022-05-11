//
//  Lesson2_2Application.hpp
//  使用uniform控制三角形在屏幕中左右移动
//
//  Created by HCM-B0233 on 2022/5/9.
//  Copyright © 2022 KuaiShou. All rights reserved.
//

#ifndef Lesson2_2Application_h
#define Lesson2_2Application_h

#include "Share/BaseApplication.h"

class Lesson2_2Application : public BaseApplication {
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

#endif /* Lesson2_2Application_h */


