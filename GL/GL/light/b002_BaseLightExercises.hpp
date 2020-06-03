//
//  b002_BaseLightExercises.hpp
//  GL
//
//  Created by yuebinbin on 2020/6/3.
//  Copyright © 2020 yuebinbin. All rights reserved.
//

#ifndef b002_BaseLightExercises_hpp
#define b002_BaseLightExercises_hpp

#include <stdio.h>

// 1. 目前，我们的光源时静止的，你可以尝试使用sin或cos函数让光源在场景中来回移动。观察光照随时间的改变能让你更容易理解冯氏光照模型。
int b002_moveLight();

// 2.  尝试使用不同的环境光、漫反射和镜面强度，观察它们怎么是影响光照效果的。同样，尝试实验一下镜面光照的反光度因子。尝试理解为什么某一个值能够有着某一种视觉输出。

// 3. 在观察空间（而不是世界空间）中计算冯氏光照.
int b002_lightInViewport();

// 4. 尝试实现一个Gouraud着色（而不是冯氏着色）。如果你做对了话，立方体的光照应该会看起来有些奇怪，尝试推理为什么它会看起来这么奇怪.
int b002_ligthByGourand();

#endif /* b002_BaseLightExercises_hpp */
