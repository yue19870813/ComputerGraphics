//
//  a000_common.hpp
//  GL
//
//  Created by yuebinbin on 2020/5/6.
//  Copyright © 2020 yuebinbin. All rights reserved.
//

#ifndef a000_common_hpp
#define a000_common_hpp

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <stdio.h>
// Standard Headers
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);//回调函数原型声明
void processInput(GLFWwindow *window);


// 着色器通用类
class Shader
{
public:
    // 程序ID
    unsigned int ID;

    // 构造器读取并构建着色器
    Shader(const GLchar* vertexStr, const GLchar* fragmentStr);
    // 使用/激活程序
    void use();
    // uniform工具函数
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
private:
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif /* a000_common_hpp */
