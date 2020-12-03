//
//	NKConst.h
//	
//	▄▄︻┻━━━┳━═━━   BUG~~
//	
//  Created by Chong on 2020/11/20.
//  
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NKConst : NSObject

typedef NS_ENUM(NSInteger, NKRCFetchStatus) {
    // 配置从未拉取成功过
    NKRCFetchStatusNoFetchYet,
    // 配置拉取成功
    NKRCFetchStatusSuccess,
    // 配置拉取失败
    NKRCFetchStatusFailure,
    // 配置拉取被限制
    NKRCFetchStatusThrottled
};

typedef NS_ENUM(NSInteger, NKRCFetchAndActivateStatus) {
    // 远程获取成功，并且获取的数据已激活。
    NKRCFetchAndActivateStatusFetchedFromRemote,
    // 从已拉取成功但尚未过期的配置数据成功“获取并激活”
    NKRCFetchAndActivateStatusUsingPreFetchedData,
    // 获取并激活失败
    NKRCFetchAndActivateStatusError
};

// Facebook登录成功的通知
extern NSString *const NKFacebookLoginNotification;
// Facebook退出登录的通知
extern NSString *const NKFacebookLogoutNotification;//
// Facebook 用户ID
extern NSString *const NKFacebookUserIDNotificationParameterKey;

@end

NS_ASSUME_NONNULL_END
