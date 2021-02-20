//
//	NKAdapterProtocol.h
//	
//	▄▄︻┻━━━┳━═━━   BUG~~
//	
//  Created by Chong on 2020/11/19.
//  
//


#import <UIKit/UIKit.h>
#import <NoxmobiKit/NKConst.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NKConnectorProtocol;

@protocol NKAdapterProtocol <NSObject>
@required

/// 初始化Adapter
- (instancetype)initWithConnector:(_Nullable id<NKConnectorProtocol>)connector;

@optional
/// App启动
- (void)didFinishLaunchingWithNotification:(NSNotification *)notification;

@end


#pragma mark - Firebase/Analytics
@protocol NKFirebaseAnalyticsAdapterProtocol <NKAdapterProtocol>

/// 初始化配置
- (void)firebaseInit;

/**
 Firebase打点
 key ：1 to 40 alphanumeric characters
 value ：up to 100 characters long
*/
- (void)firebaseLogEventName:(NSString *)name parameters:(nullable NSDictionary<NSString *, id> *)parameters;

/**
 Firebase设置UserProperty
 name: Should contain 1 to 24 alphanumeric characters or underscores and must start with an alphabetic character.
 string: Values can be up to 36 characters long.
 */
- (void)firebaseSetupUserProperty:(NSString *)name string:(NSString *)string;

@end

#pragma mark - Firebase/RemoteConfig
@protocol NKRemoteConfigAdapterProtocol <NKAdapterProtocol>
/**
 使用RC前必须先配置好Firebase(FIRApp)，是控制台输出的提示
 */

/// 设置RC最小刷新间隔。默认为0，单位：秒(s)
- (void)setupRemoteConfigMinimumFetchInterval:(NSTimeInterval)interval;
/// 设置默认配置，使用PlistFile
- (void)setDefaultConfigPlistFileName:(NSString *)plistName;
/// 设置默认配置，用一组键值对；key须为NSString类型，value须为NSString或NSNumber类型
- (void)setDefaultConfig:(nullable NSDictionary<NSString *, NSObject *> *)defaultDict;
/// 拉取远程配置，异步操作
- (void)fetchRemoteConfig:(void(^_Nullable)(NKRCFetchStatus status, NSError *_Nullable error))handler;
/// 激活通过fetchRemoteConfig:方法拉取的配置，使之可用
- (void)activateRemoteConfig:(void (^_Nullable)(BOOL changed, NSError *_Nullable error))handler;
/// 拉取并激活，等价于先调用 fetchRemoteConfig: 再调用 activateRemoteConfig:
- (void)fetchAndActivateRemoteConfig:(void (^_Nullable)(NKRCFetchAndActivateStatus status, NSError *_Nullable error))handler;
/// 取字符串类型的值
- (NSString *)configStringValueForKey:(NSString *)key;
/// 取数字类型的值
- (NSNumber *)configNumberValueForKey:(NSString *)key;

@end

#pragma mark - FacebookLogin
@protocol NKFacebookLoginAdapterProtocol <NKAdapterProtocol>
@optional
/// 在AppDelegate中实现此方法，传入相应参数
- (void)app:(UIApplication *)app openURL:(NSURL *)url options:(nonnull NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;

/// 获取FBSDKLoginButton对象；可以放置在页面上需要的位置；登录动作由FBSDKLoginButton完成；
- (UIButton *)fetchFBLoginButton;

/// 发起Facebook登录动作，仅限于自定义登录按钮
- (void)fbLogin:(UIViewController *)vc;

/// 退出登录
- (void)fbLogOut;

/// 查询Facebook是否已登录
- (BOOL)fbIsLogin;

/// 查询当前登录的Facebook用户ID
- (NSString *)fetchFBUserID;

@end

@protocol NKFacebookLoginProtocol <NSObject>
@optional

/// Adapter回调通知给SDK
@property (nonatomic, weak) id<NKFacebookLoginProtocol> delegate;

/// 登录成功
- (void)facebookDidLogin;

/// 登录失败
- (void)facebookFailedToLogin:(NSError *)error;

/// 退出登录成功
- (void)facebookDidLogout;

@end


#pragma mark - Adjust
@protocol NKAdjustAdapterProtocol <NKAdapterProtocol>

/// 初始化Adjust SDK。AppToken为AM给定的值，sandboxEnable表示是够启用沙盒环境，默认为NO不启用。
- (void)adjustInitWithAppToken:(NSString *)appToken sandboxEnable:(BOOL)enable;

/// 记录事件
- (void)adjustLogEventForToken:(NSString *)token;

@end

NS_ASSUME_NONNULL_END
