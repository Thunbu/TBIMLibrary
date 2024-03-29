//
//  SIMChatManager.h
//  NBIMDemo
//
//  on 2019/6/2.
//  Copyright © 2019 闪布科技. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SIMComm.h"
#import "SIMComm+Message.h"
#import "TBOSSManager.h"
#import <UIKit/UIKit.h>

@class SIMMessage;

NS_ASSUME_NONNULL_BEGIN

@interface SIMMessageManager : NSObject

+ (instancetype)sharedInstance;

/**
 *  发送消息
 *
 *  @param msg  消息体
 *  @param succ 发送成功时回调
 *  @param fail 发送失败时回调
 *
 *  @return 0 发送成功
 */
/*
 发送视频 应产品需求 增加进度 所以增加进度参数
 */
- (int)sendMessage:(SIMMessage*)msg uprogress:(void(^)(OSSPutObjectRequest *putReq, CGFloat current, CGFloat total))progress succ:(SIMSuccData)succ fail:(SIMFail)fail;



/**
 消息已读上报

 *  @param msg 已读消息体
 *  @param succ 发送成功时回调
 *  @param fail 发送失败时回调
 *
 *  @return 0 发送成功
 */
- (int)setReadMessage:(SIMMessage *)msg succ:(SIMSuccData)succ fail:(SIMFail)fail;


/// 主动获取消息已读通知
/// @param msg 请求消息体
/// @param succ 发送成功时回调
/// @param fail 发送失败时回调
- (int)getHadReadMessage:(SIMMessage *)msg succ:(SIMSuccData)succ fail:(SIMFail)fail;


/**
 消息撤回

 *  @param msg 撤回消息体
 *  @param succ 发送成功时回调
 *  @param fail 发送失败时回调
 *
 *  @return 0 发送成功
 */
- (int)revokeMessage:(SIMMessage *)msg succ:(SIMSuccData)succ fail:(SIMFail)fail;


/**
 消息删除
 
 *  @param msg  删除消息体
 *  @param succ 发送成功时回调
 *  @param fail 发送失败时回调
 *
 *  @return 0 发送成功
 */
- (int)deleteMessage:(SIMMessage *)msg succ:(SIMSuccData)succ fail:(SIMFail)fail;

/**
 消息状态处理 以后新增的关于消息状态的处理统一走此API 
 */
- (int)handleMsgStatus:(SIMMessage *)msg succ:(SIMSuccData)succ fail:(SIMFail)fail;

/**
 拉取消息列表

 @param req 参数请求体
 */
- (void)pullOfflineMsgList:(SIMOfflineMsgReq *)req succ:(SIMOfflineMsgReqSucc)succ fail:(SIMFail)fail;

/**
拉取会话消息（包括指令）
 不推荐使用此方法，请用pullAllSerialMsgList:succ:fail:

@param req 参数请求体
*/
- (void)pullAllMsgList:(SIMOfflineAllMsgReq *)req succ:(SIMOfflineAllMsgReqSucc)succ fail:(SIMFail)fail;

/**
拉取会话消息（不包括指令）
 推荐使用此方法

@param req 参数请求体
*/
- (void)pullAllSerialMsgList:(SIMOfflineAllSerialMsgReq *)req succ:(SIMOfflineMsgReqSucc)succ fail:(SIMFail)fail;

/**
拉取敏感指令消息（消息状态）如删除、撤回等，用户感知明显

@param req 参数请求体
*/
- (void)pullAllCDMsgList:(SIMOfflineCDMsgReq *)req succ:(SIMSuccData)succ fail:(SIMFail)fail;

/**
拉取非敏感指令消息（消息状态）如标记、取消标记等，用户感知不明显

@param req 参数请求体
*/
- (void)pullAllMsgStatusList:(SIMOfflineAllMsgStatusReq *)req succ:(SIMOfflineMsgStatusReqSucc)succ fail:(SIMFail)fail;

/**
 根据消息Id查询消息
 
 @param ids 消息Id列表
 @param sessionType 单聊 0 /群聊 1
 */
- (void)pullMsgListWithMsgIds:(NSArray *)ids sessionType:(SIMSessionType)sessionType dmSource:(NSString *)dm extend:(NSDictionary *)dic succ:(SIMOfflineMsgReqSucc)succ fail:(SIMFail)fail;

/**
 请求服务端下发离线消息

 @param req 离线消息请求体
 @param succ 成功回调
 @param fail 失败回调
 */
- (void)applyRecentMessages:(SIMRecentMsgRequest*)req succ:(SIMSuccData)succ fail:(SIMFail)fail;

/**
 根据消息根Id查询回复盖楼消息
 
 @param messageId 根消息Id
 @param sessionType 单聊 0 /群聊 1
 */
- (void)pullMsgReplyListWithRootMsgId:(NSString *)messageId sessionType:(SIMSessionType)sessionType succ:(SIMOfflineMsgReqSucc)succ fail:(SIMFail)fail;

/**
 拉取标记列表
 
 @param request 请求参数对象
 @param succ 成功回调
 @param fail 失败回调
 */
- (void)pullMsgSignList:(SIMSignRequest *)request succ:(SIMOfflineMsgReqSucc)succ fail:(SIMFail)fail;

/**
 标记消息
 
 @param msgId 消息ID
 @param groupId 群组ID
 @param succ 成功回调
 @param fail 失败回调
 */
- (void)signOrUnsignMessage:(SIMSignRequest*)request succ:(SIMSucc)succ fail:(SIMFail)fail;

/**
 根据消息ID拉取消息详情
 
 @param messageId 根消息Id
 @param sessionType 单聊 0 /群聊 1
 */
- (void)pullMessageWithMessageId:(NSString *)messageId sessionType:(SIMSessionType)sessionType succ:(SIMMsgReqSucc)succ fail:(SIMFail)fail;

/// 获取消息的已读未读列表
/// @param msgId 消息ID
/// @param succ 成功回调
/// @param fail 失败回调
- (void)getReadStatusListForMsg:(NSString *)msgId succ:(SIMSuccData)succ fail:(SIMFail)fail;



/// 拉取会话历史消息
/// @param request 请求消息体
/// @param succ 成功回调
/// @param fail 失败回调
- (void)pullMessageOfSessionWithRequest:(SIMSearchMsgRequest *)request succ:(SIMSearchMsgReqSucc)succ fail:(SIMFail)fail;


/// 查询最近一分钟音视频消息
- (void)pullCallMsgsOfMinute:(SIMOfflineMsgReqSucc)succ fail:(SIMFail)fail;

@end

NS_ASSUME_NONNULL_END
