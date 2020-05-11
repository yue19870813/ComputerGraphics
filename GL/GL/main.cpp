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
#include "a005_HelloTexture.hpp"
#include "a006_HelloTransform.hpp"

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
//    return a004_shaderWithUniform();
    // 004 尝试顶点数据中加入颜色值
//    return a004_shaderMoreAttrib();
    // 004 修改顶点着色器让三角形上下颠倒
//    return a004_changeDownTriangle();
    // 004 把三角形移动到屏幕右侧
//    return a004_moveTriangle();
    // 004 测试用顶点位置插值设置顶点颜色
//    return a004_testShader();
    // 005 显示纹理
//    return a005_HelloTexture();
    // 005 纹理融合
//    return a005_MixTexture();
    // 005 纹理翻转
//    return a005_flipTexture();
    // 005 平铺4个纹理
//    return a005_wrappingTexture();
    // 005 调整纹理范围和纹理过滤
//    return a005_filterTexture();
    // 005 隐藏和显示纹理
//    return a005_hideTexture();
    // 006 矩阵变换
    return a006_helloTransform();
}

