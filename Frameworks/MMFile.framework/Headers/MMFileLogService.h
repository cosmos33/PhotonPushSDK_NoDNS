//
//  MMFileLogManager.h
//  Expecta
//
//  Created by Dai Dongpeng on 2018/10/20.
//

#import <Foundation/Foundation.h>

@class MMFileLogInfo, MMFileLogConfig;

typedef NS_ENUM(NSInteger, MMFileEvent) {
    MMFileEvent_None = -1,
    MMFileEvent_WriteError = 0,
    MMFileEvent_OutOfBuffer,
    MMFileEvent_OpenMMPError,
    MMFileEvent_MoveOldFile,
    MMFileEvent_GetDiskFreeError,
    MMFileEvent_DiskFreeIsLow,
    MMFileEvent_INNER_FILE_FULL,
};
typedef void(^MMFileEventBlock)(MMFileEvent event, NSString *msg);

@interface MMFileLogService : NSObject

@property (nonatomic, strong, readonly) MMFileLogConfig *config;
@property (nonatomic, strong, readonly) MMFileLogInfo *commonInfo;

- (instancetype)initWithConfig:(MMFileLogConfig *)config commonInfo:(MMFileLogInfo *)info;
- (void)updateCommoninfo:(MMFileLogInfo *)info;
- (void)setEventBlock:(MMFileEventBlock)block;

- (void)start;
- (void)writeLog:(MMFileLogInfo *)info;
- (void)flush;
- (void)close;
- (void)openNewLogFile;
@end
