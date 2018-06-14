//
//  UtilsMacros.h
//  iOSPro
//
//  Created by bean on 2018/6/14.
//  Copyright © 2018年 bean. All rights reserved.
//

/**
 UtilsMacros定义的是一些工具宏，比如获取屏幕宽高，系统版本，数据类型验证等；
 */
#ifndef UtilsMacros_h
#define UtilsMacros_h

/*获取系统对象*/
/**
 获取应用对象
 */
#define kApplication [UIApplication sharedApplication]
/**
 获取Window
 */
#define kAppWindow [UIApplication sharedApplication].delegate.window
/**
 获取Appdelegate对象
 */
#define kAppDelegate [AppDelegate shareAppDelegate]
/**
 获取根视图
 */
#define kRootViewController [UIApplication sharedApplication].delegate.window.rootViewController
/**
 获取UserDefault
 */
#define kUserDefaults [NSUserDefaults standardUserDefaults]
/**
 获取通知中心
 */
#define kNotificationCenter [NSNotificationCenter defaultCenter]

/*获取屏幕宽高*/
/**
 获取屏幕宽
 */
#define KScreenWidth [[UIScreen mainScreen]bounds].size.width
/**
 获取屏幕高
 */
#define KScreenHeight [[UIScreen mainScreen]bounds].size.height
/**
 获取屏幕Frame
 */
#define kScreen_Bounds [UIScreen mainScreen].bounds
/**
 获取Iphone6宽度比例
 */
#define Iphone6ScaleWidth KScreenWidth/375.0
/**
 获取Iphone6高度比例
 */
#define Iphone6ScaleHeight KScreenHeight/667.0
/**
 根据ip6的屏幕来拉伸
 */
#define kRealValue(with)((with)*(KScreenWidth/375.0f))

//强弱引用
/**
 弱引用
 */
#define kWeakSelf(type)__weak typeof(type)weak##type = type;
/**
 强引用
 */
#define kStrongSelf(type)__strong typeof(type)type = weak##type;

/**
 View圆角和加边框
*/
#define ViewBorderRadius(View,Radius,Width,Color)\ \ [View.layer setCornerRadius:(Radius)];\ [View.layer setMasksToBounds:YES];\ [View.layer setBorderWidth:(Width)];\ [View.layer setBorderColor:[Color CGColor]]

/**
 View圆角
*/
#define ViewRadius(View,Radius)\ \ [View.layer setCornerRadius:(Radius)];\ [View.layer setMasksToBounds:YES]

//property属性快速声明
/**
 声明字符串
 */
#define PropertyString(s)@property(nonatomic,copy)NSString * s
/**
 声明NSinteger
 */
#define PropertyNSInteger(s)@property(nonatomic,assign)NSIntegers
/**
 声明floats
 */
#define PropertyFloat(s)@property(nonatomic,assign)floats
/**
 声明long long
 */
#define PropertyLongLong(s)@property(nonatomic,assign)long long s
/**
 声明NSDictionary
 */
#define PropertyNSDictionary(s)@property(nonatomic,strong)NSDictionary * s
/**
 声明NSArray
 */
#define PropertyNSArray(s)@property(nonatomic,strong)NSArray * s
/**
 声明NSMutableArray
 */
#define PropertyNSMutableArray(s)@property(nonatomic,strong)NSMutableArray * s

/**
 IOS版本判断
 */
#define IOSAVAILABLEVERSION(version)([[UIDevice currentDevice]availableVersion:version]< 0)

/**
 当前系统版本
 */
#define CurrentSystemVersion[[UIDevice currentDevice].systemVersion doubleValue]

/**
 当前语言
 */
#define CurrentLanguage([NSLocale preferredLanguages]objectAtIndex:0])

//-------------------打印日志-------------------------
/**
 DEBUG模式下打印日志,当前行
 */
#ifdef DEBUG
#define DLog(fmt,...)NSLog((@"%s[Line %d]" fmt),__PRETTY_FUNCTION__,__LINE__,##__VA_ARGS__);
#else
#define DLog(...)
#endif

/**
 拼接字符串
 */
#define NSStringFormat(format,...)[NSString stringWithFormat:format,##__VA_ARGS__]

/*定义UIImage对象*/
/**
 UIImage读取文件夹
 */
#define ImageWithFile(_pointer)[UIImage imageWithContentsOfFile:([[NSBundle mainBundle]pathForResource:[NSString stringWithFormat:@"%@@%dx",_pointer,(int)[UIScreen mainScreen].nativeScale]ofType:@"png"])]
/**
 UIImage读取图片名
 */
#define IMAGE_NAMED(name)[UIImage imageNamed:name]

//数据验证
/**
 验证字符串是否合法
 */
#define StrValid(f)(f!=nil &&[f isKindOfClass:[NSString class]]&& ![f isEqualToString:@""])
/**
 验证字符串是否为空，不为空返回本身，为空返回空格
 */
#define SafeStr(f)(StrValid(f)?f:@"")
/**
 验证字符串是否包含另一个字符串
 */
#define HasString(str,eky)([str rangeOfString:key].location!=NSNotFound)
#define ValidStr(f)StrValid(f)
/**
 验证字典是否合法
 */
#define ValidDict(f)(f!=nil &&[f isKindOfClass:[NSDictionary class]])
/**
 验证数组是否合法
 */
#define ValidArray(f)(f!=nil &&[f isKindOfClass:[NSArray class]]&&[f count]>0)
/**
 验证数字是否合法
 */
#define ValidNum(f)(f!=nil &&[f isKindOfClass:[NSNumber class]])
/**
 验证类是否合法
 */
#define ValidClass(f,cls)(f!=nil &&[f isKindOfClass:[cls class]])
/**
 验证Data是否合法
 */
#define ValidData(f)(f!=nil &&[f isKindOfClass:[NSData class]])

//获取一段时间间隔
#define kStartTime CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define kEndTimeNSLog(@"Time: %f",CFAbsoluteTimeGetCurrent()- start)

/**
 打印当前方法名
*/
#define ITTDPRINTMETHODNAME()ITTDPRINT(@"%s",__PRETTY_FUNCTION__)

//GCD
#define kDISPATCH_ASYNC_BLOCK(block)dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT,0),block)
#define kDISPATCH_MAIN_BLOCK(block)dispatch_async(dispatch_get_main_queue(),block)

//GCD -一次性执行
#define kDISPATCH_ONCE_BLOCK(onceBlock)static dispatch_once_t onceToken;dispatch_once(&onceToken,onceBlock);

//单例化一个类
#define SINGLETON_FOR_HEADER(className)\ \ +(className *)shared##className;
#define SINGLETON_FOR_CLASS(className)\ \ +(className *)shared##className { \ static className *shared##className = nil;\ static dispatch_once_t onceToken;\ dispatch_once(&onceToken,^{ \ shared##className =[[self alloc]init];\ });\ return shared##className;\ }









#endif /* UtilsMacros_h */
