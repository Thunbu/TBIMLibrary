//
//  SIMTools.h
//  NBIMDemo
//
//  Created by changxuanren on 2019/5/7.
//  Copyright © 2019年 常宣任. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SIMTools : NSObject

/**
 生成32位UUID
 */
+ (NSString *)uuidString;

//json格式字符串转字典：
+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;


@end

NS_ASSUME_NONNULL_END
