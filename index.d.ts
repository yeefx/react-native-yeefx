import { NativeModules } from 'react-native';

// 定义 RNYeefxReactNativeModule 类型
type RNYeefxReactNativeModuleType = {
    init: (config: any) => void;
    trackPage: (pageUrl: string, pageTitle: string) => void;
    trackContent: (contentUrl: string, contentTitle: string, contentNodeId: string, contentId: string, contentEditor: string, contentPubTime: string) => void;
    trackEvent: (eventType: string, eventCate: string, eventName: string, properties: any) => void;
    trackGov: (eventCate: string, eventName: string, eventStep: string, properties: any) => void;
    trackUserSet: (properties: any) => void;
    setUserStopTrack: () => void;
    setUserStartTrack: () => void;
    getUserCookie: () => Promise<string>;
};

const { RNYeefxReactNativeModule } = NativeModules as { RNYeefxReactNativeModule: RNYeefxReactNativeModuleType | undefined };

// sdk初始化
function init(config: any): void {
    console.log("易分析初始化");
    if (RNYeefxReactNativeModule && RNYeefxReactNativeModule.init) {
        RNYeefxReactNativeModule.init(config);
    } else {
        console.error('RNYeefxSdkModule 或 init 方法未找到');
    }
}

// 页面采集
function trackPage(pageUrl: string, pageTitle: string): void {
    if (RNYeefxReactNativeModule && RNYeefxReactNativeModule.trackPage) {
        RNYeefxReactNativeModule.trackPage(pageUrl, pageTitle);
    } else {
        console.error('RNYeefxReactNativeModule 或 trackPage 方法未找到');
    }
}

// 稿件采集
function trackContent(contentUrl: string, contentTitle: string, contentNodeId: string, contentId: string, contentEditor: string, contentPubTime: string): void {
    if (RNYeefxReactNativeModule && RNYeefxReactNativeModule.trackContent) {
        RNYeefxReactNativeModule.trackContent(contentUrl, contentTitle, contentNodeId, contentId, contentEditor, contentPubTime);
    } else {
        console.error('RNYeefxReactNativeModule 或 trackContent 方法未找到');
    }
}

// 事件采集
function trackEvent(eventType: string, eventCate: string, eventName: string, properties: any): void {
    if (RNYeefxReactNativeModule && RNYeefxReactNativeModule.trackEvent) {
        RNYeefxReactNativeModule.trackEvent(eventType, eventCate, eventName, properties);
    } else {
        console.error('RNYeefxReactNativeModule 或 trackEvent 方法未找到');
    }
}

// 政务采集
function trackGov(eventCate: string, eventName: string, eventStep: string, properties: any): void {
    if (RNYeefxReactNativeModule && RNYeefxReactNativeModule.trackGov) {
        RNYeefxReactNativeModule.trackGov(eventCate, eventName, eventStep, properties);
    } else {
        console.error('RNYeefxReactNativeModule 或 trackGov 方法未找到');
    }
}

// 用户采集
function trackUserSet(properties: any): void {
    if (RNYeefxReactNativeModule && RNYeefxReactNativeModule.trackUserSet) {
        RNYeefxReactNativeModule.trackUserSet(properties);
    } else {
        console.error('RNYeefxReactNativeModule 或 trackUserSet 方法未找到');
    }
}

// 停止采集
function setUserStopTrack(): void {
    if (RNYeefxReactNativeModule && RNYeefxReactNativeModule.setUserStopTrack) {
        RNYeefxReactNativeModule.setUserStopTrack();
    } else {
        console.error('RNYeefxReactNativeModule 或 setUserStopTrack 方法未找到');
    }
}

// 重新开始采集
function setUserStartTrack(): void {
    if (RNYeefxReactNativeModule && RNYeefxReactNativeModule.setUserStartTrack) {
        RNYeefxReactNativeModule.setUserStartTrack();
    } else {
        console.error('RNYeefxReactNativeModule 或 setUserStartTrack 方法未找到');
    }
}

/**
 * Promise 方式 getUserCookie 获取匿名 ID.
 */
async function getUserCookie(): Promise<string | undefined> {
    if (RNYeefxReactNativeModule && RNYeefxReactNativeModule.getUserCookie) {
        try {
            return await RNYeefxReactNativeModule.getUserCookie();
        } catch (e) {
            console.log(e);
        }
    }
    return undefined;
}

export default {
    init,
    trackPage,
    trackContent,
    trackEvent,
    trackGov,
    trackUserSet,
    setUserStopTrack,
    setUserStartTrack,
    getUserCookie
};    