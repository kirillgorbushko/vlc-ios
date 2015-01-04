/*****************************************************************************
 * VLCOneDriveController.h
 * VLC for iOS
 *****************************************************************************
 * Copyright (c) 2014-2015 VideoLAN. All rights reserved.
 * $Id$
 *
 * Authors: Felix Paul Kühne <fkuehne # videolan.org>
 *
 * Refer to the COPYING file of the official project for license.
 *****************************************************************************/

#import "VLCOneDriveTableViewController.h"
#import "VLCOneDriveObject.h"

@protocol VLCOneDriveControllerDelegate <NSObject>

@required
- (void)sessionWasUpdated;
- (void)mediaListUpdated;

@optional
- (void)operationWithProgressInformationStarted;
- (void)currentProgressInformation:(float)progress;
- (void)updateRemainingTime:(NSString *)time;
- (void)operationWithProgressInformationStopped;

- (void)numberOfFilesWaitingToBeDownloadedChanged;

@end

@interface VLCOneDriveController : NSObject

@property (nonatomic, weak) VLCOneDriveTableViewController *delegate;
@property (readonly) BOOL activeSession;
@property (readonly) BOOL userAuthenticated;
@property (nonatomic, readonly) VLCOneDriveObject *rootFolder;
@property (nonatomic, readwrite) VLCOneDriveObject *currentFolder;

+ (VLCOneDriveController *)sharedInstance;

- (void)login;
- (void)logout;

- (void)loadCurrentFolder;
- (void)downloadFileWithPath:(NSString *)path;
- (void)streamFileWithPath:(NSString *)path;

@end