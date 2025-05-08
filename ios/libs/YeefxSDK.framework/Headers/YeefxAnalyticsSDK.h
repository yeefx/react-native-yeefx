//
//  YeefxAnalyticsSDK.h
//  YeefxSDK
//
//  Created by 普艾斯 on 2024/03.
//  Copyright © 2024 YeefxData. All rights reserved.
//  uniapp

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YeefxAnalyticsSDK : NSObject

/// 当本地存储的事件达到这个数量时，上传数据（默认为 100）
@property (nonatomic) NSUInteger flushBulkSize;
/// 两次数据发送的时间间隔，单位秒
@property (nonatomic) NSUInteger flushInterval;

//是否打印日志
@property (nonatomic, copy) NSString *logflag;
//是否自动采集点击
@property (nonatomic, copy) NSString *autoclick;

//卡顿时间阀值
@property (nonatomic, strong) NSString *anrtime;

//启动标记
@property (nonatomic, assign) Boolean appStartMark;

@property (nonatomic, copy, readonly) NSString *loginId;

@property (nonatomic, copy, nullable) NSString *anonymousId;

@property (nonatomic, copy, nullable) NSString *phoneId;

/// 页面进入时间，进入其他页面改变，在本页面发生的动作时间都用这个
@property (nonatomic, copy) NSNumber *enterPageTime;
/// 当前页面标题
@property (nonatomic, copy) NSString *currentPageTitle;
/// 当前页面url
@property (nonatomic, copy) NSString *currentPageUrl;

///
@property (nonatomic, copy) NSString *customPage;

//第一个viewcontroller加载完成时间
@property (nonatomic, strong) NSNumber *firstPageTime;
//是否是第一个页面
@property (nonatomic, assign) Boolean isFirsttPage;

//是否是第一个页面
@property (nonatomic, assign) Boolean isFirstUPage;


- (instancetype)init NS_UNAVAILABLE;

/**
@abstract
获取 SDK 实例

@return 返回单例
*/
+ (YeefxAnalyticsSDK *)sharedInstance;

/**
初始化 SDK

@param urlString 数据上传地址
 //设置需要自定义的cotroller的名称
 //页面自定义名称 pageName 传入需要自定义的页面controller名字，每个页面用 | 隔开，还可以用(*)定义多个页面
 //比如  News(*) 代表  News开头的所有页面 这个方法需要在启动时调用
*/
+ (void)startWithServerURL:(NSString *)urlString options:(NSDictionary<NSString *,id> *)options;


// 获取用户唯一识别码
- (NSString *)getUserCookie;

//判断是否是需要自定义标题的页面
- (BOOL)isCustomPage:(NSString *)pageName;

/**
 向服务器发送本地所有数据
 */
- (void)flush;


@end

#pragma mark - Track
@interface YeefxAnalyticsSDK (Track)

//停止采集
-(void)setStopTrack;

//重新开始采集
-(void)setStartTrack;

/**
@abstract
 用户登录接口
@param properties 用户属性
*/
-(void)trackUserSet:(NSDictionary<NSString *, id> *)properties;

/**
@abstract
调用 track 接口，触发事件

@discussion
properties 是一个 NSDictionary。
其中的 key 是 Property 的名称，必须是 NSString
value 则是 Property 的内容

@param trackType    日志大分类
@param subTrackType  日志小分类
@param properties 自定义事件属性
*/
- (void)track:(NSString *)trackType subTrackType:(NSString *)subTrackType properties:(nullable NSDictionary<NSString *, id> *)properties;


//首屏加载时间，内部类使用
- (void)trackFirstPage;


//页面，内部类使用
- (void)trackPage:(NSString *)pageType pageName:(NSString *)pageName pageTitle:(NSString *)pageTitle;

//手动采集页面（uniapp用）
- (void)trackUpage:(NSString *)pageUrl pageTitle:(NSString *)pageTitle;
/**
@abstract
对外提供的页面标题自定义
@param pageTitle   页面标题
*/
- (void)trackPageTitle:(NSString *)pageTitle;


/**
 @abstract
 对外提供的稿件采集
 @param contentUrl  稿件url
 @param contentNodeId  稿件栏目id
 @param contentId  稿件id
 @param contentTitle 稿件标题
 @param contentEditor 稿件编辑
 @param contentPubtime 稿件发布时间
 */
- (void)trackContent:(NSString *)contentUrl contentTitle:(NSString *)contentTitle  contentNodeId:(NSString *)contentNodeId contentId:(NSString *)contentId contentEditor:(NSString *)contentEditor contentPubtime:(NSString *)contentPubtime;

/**
@abstract
对外提供的事件采集接口
 
@param eventType   事件类型
@param eventCate   事件分类
@param eventName   事件名称
*/
- (void)trackEvent:(NSString *)eventType eventCate:(NSString *)eventCate eventName:(NSString *)eventName;


/**
@abstract
对外提供的事件采集接口

@discussion
properties 是一个 NSDictionary。
其中的 key 是 Property 的名称，必须是 NSString
value 则是 Property 的内容
 
@param eventType   事件类型
@param eventCate   事件分类
@param eventName   事件名称
@param sproperties 自定义事件属性
*/
- (void)trackEvent:(NSString *)eventType eventCate:(NSString *)eventCate eventName:(NSString *)eventName properties:(NSDictionary *)sproperties;

/**
@abstract
对外提供的政务采集接口

@discussion
properties 是一个 NSDictionary。
其中的 key 是 Property 的名称，必须是 NSString
value 则是 Property 的内容
 
@param eventType   事件类型 govevent
@param eventCate   事件分类
@param eventName   事件名称
@param eventStep   办事步骤
@param sproperties 自定义事件属性
*/
- (void)trackEvent:(NSString *)eventType eventCate:(NSString *)eventCate eventName:(NSString *)eventName eventStep:(NSString *)eventStep properties:(NSDictionary *)sproperties;


/**
让视图触发 $AppClick 事件

@param view 触发事件的视图
@param properties 自定义事件属性
*/
- (void)trackAppClickWithView:(UIView *)view properties:(nullable NSDictionary<NSString *, id> *)properties;

/**
支持 UITableView 触发 $AppClick 事件
@param tableView 触发事件的 UITableView 视图
@param indexPath 在 UITableView 中点击的位置
@param properties 自定义事件属性
*/
- (void)trackAppClickWithTableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath properties:(nullable NSDictionary<NSString *, id> *)properties;

/**
支持 UICollectionView 触发 $AppClick 事件
@param collectionView 触发事件的 UICollectionView 视图
@param indexPath 在 UICollectionView 中点击的位置
@param properties 自定义事件属性
*/
- (void)trackAppClickWithCollectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath properties:(nullable NSDictionary<NSString *, id> *)properties;

/**
 获取abtesturl
 */
- (NSString*)getAbTestUrl:(NSString *)apiUrl apiServer:(NSString *)apiServer userId:(NSString *)userId abtestId:(NSString *)abtestId cacheTime:(NSString *)cacheTime filterItem:(NSString *)filterItem;

//发送abtest请求
-(void)sendAbTestLog:(NSString *)jsonString;

@end

#pragma mark - ReactNative
@interface YeefxAnalyticsSDK (ReactNative)

- (void)enableTrackReactNativeEvent;

@end

NS_ASSUME_NONNULL_END
