//
//  GPInspector.m
//  GPPerformance
//
//  Created by Liyanwei on 2019/5/14.
//  Copyright © 2019 Liyanwei. All rights reserved.
//

#import "GPInspector.h"
#import "GPInspectorOverlay.h"
#import "GPInspectorWindow.h"
#import "GPInspectController.h"
#import "GPCrashInspector.h"

UIWindow* g_lastKeyWindow = nil;

@implementation GPInspector

+ (void)showOnStatusBar
{
    //dispatch to the next runloop
    dispatch_async(dispatch_get_main_queue(), ^{
        [GPInspectorOverlay show];
    });
    
}

+ (BOOL)isShow
{
    return ![GPInspectorWindow sharedInstance].hidden;
}

+ (void)show
{
    // key window
    g_lastKeyWindow = [UIApplication sharedApplication].keyWindow;
    
    UIWindow* window = [GPInspectorWindow sharedInstance];
    [window makeKeyWindow];
    
    window.hidden = NO;
    UIViewController* vc = [GPInspectController new];
    UIViewController* root = [[GPNavigationController alloc] initWithRootViewController:vc];
    window.rootViewController = root;
    
    [window makeKeyAndVisible];
    
    [GPInspectorOverlay hide];
}

+ (void)hide
{
    [GPInspectorWindow sharedInstance].hidden = YES;
    // key window
    [g_lastKeyWindow makeKeyAndVisible];
    
    [GPInspectorOverlay show];
}

+ (void)setShouldHandleCrash:(BOOL)b
{
    if (b) {
        [[GPCrashInspector sharedInstance] install];
    }
}

+ (void)setShouldHookException:(BOOL)b
{
    [[NSUserDefaults standardUserDefaults] setObject:@(b ? 1:0) forKey:@"hook_exception"];
}

+ (BOOL) isHookException
{
    id tmp = [[NSUserDefaults standardUserDefaults] objectForKey:@"hook_exception"];
    if ([tmp isKindOfClass:[NSNumber class]]) {
        return [tmp boolValue];
    }
    
    return NO;
}

@end
