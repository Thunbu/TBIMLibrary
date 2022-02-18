//
//  SSocketHeartbeat.h
//  NBIMDemo
//
//  心跳管理器
//
//  Created by changxuanren on 2019/4/24.
//  Copyright © 2019年 常宣任. All rights reserved.
//
#import "SIMComm.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SSocketHeartbeat : NSObject

+ (instancetype)sharedInstance;

- (void)start;

- (void)stop;

- (void)sendSocketHeart:(SIMSucc)success fail:(SIMFail)fail;
@end

NS_ASSUME_NONNULL_END
