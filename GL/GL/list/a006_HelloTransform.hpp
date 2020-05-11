//
//  a006_HelloTransform.hpp
//  GL
//
//  Created by yuebinbin on 2020/5/11.
//  Copyright © 2020 yuebinbin. All rights reserved.
//

#ifndef a006_HelloTransform_hpp
#define a006_HelloTransform_hpp

#include <stdio.h>

// 矩阵变换
int a006_helloTransform();

// 练习题：
// 1. 使用应用在箱子上的最后一个变换，尝试将其改变为先旋转，后位移。看看发生了什么，试着想想为什么会发生这样的事情？
int a006_rotationAndMove();

// 2. 尝试再次调用glDrawElements画出第二个箱子，只使用变换将其摆放在不同的位置。让这个箱子被摆放在窗口的左上角，并且会不断的缩放（而不是旋转）。（sin函数在这里会很有用，不过注意使用sin函数时应用负值会导致物体被翻转）
int a006_draw2Box();

#endif /* a006_HelloTransform_hpp */
