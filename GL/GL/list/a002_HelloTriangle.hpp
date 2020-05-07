//
//  a002_HelloTriangle.hpp
//  GL
//
//  Created by yuebinbin on 2020/5/6.
//  Copyright © 2020 yuebinbin. All rights reserved.
//

#ifndef a002_HelloTriangle_hpp
#define a002_HelloTriangle_hpp

#include <stdio.h>

int a002_hello_triangle();

// 练习题：
// 1. 添加更多顶点到数据中，使用glDrawArrays，尝试绘制两个彼此相连的三角形
int a002_twoTriangle();

// 2. 创建相同的两个三角形，但对它们的数据使用不同的VAO和VBO
int a002_twoTriangleByTwoData();

// 3. 创建两个着色器程序，第二个程序使用一个不同的片段着色器，输出黄色；再次绘制这两个三角形，让其中一个输出为黄色
int a002_twoTriangleDiffColor();

#endif /* a002_HelloTriangle_hpp */
