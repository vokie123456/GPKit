//
//  GPCategoryImageView.h
//  GPCategoryView
//
//  Created by Liyanwei on 2018/8/8.
//  Copyright © 2018年 Liyanwei. All rights reserved.
//

#import "GPCategoryTitleView.h"
#import "GPCategoryTitleImageCell.h"
#import "GPCategoryTitleImageCellModel.h"

@interface GPCategoryTitleImageView : GPCategoryTitleView

@property (nonatomic, strong) NSArray <NSString *>*imageNames;

@property (nonatomic, strong) NSArray <NSURL *>*imageURLs;

@property (nonatomic, strong) NSArray <NSString *>*selectedImageNames;

@property (nonatomic, strong) NSArray <NSURL *>*selectedImageURLs;

@property (nonatomic, strong) NSArray <NSNumber *> *imageTypes;    //默认GPCategoryTitleImageType_LeftImage

@property (nonatomic, copy) void(^loadImageCallback)(UIImageView *imageView, NSURL *imageURL);   //使用imageURL从远端下载图片进行加载，建议使用SDWebImage等第三方库进行下载。

@property (nonatomic, assign) CGSize imageSize;     //默认CGSizeMake(20, 20)

@property (nonatomic, assign) CGFloat titleImageSpacing;    //titleLabel和ImageView的间距，默认5

@property (nonatomic, assign) BOOL imageZoomEnabled;     //默认为NO

@property (nonatomic, assign) CGFloat imageZoomScale;    //默认1.2，imageZoomEnabled为YES才生效

@end
