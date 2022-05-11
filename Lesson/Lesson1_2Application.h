//
//  Lesson1_2Application.hpp
//  创建相同的两个三角形，但对它们的数据使用不同的VAO和VBO
//
//  Created by HCM-B0233 on 2022/5/9.
//  Copyright © 2022 KuaiShou. All rights reserved.
//

#ifndef Lesson1_2Application_h
#define Lesson1_2Application_h

#include "Share/BaseApplication.h"

class Lesson1_2Application : public BaseApplication {
public:
    virtual void setup(GLFWwindow *window) override;
    virtual void draw() override;
    
protected:
    GLuint vaoList[2];
    GLuint vboList[2];
    
    enum Attrib_IDs { vPosition = 0 };

    int vertexCount = 3; // 顶点数量
    
protected:
    virtual const std::vector<Program::ShaderConfig> getShaderConfigs() const override;
};

#endif /* Lesson1Application_h */
