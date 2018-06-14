//
//  FontAndColorMacros.h
//  iOSPro
//
//  Created by bean on 2018/6/14.
//  Copyright © 2018年 bean. All rights reserved.
//

/*
 FontAndColorMacros定义全局用的色值、字体大小，这里建议跟设计师共同维护一个设计规范，
 **/
#ifndef FontAndColorMacros_h
#define FontAndColorMacros_h

/*颜色*/

/**
 透明色
 */
#define KClearColor [UIColor clearColor]
/**
 白色
 */
#define KWhiteColor [UIColor whiteColor]
/**
 黑色
 */
#define KBlackColor [UIColor blackColor]
/**
 灰色
 */
#define KGrayColor [UIColor grayColor]
/**
 亮灰色
 */
#define KGray2Color [UIColor lightGrayColor]
/**
 蓝色
 */
#define KBlueColor [UIColor blueColor]
/**
 红色
 */
#define KRedColor [UIColor redColor]
/**
 随机色
 */
#define kRandomColorKRGBColor (arc4random_uniform(256)/255.0,arc4random_uniform(256)/255.0,arc4random_uniform(256)/255.0)


/*字体*/
/**
 加粗字体
 */
#define BOLDSYSTEMFONT(FONTSIZE)[UIFont boldSystemFontOfSize:FONTSIZE]
/**
 设置字体大小
 */
#define SYSTEMFONT(FONTSIZE)[UIFont systemFontOfSize:FONTSIZE]
/**
 设置字体样式和大小
 */
#define FONT(NAME,FONTSIZE)[UIFont fontWithName:(NAME)size:(FONTSIZE)]

#endif /* FontAndColorMacros_h */
