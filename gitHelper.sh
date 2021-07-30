#! /bin/bash

SDKName="NoxmobiKit"
echo "\n🔥当前版本号："
# 读取plist中的版本号
srcVer=$(/usr/libexec/PlistBuddy -c "Print CFBundleShortVersionString" ./$SDKName.framework/Info.plist)
echo "\n🔥版本号 = " "$srcVer"

echo "\n🔥查看改动 git status："
gitStatusRes=`git status`
echo "$gitStatusRes"

echo "\n🔥添加到暂存区 git add . ："
gitAddRes=`git add .`

echo "\n🔥提交 git commit："
gitCommitRes=`git commit -m $srcVer`
echo "$gitCommitRes"

echo "\n🔥推送到远程 git push："
gitPushRes=`git push origin main`
echo "$gitPushRes"
