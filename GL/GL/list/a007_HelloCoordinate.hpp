//
//  a007_HelloCoordinate.hpp
//  GL
//
//  Created by yuebinbin on 2020/5/12.
//  Copyright © 2020 yuebinbin. All rights reserved.
//

#ifndef a007_HelloCoordinate_hpp
#define a007_HelloCoordinate_hpp

#include <stdio.h>

// 坐标系统测试
int a007_helloCoordinate();
// 更多旋转的3D物体
int a007_more3D();

// 练习题：
// 1. 对GLM的projection函数中的FoV和aspect-ratio参数进行实验。看能否搞懂它们是如何影响透视平截头体的。
//    答：Fov影响的是视野，角度越大视野越开阔；aspect-ratio参数影响的是宽高比，当传入的宽高比与view的宽高不同时，会按比例变形。
int a007_testProjection();
// 2. 将观察矩阵在各个方向上进行位移，来看看场景是如何改变的。注意把观察矩阵当成摄像机对象。
int a007_moveMat();
// 3. 使用模型矩阵只让是3倍数的箱子旋转（以及第1个箱子），而让剩下的箱子保持静止。
int a007_rotationWith3();

#endif /* a007_HelloCoordinate_hpp */
