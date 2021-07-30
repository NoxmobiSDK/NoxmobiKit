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
#import "NKAdapterProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface NoxmobiKitSDK : NSObject

+ (instancetype)shared;

@end


#pragma mark - Firebase/Analytics
@interface NoxmobiKitSDK (FirebaseAnalytics) 

/**
 初始化配置
 */
+ (void)firebaseInit;

/**
 Firebase打点
 key ：1 to 40 alphanumeric characters
 value ：up to 100 characters long
*/
+ (void)firebaseLogEventName:(NSString *)name parameters:(nullable NSDictionary<NSString *, id> *)parameters;

/**
 Firebase设置UserProperty
 name: Should contain 1 to 24 alphanumeric characters or underscores and must start with an alphabetic character.
 string: Values can be up to 36 characters long.
 */
+ (void)firebaseSetupUserProperty:(NSString *)name string:(NSString *)string;

/**
 @event 进入关卡
 @discussion 用户刚进入某个关卡时（注：复活不算重新进入关卡）
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param session_id 参数值(string类型)：标识本次闯关活动的uuid(通用唯一标识码Universally Unique Identifier)，下次还进入该关卡，session_id要变化
 */
+ (void)firTrackGameLevelEnter:(int)level_id session_id:(string)session_id;

/**
 @event 关口结算
 @discussion 闯关成功或失败时
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param session_id 参数值(string类型)：标识本次闯关活动的uuid，在本次闯关活动中的level_enter.session_id = level_complete.session_id
 @param result 参数值(int类型）：（示例：0 失败 1 成功）
 */
+ (void)firTrackGameLevelComplete:(int)level_id session_id:(string)session_id result:(int)result;
/**
 @event 复活机会
 @discussion 弹出复活提示页面时
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param session_id 参数值(string类型)：标识本次复活机会的uuid，和本次闯关活动中的level_enter.session_id相同
 */
+ (void)firTrackGameReviveOpportunity:(int)level_id session_id:(string)session_id;
/**
 @event 复活
 @discussion 复活确认后
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param session_id 参数值(string类型)：标识本次复活的uuid，和本次复活机会的uuid相等。
 */
+ (void)firTrackGameRevive:(int)level_id session_id:(string)session_id;
/**
 @event 激励按钮展示
 @discussion 用于标识激励视频机会，通常为激励按钮展示，无论广告是否已准备好；打点时机 1. 用户进入或者页面切换到有激励视频按钮展示的页面时。2. 用户点击激励视频按钮，并关闭广告或无广告提示弹窗后。
 @param ad_ready 参数值(int类型): 此时广告是否已缓存好（示例：0未缓存，1已缓存）
 @param scene 参数值(string类型): "scene_" + 触发激励的场景 （示例："scene_store"）
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param pl_id 参数值(string类型)：广告位placementID
 @param format 参数值（int类型）：广告位类型（3：激励视频；4：banner；5：插屏）
 */
+ (void)firTrackGameRewardBtnShow:(int)ad_ready scene:(string)scene level_id:(int)level_id pl_id:(string)pl_id format:(int)format;
/**
 @event 激励按钮点击
 @discussion 当激励按钮被点击时
 @param ad_ready 参数值(int类型): 此时广告是否已缓存好（示例：0未缓存，1已缓存）
 @param scene 参数值(string类型): "scene_" + 触发激励的场景 （示例："scene_store"）
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param pl_id 参数值(string类型)：广告位placementID
 @param format 参数值（int类型）：广告位类型（3：激励视频；4：banner；5：插屏）
 */
+ (void)firTrackGameRewardBtnClick:(int)ad_ready scene:(string)scene level_id:(int)level_id pl_id:(string)pl_id format:(int)format;
/**
 @event 激励广告展示
 @discussion 当激励广告展示成功时
 @param scene 参数值(string类型): "scene_" + 触发激励的场景 （示例："scene_store"）
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param pl_id 参数值(string类型)：广告位placementID
 @param format 参数值（int类型）：广告位类型（3：激励视频；4：banner；5：插屏）
 */
+ (void)firTrackGameRewardAdShow:(string)scene level_id:(int)level_id pl_id:(string)pl_id format:(int)format;
/**
 @event 激励广告完成
 @discussion 奖励成功发放后
 @param scene 参数值(string类型): "scene_" + 触发激励的场景 （示例："scene_store"）
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param pl_id 参数值(string类型)：广告位placementID
 @param format 参数值（int类型）：广告位类型（3：激励视频；4：banner；5：插屏）
 */
+ (void)firTrackGameRewardAdComplete:(string)scene level_id:(int)level_id pl_id:(string)pl_id format:(int)format;
/**
 @event 插屏/banner机会
 @discussion 插屏/banner需要展示时
 @param ad_ready 参数值(int类型): 此时广告是否已缓存好（示例：0未缓存，1已缓存）
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param pl_id 参数值(string类型)：广告位placementID
 @param format 参数值（int类型）：广告位类型（3：激励视频；4：banner；5：插屏）
 */
+ (void)firTrackGameIntOpportunity:(int)ad_ready level_id:(int)level_id pl_id:(string)pl_id format:(int)format;
/**
 @event 插屏/banner广告展示
 @discussion 插屏/banner广告展示成功
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param pl_id 参数值(string类型)：广告位placementID
 @param format 参数值（int类型）：广告位类型（3：激励视频；4：banner；5：插屏）
 */
+ (void)firTrackGameIntAdShow:(int)level_id pl_id:(string)pl_id format:(int)format;
/**
 @event 按钮点击
 @discussion 各类型按钮点击时。
 @discussion 按钮符号表中的每日签到按钮，取值rank不是按钮等级，而是第几日签到，即rank=1/2/3/4/5/6/7，且没有scene的概念.
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param name 参数值(string类型)：按钮名称(英文字母)
 @param rank 参数值(int类型)：按钮等级
 @param scene 参数值(string类型)：按钮所属国家
 @param coin_consume 参数值(int类型)：本次点击的货币消耗量；适用于消耗货币的按钮；传入-1代表不需要此参数；
 @param coin_produce_all 参数值(int类型)：当前关卡的货币总产出量；适用于消耗货币的按钮；传入-1代表不需要此参数；
 @param coin_consume_all 参数值(int类型)：当前关卡的货币总消耗量；适用于消耗货币的按钮；传入-1代表不需要此参数；
 */
+ (void)firTrackGameBtnClick:(int)level_id
                        name:(string)name
                        rank:(int)rank
                       scene:(string)scene
                coin_consume:(int)coin_consume
            coin_produce_all:(int)coin_produce_all
            coin_consume_all:(int)coin_consume_all;

/**
 @event 退出游戏
 @discussion 退出游戏时（仅记录当前关卡）
 @param level_id 参数值(int类型)：关卡名（示例：1）
 @param coin_produce_all 参数值(int类型)：当前关卡的货币总产出量
 @param coin_consume_all 参数值(int类型)：当前关卡的货币总消耗量
 */
+ (void)firTrackGameAppExit:(int)level_id coin_produce_all:(int)coin_produce_all coin_consume_all:(int)coin_consume_all;

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
