//
//  Aardvark.h
//  Aardvark
//
//  Created by Dan Federman on 10/4/14.
//  Copyright (c) 2014 Square, Inc. All rights reserved.
//

typedef NS_ENUM(NSUInteger, ARKLogType) {
    /// Default log type.
    ARKLogTypeDefault,
    /// Marks the beginning or end of a task.
    ARKLogTypeSeparator,
    /// Marks that the log represents an error.
    ARKLogTypeError,
};


OBJC_EXTERN void ARKLog(NSString *format, ...) NS_FORMAT_FUNCTION(1,2);
OBJC_EXTERN void ARKTypeLog(ARKLogType type, NSString *format, ...) NS_FORMAT_FUNCTION(2,3);
OBJC_EXTERN void ARKLogScreenshot();


@protocol ARKBugReporter;


@interface Aardvark : NSObject

/// Enables logging to ARKLog.
+ (void)enableDefaultLogController;

/// Disables logging to ARKLog.
+ (void)disableDefaultLogController;

/// Sets up a two finger press-and-hold gesture recognizer to trigger email bug reports that will be sent to emailAddress.
+ (void)addDefaultBugReportingGestureWithBugReportRecipient:(NSString *)emailAddress;

/// Sets up a two finger press-and-hold gesture recognizer to trigger email bug reports prefilled with prefilledBody that will be sent to emailAddress.
+ (void)addDefaultBugReportingGestureWithBugReportRecipient:(NSString *)emailAddress prefilledBugReportBody:(NSString *)prefilledBody;

/// Creates and returns a gesture recognizer that when trigger will [bugReporter composeBugReportWithLogs:[ARKLogController defaultController]] after taking a screenshot.
+ (UIGestureRecognizer *)addBugReporter:(id <ARKBugReporter>)bugReporter withTriggeringGestureRecognizerOfClass:(Class)gestureRecognizerClass;

@end
