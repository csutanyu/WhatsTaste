//
//  WebViewController.h
//  WhatsTaste
//
//  Created by arvin.tan on 4/9/15.
//  Copyright (c) 2015 DJI. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import "JavaScriptController.h"

typedef void (^NativeFunction)(NSDictionary *arguments);

@protocol WebViewControllerExport<JSExport>

- (void)pushNewWebControllerWithURL:(NSString *)urlString title:(NSString *)title;

@end


@interface WebViewController : UIViewController <UIWebViewDelegate, WebViewControllerExport>

@property (weak, nonatomic) IBOutlet UIWebView *webView;
@property (copy, nonatomic) NSURL *destinationURL;
@property (strong, nonatomic) JSContext *context;
@property (strong, nonatomic) JavaScriptController *javaScriptController;
@property (strong, nonatomic) NSMutableDictionary *javaScriptControllerTaskHandler;

- (void)pushNewWebControllerWithURL:(NSString *)urlString title:(NSString *)title;
- (void)setupJavaScriptControllerTaskHandler;

@end