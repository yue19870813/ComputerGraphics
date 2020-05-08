//
//  main.cpp
//  GL
//
//  Created by yuebinbin on 2020/4/30.
//  Copyright © 2020 yuebinbin. All rights reserved.
//

// System Headers
#include "a001_HelloWorld.hpp"
#include "a002_HelloTriangle.hpp"
#include "a003_HelloRect.hpp"
#include "a004_HelloShader.hpp"

int main(int argc, char * argv[]) {
    // 001 hello world
//    return a001_hello();
    // 002 第一个三角形
//    return a002_hello_triangle();
    // 002 练习题 两个三角形
//    return a002_twoTriangle();
    // 002 练习题 两个三角形 两组顶点数据
//    return a002_twoTriangleByTwoData();
    // 002 练习题 两个三角形 两种颜色
//    return a002_twoTriangleDiffColor();
    // 003 第一个矩形
//    return a003_HelloRect();
    // 004 第一个着色器
//    return a004_helloShader();
    // 004 在着色器中使用uniform
    return a004_shaderWithUniform();
}

