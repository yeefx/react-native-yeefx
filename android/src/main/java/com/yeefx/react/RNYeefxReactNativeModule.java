
package com.yeefx.react;

import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.ReadableNativeMap;

import android.util.Log;
import android.app.Activity;
import android.app.Application;
import org.json.JSONException;
import org.json.JSONObject;


import com.yeefx.react.utils.RNUtils;
import com.yeefxdata.analytics.android.sdk.YeefxDataAPI;
import com.yeefxdata.analytics.android.sdk.YeefxDataPrivate;



public class RNYeefxReactNativeModule extends ReactContextBaseJavaModule {

    private ReactApplicationContext reactContext;

    public RNYeefxReactNativeModule(ReactApplicationContext reactContext) {
        super(reactContext);
        this.reactContext = reactContext;
    }

    @Override
    public String getName() {
        return "RNYeefxReactNativeModule";
    }

    //初始化
    @ReactMethod
    public void init(ReadableMap config) {
      // 在方法中获取当前 Activity
      Activity activity = getCurrentActivity();
      if (activity == null) {
          // 处理 Activity 为空的情况
          return;
      }
        try {
             // 将 ReadableMap 转换为 JSONObject
             JSONObject configJson = new JSONObject();
             java.util.Map<String, Object> map = config.toHashMap();
             for (String key : map.keySet()) {
                 Object value = map.get(key);
                 configJson.put(key, value);
             }

           // JSONObject configJson = RNUtils.convertToJSONObject(config);

            // 构建初始化参数
            JSONObject initParam = new JSONObject();
            String appUrl = configJson.has("appurl") ? configJson.getString("appurl") : "";
            String website = configJson.has("website") ? configJson.getString("website") : "";
            String version = configJson.has("version") ? configJson.getString("version") : "";
            String channel = configJson.has("channel") ? configJson.getString("channel") : "";
            boolean logFlag = configJson.has("logflag") ? configJson.getBoolean("logflag") : false;

            initParam.put("appurl", appUrl);
            initParam.put("website", website);
            initParam.put("version", version);
            initParam.put("channel", channel);
            initParam.put("logflag", logFlag);

            // 初始化操作
            Application application = activity.getApplication();
            YeefxDataAPI.init(application, initParam);
            Log.i("yeefx", "易分析初始化成功");
        } catch (JSONException e) {
            Log.i("yeefx", "JSON 处理异常: " + e.getMessage(), e);
        } catch (Exception e) {
            Log.i("yeefx", "初始化过程中出现未知异常: " + e.getMessage(), e);
        }
    }


    //页面采集
    @ReactMethod
    public void trackPage(String pageUrl, String pageTitle) {
      try {
        Log.i("yeefx","易分析页面采集");
        Log.i("yeefx",pageUrl);
        Log.i("yeefx",pageTitle);
        YeefxDataAPI.getInstance().trackPageTitle(pageUrl, pageTitle);
      } catch (Exception e) {
        e.printStackTrace();

      }
    }

    //事件采集
    @ReactMethod
    public void trackEvent(String eventType, String eventCate, String eventName, ReadableMap properties) {
      try {
        YeefxDataAPI.getInstance().trackEvent(eventType,eventCate,eventName,RNUtils.convertToJSONObject(properties));
      } catch (Exception e) {
        e.printStackTrace();
      }
    }
    

     //政务采集
     @ReactMethod
     public void trackGov(String eventCate, String eventName, String eventStep, ReadableMap properties) {
       try {
         // 将 ReadableMap 转换为 JSONObject
        //  JSONObject propertiess = new JSONObject();
        //  java.util.Map<String, Object> map = properties.toHashMap();
        //  for (String key : map.keySet()) {
        //    Object value = map.get(key);

        //    propertiess.put(key, value);
        //  }
         YeefxDataAPI.getInstance().trackEvent("govevent",eventCate,eventName, eventStep, RNUtils.convertToJSONObject(properties));
       } catch (Exception e) {
         e.printStackTrace();
       }
     }

    //用户采集
    @ReactMethod
    public void trackUserSet(ReadableMap properties) {
      try {
        // // 将 ReadableMap 转换为 JSONObject
        // JSONObject propertiess = new JSONObject();
        // java.util.Map<String, Object> map = properties.toHashMap();
        // for (String key : map.keySet()) {
        //   Object value = map.get(key);
        //   propertiess.put(key, value);
        // }

        YeefxDataAPI.getInstance().trackUserSet(RNUtils.convertToJSONObject(properties));
      } catch (Exception e) {
        e.printStackTrace();
      }
    }

    //稿件采集
    @ReactMethod
    public void trackContent(String contentUrl, String contentTitle, String contentNodeId, String contentId, String contentEditor, String contentPubTime) {
      try {
        YeefxDataAPI.getInstance().trackContent(contentUrl, contentTitle, contentNodeId, contentId, contentEditor, contentPubTime);
      } catch (Exception e) {
        e.printStackTrace();
      }
    }
    

    /**
     * 导出 getUserCookie 方法给 RN 使用.
     * <p>
     * Promise 方式 getUserCookie 获取匿名 ID.
     * <p>
     * RN 中使用示例：
     * async  getUserCookie() {
     * var cookie = await RNYeefxReactNativeModule.getUserCookie()
     * };
     */
    @ReactMethod
    public void getUserCookie(Promise promise) {
        if (promise == null) {
            return;
        }
        try {
            promise.resolve(YeefxDataAPI.getInstance().getUserCookie());
        } catch (Exception e) {
            e.printStackTrace();
            promise.reject("getUserCookie failed", e);
        }
    }

    //停止采集
    @ReactMethod
    public void setUserStopTrack() {
      try {
        YeefxDataAPI.getInstance().setUserStopTrack();
      } catch (Exception e) {
        e.printStackTrace();
      }
    }

    //重新开始采集
    @ReactMethod
    public void setUserStartTrack() {
      try {
        YeefxDataAPI.getInstance().setUserStartTrack();
      } catch (Exception e) {
        e.printStackTrace();
      }
    }
}