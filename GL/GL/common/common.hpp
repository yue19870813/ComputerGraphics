//
//  common.hpp
//  GL
//
//  Created by yuebinbin on 2020/5/13.
//  Copyright © 2020 yuebinbin. All rights reserved.
//

#ifndef common_hpp
#define common_hpp

// Standard Headers
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
// OpenGL headers
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stb_image.h"
#include "filesystem.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);//回调函数原型声明
void processInput(GLFWwindow *window);


class GLFW {
public:
    GLFWwindow* init();
};

// 着色器通用类
class Shader {
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
    void setMat4(const std::string &name, glm::mat4 value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
private:
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif /* common_hpp */
