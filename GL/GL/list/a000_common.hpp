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

#endif /* a000_common_hpp */
