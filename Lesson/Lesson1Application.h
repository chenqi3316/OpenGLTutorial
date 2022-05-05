//
//  Lesson1Application.hpp
//  Common
//
//  Created by HCM-B0233 on 2022/5/5.
//  Copyright © 2022 KuaiShou. All rights reserved.
//

#ifndef Lesson1Application_h
#define Lesson1Application_h

#include "Share/BaseApplication.h"

class Lesson1Application : public BaseApplication {
public:
    virtual void setup(GLFWwindow *window) override;
    virtual void draw() override;
    
protected:
    GLuint vao;
    GLuint vbo;
    
    enum Attrib_IDs { vPosition = 0 };
    
    const int circlePointsNumber = 360;
    
protected:
    virtual const std::vector<Program::ShaderConfig> getShaderConfigs() const override;
};

#endif /* Lesson1Application_h */

