//
//  Program.cpp
//  Common
//
//  Created by 陈奇 on 2021/3/23.
//  Copyright © 2021 Personal. All rights reserved.
//

#include "Program.h"

Program::Program()
{
    _program = 0;
}

bool Program::load(const std::vector<Program::ShaderConfig> &shaders)
{
    auto program = glCreateProgram();
    
    for (auto &config : shaders) {
        auto shader = glCreateShader(config.type);
        auto file = fopen(config.filename.c_str(), "r");
        if (!file) {
            printf("[Error] Shader Not Found: %s\n", config.filename.c_str());
            return false;
        }
        
        fseek(file, 0, SEEK_END);
        auto len = ftell(file);
        fseek(file, 0, SEEK_SET);
        auto code = new GLchar[len + 1];
        memset(code, 0, len + 1);
        fread(code, sizeof(GLchar), len, file);
        fclose(file);
        
        glShaderSource(shader, 1, &code, nullptr);
        delete []code;
        
        glCompileShader(shader);
        GLint isCompiled;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
        if (!isCompiled) {
            GLsizei len;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
            GLchar *log = new GLchar[len + 1];
            glGetShaderInfoLog(shader, len, &len, log);
            printf("[Error] Shader Compile Fail: %s\n%s\n", config.filename.c_str(), log);
            delete [] log;
            return false;
        }
        
        glAttachShader(program, shader);
    }
    
    glLinkProgram(program);
    
    GLint isLinked;
    glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
    if (!isLinked) {
        GLsizei len;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
        GLchar *log = new GLchar[len + 1];
        glGetProgramInfoLog(program, len, &len, log);
        printf("[Error] Shader Link Fail:\n%s\n", log);
        delete [] log;
        return false;
    }
    
    _program = program;
    
    return true;
}

Program::~Program()
{
    if (_program) {
        glDeleteProgram(_program);
    }
}

GLuint Program::program() const
{
    return _program;
}

GLuint Program::getUniform(const std::string &name) const
{
    if (!_program) {
        return 0;
    }
    return glGetUniformLocation(_program, name.c_str());
}

void Program::use() const
{
    glUseProgram(_program);
}
