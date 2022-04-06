//
//  BaseApplication.cpp
//  Common
//
//  Created by 陈奇 on 2021/3/23.
//  Copyright © 2021 Personal. All rights reserved.
//

#include "BaseApplication.h"

BaseApplication::BaseApplication() : _runTime(-1), _isFirstMouse(true)
{
}

void BaseApplication::preSetup()
{
}

void BaseApplication::setup(GLFWwindow *window)
{
    _window = window;
    loadShaders();
    getWindowSize();
}

void BaseApplication::draw()
{
}

void BaseApplication::destroy()
{
}

bool BaseApplication::loadShaders()
{
    auto configs = getShaderConfigs();
    auto res = _program.load(configs);
    if (res) {
        _program.use();
    }
    return res;
}

void BaseApplication::getWindowSize()
{
    glfwGetWindowSize(_window, &_windowWidth, &_windowHeight);
}

void BaseApplication::updateTime()
{
    auto time = glfwGetTime();
    if (_runTime < 0) {
        _runTime = time;
        _frameTime = 0;
    }
    else {
        _frameTime = time - _runTime;
        _runTime = time;
    }
}

static BaseApplication::MouseMoveCallback mouseMoveCallbackDelegate = nullptr;
static BaseApplication::MouseScrollCallback mouseScrollCallbackDelegate = nullptr;
static BaseApplication::KeyboardCallback keyboardCallbackDelegate = nullptr;

void BaseApplication::setMouseMoveCallback(MouseMoveCallback callback)
{
    glfwSetCursorPosCallback(_window, [](GLFWwindow *window, double x, double y) {
        mouseMoveCallbackDelegate(window, x, y);
    });
    
    mouseMoveCallbackDelegate = [this, callback](GLFWwindow *window, double x, double y) {
        y = _windowHeight - y;
        
        if (!_isFirstMouse) {
            _mouseDX = x - _mouseX;
            _mouseDY = y - _mouseY;
        }
        else {
            _isFirstMouse = false;
            _mouseDX = 0;
            _mouseDY = 0;
        }
        
        _mouseX = x;
        _mouseY = y;
        
        callback(window, x, y);
    };
}

void BaseApplication::setMouseScrollCallback(MouseScrollCallback callback)
{
    glfwSetScrollCallback(_window, [](GLFWwindow *window, double x, double y) {
        mouseScrollCallbackDelegate(window, x, y);
        
    });
    
    mouseScrollCallbackDelegate = callback;
}

void BaseApplication::setKeyboardCallback(KeyboardCallback callback)
{
    glfwSetKeyCallback(_window, [](GLFWwindow *window, int key, int scancode, int action, int modifiers) {
        keyboardCallbackDelegate(window, key, scancode, action, modifiers);
    });
    
    keyboardCallbackDelegate = callback;
}
