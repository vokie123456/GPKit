//
//  NSObject+KVOCrash.h
//  GPException
//
//  Created by Jezz on 2018/8/29.
//  Copyright © 2018年 Jezz. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (KVOCrash)

+ (void)gp_swizzleKVOCrash;

@end