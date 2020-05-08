//
//  a004_HelloShader.hpp
//  GL
//
//  Created by yuebinbin on 2020/5/8.
//  Copyright © 2020 yuebinbin. All rights reserved.
//

#ifndef a004_HelloShader_hpp
#define a004_HelloShader_hpp

#include <stdio.h>
// 第一个shader程序
int a004_helloShader();

// 第一个uniform程序
int a004_shaderWithUniform();

// 尝试顶点数据中加入颜色值
int a004_shaderMoreAttrib();


// ----------------------------
// 练习题：
// 1. 修改顶点着色器让三角形上下颠倒
int a004_changeDownTriangle();

// 2. 使用uniform定义一个水平偏移量，在顶点着色器中使用这个偏移量把三角形移动到屏幕右侧
int a004_moveTriangle();

// 3. 使用out关键字把顶点位置输出到片段着色器，并将片段的颜色设置为与顶点位置相等（来看看连顶点位置值都在三角形中被插值的结果）。
//    做完这些后，尝试回答下面的问题：为什么在三角形的左下角是黑的?
//    回答：因为左下角坐标是负值，颜色范围是0～1，小于0的会被设置成0，所以一直为黑色，知道插值变为正值。
int a004_testShader();
#endif /* a004_HelloShader_hpp */
