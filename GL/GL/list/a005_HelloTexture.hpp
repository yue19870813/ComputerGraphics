//
//  a005_HelloTexture.hpp
//  GL
//
//  Created by yuebinbin on 2020/5/8.
//  Copyright © 2020 yuebinbin. All rights reserved.
//

#ifndef a005_HelloTexture_hpp
#define a005_HelloTexture_hpp

#include <stdio.h>
// 第一个纹理
int a005_HelloTexture();
// 纹理融合
int a005_MixTexture();

// --------------------------------------
// 练习题：
// 1. 修改片段着色器，仅让笑脸图案朝另一个方向看。
int a005_flipTexture();

// 2. 尝试用不同的纹理环绕方式，设定一个从0.0f到2.0f范围内的（而不是原来的0.0f到1.0f）纹理坐标。试试看能不能在箱子的角落放置4个笑脸.
int a005_wrappingTexture();

// 3. 尝试在矩形上只显示纹理图像的中间一部分，修改纹理坐标，达到能看见单个的像素的效果。尝试使用GL_NEAREST的纹理过滤方式让像素显示得更清晰
int a005_filterTexture();

// 4. 使用一个uniform变量作为mix函数的第三个参数来改变两个纹理可见度，使用上和下键来改变箱子或笑脸的可见度
int a005_hideTexture();

#endif /* a005_HelloTexture_hpp */
