//
//  b001_HelloLight.cpp
//  GL
//
//  Created by yuebinbin on 2020/5/14.
//  Copyright © 2020 yuebinbin. All rights reserved.
//

#include "b001_HelloLight.hpp"
#include "common.hpp"


const char *vertexShaderB001Source = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
    "}\0";

const char *fragmentShaderB001Source = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0);\n"
    "}\n\0";

int b001_helloLight() {
    
    return EXIT_SUCCESS;
}
