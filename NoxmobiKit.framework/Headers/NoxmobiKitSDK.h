//
//	NoxmobiKitSDK.h
//	
//	▄▄︻┻━━━┳━═━━   BUG~~
//	
//  Created by Chong on 2020/11/23.
//  
//

#import <UIKit/UIKit.h>
#import <NoxmobiKit/NKConst.h>

NS_ASSUME_NONNULL_BEGIN

@interface NoxmobiKitSDK : NSObject

+ (instancetype)shared;

@end


#pragma mark - Firebase/Analytics
@interface NoxmobiKitSDK (FirebaseAnalytics)

/// 初始化配置
+ (void)firebaseInit;

/**
 Firebase打点
 key ：1 to 40 alphanumeric characters
 value ：up to 100 characters long
*/
+ (void)firebaseLogEventName:(NSString *)name parameters:(nullable NSDictionary<NSString *, id> *)parameters;

@end


#pragma mark - Firebase/RemoteConfig
@interface NoxmobiKitSDK (RemoteConfig)

/// 设置RC最小刷新间隔。默认为0，单位：秒(s)
+ (void)setupRemoteConfigMinimumFetchInterval:(NSTimeInterval)interval;
/// 使用PlistFile设置默认配置，例如：文件名为NoxDefault.plist，则[NoxmobiKitSDK setRCDefaultPlistFileName:@"NoxDefault"].
+ (void)setRCDefaultPlistFileName:(NSString *)plistName;
/// 用一组键值对设置默认配置；key须为NSString类型，value须为NSString或NSNumber类型
+ (void)setRCDefault:(nullable NSDictionary<NSString *, NSObject *> *)defaultDict;
/// 拉取远程配置，异步操作
+ (void)fetchRemoteConfig:(void(^_Nullable)(NKRCFetchStatus status, NSError *_Nullable error))handler;
/// 激活通过fetchRemoteConfig:方法拉取的配置，使之可用
+ (void)activateRemoteConfig:(void (^_Nullable)(BOOL changed, NSError *_Nullable error))handler;
/// 拉取并激活，等价于先调用 fetchRemoteConfig: 再调用 activateRemoteConfig:
+ (void)fetchAndActivateRemoteConfig:(void (^_Nullable)(NKRCFetchAndActivateStatus status, NSError *_Nullable error))handler;
/// 取字符串类型的值
+ (NSString *)rcStringValueForKey:(NSString *)key;
/// 取数字类型的值
+ (NSNumber *)rcNumberValueForKey:(NSString *)key;

@end

@protocol NKFacebookLoginProtocol;
#pragma mark - FacebookLogin & FacebookAnalytics
@interface NoxmobiKitSDK (FacebookLoginAnalytics)

/// 获取FBSDKLoginButton对象；可以放置在页面上需要的位置；登录动作由FBSDKLoginButton完成；
+ (UIButton *)fetchFBLoginButton;

/// 发起Facebook登录动作，仅限于自定义登录按钮
+ (void)fbLogin:(UIViewController *)vc;

/// 退出登录
+ (void)fbLogOut;

/// 查询Facebook是否已登录
+ (BOOL)fbIsLogin;

/// 查询当前登录的Facebook用户ID
+ (NSString *)fetchFBUserID;

/// 监听登录和登出结果
+ (void)setLoginDelegate:(id<NKFacebookLoginProtocol>)delegate;

@end

#pragma mark - Adjust
@interface NoxmobiKitSDK (Adjust)

/// 记录事件
+ (void)adjustLogEventForToken:(NSString *)token;

@end

NS_ASSUME_NONNULL_END
