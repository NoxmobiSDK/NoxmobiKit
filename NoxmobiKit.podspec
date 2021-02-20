#
#  Be sure to run `pod spec lint NoxmobiKit.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "NoxmobiKit"
  spec.version      = "1.2.2" # Mark
  spec.summary      = "A complete set of monetization solution tools provided by Nox."
  spec.homepage     = "https://github.com/NoxmobiSDK/NoxmobiKit"
  spec.license      = "MIT"
  spec.author       = { "nox_chong" => "gaochong@bignox.com" }
  spec.platform     = :ios, "10.0"
  spec.source       = { :git => "https://github.com/NoxmobiSDK/NoxmobiKit.git", :tag => "#{spec.version}" }
  spec.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  spec.requires_arc = true
  
  spec.subspec 'NoxmobiKitCore' do |ss|
    ss.source_files = "NoxmobiKit.framework/Headers/*.{h}"
    ss.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
    ss.ios.vendored_frameworks = 'NoxmobiKit.framework'
    ss.requires_arc = true
  end

  spec.subspec 'FirebaseAnalytics' do |ss|
    ss.source_files = "NKFirebaseAnalyticsAdapter.framework/Headers/*.{h}"
    ss.ios.vendored_frameworks = 'NKFirebaseAnalyticsAdapter.framework'
    ss.dependency 'Firebase/Analytics'
    ss.dependency 'NoxmobiKit/NoxmobiKitCore'
  end

  spec.subspec 'FirebaseRemoteConfig' do |ss|
    ss.source_files = "NKRemoteConfigAdapter.framework/Headers/*.{h}"
    ss.ios.vendored_frameworks = 'NKRemoteConfigAdapter.framework'
    ss.dependency 'Firebase/RemoteConfig'
    ss.dependency 'NoxmobiKit/NoxmobiKitCore'
  end

  spec.subspec 'FirebaseCrashlytics' do |ss|
    ss.dependency 'Firebase/Crashlytics'
    # 需要在Objective-C中调用[FIRApp configure]来启动FirebaseCrashlytics实例
    ss.dependency 'NoxmobiKit/NoxmobiKitCore'
  end

  spec.subspec 'FacebookLogin' do |ss|
    ss.source_files = "NKFacebookLoginAdapter.framework/Headers/*.{h}"
    ss.ios.vendored_frameworks = 'NKFacebookLoginAdapter.framework'
    ss.dependency 'FBSDKLoginKit'
    ss.dependency 'NoxmobiKit/NoxmobiKitCore'
  end
  
  spec.subspec 'Adjust' do |ss|
    ss.source_files = "NKAdjustAdapter.framework/Headers/*.{h}"
    ss.ios.vendored_frameworks = 'NKAdjustAdapter.framework'
    ss.dependency 'Adjust'
    ss.dependency 'NoxmobiKit/NoxmobiKitCore'
  end

end
