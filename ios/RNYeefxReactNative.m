#import "RNYeefxReactNative.h"
#import <YeefxSDK/YeefxAnalyticsSDK.h> // 假设存在这样的 SDK 头文件

@implementation RNYeefxReactNative

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

RCT_EXPORT_MODULE()

// 初始化
RCT_EXPORT_METHOD(init:(NSDictionary *)config)
{
    NSString *appUrl = config[@"appurl"] ?: @"";
    NSString *website = config[@"website"] ?: @"";
    NSString *version = config[@"version"] ?: @"";
    NSString *channel = config[@"channel"] ?: @"";
    BOOL logFlag = [config[@"logflag"] boolValue];

    NSDictionary *initParam = @{
        @"website": website,
        @"version": version,
        @"channel": channel,
        @"logflag": @(logFlag)
    };
    [YeefxAnalyticsSDK startWithServerURL:appUrl options:initParam];
    NSLog(@"易分析初始化成功");
}

// 页面采集
RCT_EXPORT_METHOD(trackPage:(NSString *)pageUrl pageTitle:(NSString *)pageTitle)
{
    NSLog(@"易分析页面采集");
    NSLog(@"%@", pageUrl);
    NSLog(@"%@", pageTitle);
    [YeefxAnalyticsSDK trackUPage:pageUrl pageTitle:pageTitle];
}

// 事件采集
RCT_EXPORT_METHOD(trackEvent:(NSString *)eventType eventCate:(NSString *)eventCate eventName:(NSString *)eventName properties:(NSDictionary *)properties)
{
    [YeefxAnalyticsSDK trackEvent:eventType eventCate:eventCate eventName:eventName properties:properties];
}

// 政务采集
RCT_EXPORT_METHOD(trackGov:(NSString *)eventCate eventName:(NSString *)eventName eventStep:(NSString *)eventStep properties:(NSDictionary *)properties)
{
    [YeefxAnalyticsSDK trackEvent:@"govevent" eventCate:eventCate eventName:eventName eventStep:eventStep properties:properties];
}

// 用户采集
RCT_EXPORT_METHOD(trackUserSet:(NSDictionary *)properties)
{
    [YeefxAnalyticsSDK trackUserSet:properties];
}

// 稿件采集
RCT_EXPORT_METHOD(trackContent:(NSString *)contentUrl contentTitle:(NSString *)contentTitle contentNodeId:(NSString *)contentNodeId contentId:(NSString *)contentId contentEditor:(NSString *)contentEditor contentPubTime:(NSString *)contentPubTime)
{
    [YeefxAnalyticsSDK trackContent:contentUrl contentTitle:contentTitle contentNodeId:contentNodeId contentId:contentId contentEditor:contentEditor contentPubTime:contentPubTime];
}

// 获取用户匿名 ID
RCT_EXPORT_METHOD(getUserCookie:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject)
{
    NSString *cookie = [YeefxAnalyticsSDK getUserCookie];
    if (cookie) {
        resolve(cookie);
    } else {
        reject(@"getUserCookie failed", @"获取用户匿名 ID 失败", nil);
    }
}

// 停止采集
RCT_EXPORT_METHOD(setUserStopTrack)
{
    [YeefxAnalyticsSDK setUserStopTrack];
}

// 重新开始采集
RCT_EXPORT_METHOD(setUserStartTrack)
{
    [YeefxAnalyticsSDK setUserStartTrack];
}

@end
