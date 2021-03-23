//
//  Program.hpp
//  Common
//
//  Created by 陈奇 on 2021/3/23.
//  Copyright © 2021 Personal. All rights reserved.
//

#ifndef Program_hpp
#define Program_hpp

#include "Common.h"

class Program {
public:
    struct ShaderConfig
    {
        GLenum type;
        std::string filename;
    };
    Program();
    ~Program();
    
protected:
    GLuint _program;
    
public:
    GLuint program() const;
    bool load(const std::vector<Program::ShaderConfig> &shaders);
    GLuint getUniform(const std::string &name) const;
    void use() const;
};

#endif /* Program_hpp */
