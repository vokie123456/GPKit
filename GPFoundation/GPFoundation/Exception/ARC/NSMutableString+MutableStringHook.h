//
//  NSMutableString+MutableStringHook.h
//  GPFoundation
//
//  Created by Liyanwei on 2018/9/18.
//  Copyright © 2019 Liyanwei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableString (MutableStringHook)

+ (void)gp_swizzleNSMutableString;

@end
