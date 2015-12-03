//
//  Defines.h
//  网易新闻阅读器的Demo
//
//  Created by apple on 15/12/1.
//  Copyright © 2015年 Archy. All rights reserved.
//


#if (DEBUG || TESTCASE)
#define FxLog(format, ...) NSLog(format, ## __VA_ARGS__)
// ## __VA_ARGS__ 是宏 顾名思义，它是一个可变参数，即可变参数宏（variadic  macros）,是一个保留字。其中＃＃的作用防止可变参数为无的情况下，可能发生的bug。 (看了@TomatoPeter 的《Release版本的Log问题》理解了这段代码)
#else
#define FxLog(format, ...)      // NSLog在deBug阶段可以使用，但是在Release阶段不再被使用
#endif

// 日志输出宏
#define BASE_LOG(cls,sel) FxLog(@"%@-%@",NSStringFromClass(cls),NSStringFromSelector(sel))   //Log日志，记录了计算机程序工作情况
#define BASE_ERROR_LOG(cls,sel,error) FxLog(@"ERROR:%@-%@-%@",NSStringFromClass(cls), NSStringFromSelector(sel), error)
#define BASE_INFO_LOG(cls,sel,info) FxLog(@"INFO:%@-%@-%@", NSStringFromClass(cls), NSStringFromSelector(sel), info)

// 日志输出函数
#if (DEBUG || TESTCASE)
#define BASE_LOG_FUN(self,_cmd)           BASE_LOG([self class], _cmd)  // _cmd在Objective-C的方法中表示当前方法的selector.
#define BASE_ERROR_FUN(self,_cmd,error)   BASE_ERROR_LOG([self class],_cmd,error)
//#define BASE_INFO_FUN(self,_cmd,info)     BASE_INFO_LOG([self class],_cmd,info)
#define BASE_INFO_FUN(info)               BASE_INFO_LOG([self class],_cmd,info)
#else
#define BASE_LOG_FUN(self,_cmd)
#define BASE_ERROR_FUN(self,_cmd,error)
#define BASE_INFO_FUN(self,_cmd,info)
#endif

// 设备类型判断
#define IsiPad             (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IsiPhone           (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IsRetain           ([[UIScreen mainScreen] scale] >= 2.0)
#define ScreenWidth        ([[UIScreen mainScreen] bounds].size.width)
#define ScreenHeight       ([[UIScreen mainScreen] bounds].size.height)
#define ScreenMaxLength    (MAX(ScreenWidth, ScreenHeight))
#define ScreenMinLength    (MIN(ScreenWidth, ScreenHeight))

#define IsiPhone4          (IsiPhone && ScreenMaxLength < 568.0)
#define IsiPhone5          (IsiPhone && ScreenMaxLength == 568.0)
#define IsiPhone6          (IsiPhone && ScreenMaxLength == 667.0)
#define IsiPhone6P         (IsiPhone && ScreenMaxLength == 736.0)







