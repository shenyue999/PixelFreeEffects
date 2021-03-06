//
//  SMPixelFree.h
//  SMBeautyEngine
//
//  Created by 孙慕 on 2020/7/27.
//  Copyright © 2020 孙慕. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#import "SMFilterModel.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((visibility("default"))) @interface SMPixelFree : NSObject


/// 初始化
/// @param context sdk 运行的上线文，context != nil  所有着色器程序将在这里优化， 否在视频第一帧处理时候初始化
- (instancetype)initWithProcessContext:(EAGLContext *)context;

/* 动态贴纸 */
@property(nonatomic, strong) SMStickerModel *stickerModel;
/* 美颜 美型 滤镜*/
@property(nonatomic, strong) SMBeautyFilterModel *beautyModel;

/* 美妆*/
@property(nonatomic, strong) SMMakeUpFilterModel *makeupModle;

/**
 处理纹理数据
 
 @param texture 纹理数据
 @param width 宽度
 @param height 高度
 */
- (void)processWithTexture:(GLuint)texture width:(GLint)width height:(GLint)height;

@end

NS_ASSUME_NONNULL_END
