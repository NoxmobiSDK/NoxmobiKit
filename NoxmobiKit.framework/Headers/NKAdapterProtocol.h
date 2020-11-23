//
//	NKAdapterProtocol.h
//	
//	▄▄︻┻━━━┳━═━━   BUG~~
//	
//  Created by Chong on 2020/11/19.
//  
//


#import <Foundation/Foundation.h>
#import <NoxmobiKit/NKConst.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NKConnectorProtocol;

@protocol NKAdapterProtocol <NSObject>
@required

/// 初始化Adapter
- (instancetype)initWithConnector:(_Nullable id<NKConnectorProtocol>)connector;

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

@end

#pragma mark - Firebase/RemoteConfig
@protocol NKRemoteConfigAdapterProtocol <NKAdapterProtocol>
/**
 使用RC前必须先配置好Firebase(FIRApp)，是控制台输出的提示
 */

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

NS_ASSUME_NONNULL_END
