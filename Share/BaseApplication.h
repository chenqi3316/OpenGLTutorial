//
//  BaseApplication.h
//  Common
//
//  Created by 陈奇 on 2021/3/23.
//  Copyright © 2021 Personal. All rights reserved.
//

#ifndef BaseApplication_h
#define BaseApplication_h

#include "Common.h"
#include "Program.h"

class BaseApplication {
    
public:
    BaseApplication();
    virtual void preSetup();
    virtual void setup(GLFWwindow *window);
    virtual void draw();
    virtual void destroy();
    
protected:
    virtual const std::vector<Program::ShaderConfig> getShaderConfigs() const = 0;
    virtual bool loadShaders();
    Program _program;
    GLFWwindow *_window;
    
protected:
    void getWindowSize();
    void updateTime();
    int _windowWidth, _windowHeight;
    bool _isFirstMouse;
    double _mouseX, _mouseY;
    double _mouseDX, _mouseDY;
    double _scrollX, _scollY;
    double _runTime, _frameTime;
    
public:
    typedef std::function<void (GLFWwindow *window, double x, double y)> MouseMoveCallback;
    typedef std::function<void (GLFWwindow *window, double x, double y)> MouseScrollCallback;
    typedef std::function<void (GLFWwindow *window, int key, int scancode, int action, int modifiers)> KeyboardCallback;
    
    void setMouseMoveCallback(MouseMoveCallback callback);
    void setMouseScrollCallback(MouseScrollCallback callback);
    void setKeyboardCallback(KeyboardCallback callback);
};

#endif /* BaseApplication_h */
