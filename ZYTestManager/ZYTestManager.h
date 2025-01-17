//
//  ZYTestManager.h
//  ZYSuspensionView
//
//  Created by ripper on 2016/12/9.
//  Copyright © 2016年 ripper. All rights reserved.
//

#import <Foundation/Foundation.h>
@class UIViewController;

extern NSString *const kTestTitleKey;
extern NSString *const kTestAutoCloseKey;
extern NSString *const kTestActionKey;

@interface ZYTestManager : NSObject

/** 通过 @selector(setupTestItemPermanentArray:) 设置的长期存在的测试条目 */
@property (nonatomic, strong, readonly) NSArray <NSDictionary *>*testItemPermanentArray;
/** 通过 @selector(addTestItemWithTitle:action:) 添加的所有测试条目 */
@property (nonatomic, strong, readonly) NSMutableDictionary *testItemDic;
/** 当前显示测试条目的控制器 */
@property (nonatomic, weak, readonly) UIViewController *testTableViewController;


/**
 单例对象

 @return 单例对象
 */
+ (instancetype)shareInstance;


/**
 显示测试按钮 release模式自动不显示
 */
+ (void)showSuspensionView;


/**
 设置常驻的测试条目（如果长期需要使用，可以用该方法统一设置）

 @param array 所有常驻的测试条目
 */
+ (void)setupTestItemPermanentArray:(NSArray <NSDictionary *>*)array;


/**
 添加测试条目

 @param title 标题
 @param autoClose 点击后是否自动关闭测试列表
 @param action 行为
 */
+ (void)addTestItemWithTitle:(NSString *)title autoClose:(BOOL)autoClose action:(void(^)())action;

@end
