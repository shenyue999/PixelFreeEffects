//
//  SMStickerModel.h
//  SMBeautyEngine
//
//  Created by 孙慕 on 2020/7/27.
//  Copyright © 2020 孙慕. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, SMFilterType)
{
    SMFilterTypeBeauty,         // 磨皮、瘦脸等
    SMFilterTypeStyle,          // 风格滤镜
    SMFilterTypeEffects         // 人脸特效
};

/* 美颜 */
@interface SMBeautyFilterModel : NSObject

//大眼
@property (nonatomic, assign) float enlargeEyeStrength;
//瘦脸
@property (nonatomic, assign) float faceLiftStrength;
//削脸
@property (nonatomic, assign) float faceShaveStrength;
//下巴
@property (nonatomic, assign) float chinChangeStrength;
//磨皮
@property (nonatomic, assign) float blurStrength;
//美白
@property (nonatomic, assign) float whitenStrength;
//红润
@property (nonatomic, assign) float ruddyStrength;
//锐化
@property (nonatomic, assign) float sharpenStrength;

/* 滤镜输入 */
@property (nonatomic, strong) UIImage *lutImage;
@property (nonatomic, assign) float lutImageStrength;
@end


@interface SMMakeUpFilterModel : NSObject
@property (nonatomic, assign) float lipStrength;
@end

/* 人脸特效道具 */
@interface SMNodeModel : NSObject
/// 模型类型
@property (nonatomic, strong) NSString *type;
/// 存放素材的文件夹名称 (素材目录下图片格式 dirname_000.png)
@property (nonatomic, strong) NSString *dirname;
/// 图片素材文件路径
@property (nonatomic, strong) NSString *filePath;
/// 贴纸中心点
@property (nonatomic, assign) NSInteger facePos;
/// 人脸起始位置
@property (nonatomic, assign) NSInteger startIndex;
/// 人脸结束位置，起始位置和结束位置用于求人脸宽度的
@property (nonatomic, assign) NSInteger endIndex;
/// 贴纸x轴偏移量
@property (nonatomic, assign) float offsetX;
/// 贴纸y轴偏移量
@property (nonatomic, assign) float offsetY;
/// 贴纸缩放倍数(相对于人脸)
@property (nonatomic, assign) float ratio;
/// 素材图片的个数
@property (nonatomic, assign) NSInteger number;
/// 素材图片的分辨率，同一个dirname下的素材图片分辨率要一致
@property (nonatomic, assign) float width;
@property (nonatomic, assign) float height;
/// 该dirname下所有的素材图片，每张图片的播放时间，以毫秒为单位。不同dirname下的素材图片的duration可以不同。
@property (nonatomic, assign) NSInteger duration;
/// 该dirname下所有素材图片都播放完一遍之后，是否重新循环播放。1：循环播放，0：不循环播放。
@property (nonatomic, assign) NSInteger isloop;
/// 最多支持人脸数
@property (nonatomic, assign) NSInteger maxcount;
@end

@interface SMStickerModel : NSObject

//@property (nonatomic, assign) SMFilterType type;
//@property (nonatomic, strong) NSString *fileName;
@property (nonatomic, strong) NSString *name;
//@property (nonatomic, strong) NSString *icon;

/* 滤镜输入 */
//@property (nonatomic, strong) NSString *image;
//@property (nonatomic, assign) BOOL isAdjust;
//@property (nonatomic, assign) float currentAlphaValue;
//@property (nonatomic, strong) NSArray<NSString *> *textureImages;
/* 是否渲染 */
@property (nonatomic, assign) BOOL isRender;
/* 用户贴纸*/
@property (nonatomic, strong) NSArray<SMNodeModel *> *nodes;


// 人脸特效
+ (SMStickerModel *)buildStickerFilterModelsWithPath:(NSString *)filter;

@end

NS_ASSUME_NONNULL_END
