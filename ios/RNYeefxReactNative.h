#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif

@interface RNYeefxReactNative : NSObject <RCTBridgeModule>

// 初始化
- (void)init:(NSDictionary *)config;

// 页面采集
- (void)trackPage:(NSString *)pageUrl pageTitle:(NSString *)pageTitle;

// 事件采集
- (void)trackEvent:(NSString *)eventType eventCate:(NSString *)eventCate eventName:(NSString *)eventName properties:(NSDictionary *)properties;

// 政务采集
- (void)trackGov:(NSString *)eventCate eventName:(NSString *)eventName eventStep:(NSString *)eventStep properties:(NSDictionary *)properties;

// 用户采集
- (void)trackUserSet:(NSDictionary *)properties;

// 稿件采集
- (void)trackContent:(NSString *)contentUrl contentTitle:(NSString *)contentTitle contentNodeId:(NSString *)contentNodeId contentId:(NSString *)contentId contentEditor:(NSString *)contentEditor contentPubTime:(NSString *)contentPubTime;

// 获取用户匿名 ID
- (void)getUserCookie:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject;

// 停止采集
- (void)setUserStopTrack;

// 重新开始采集
- (void)setUserStartTrack;

@end