//
//  CBLMockConnectionErrorLogic.h
//  CouchbaseLite
//
//  Copyright (c) 2018 Couchbase, Inc. All rights reserved.
//
//  Licensed under the Couchbase License Agreement (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//  https://info.couchbase.com/rs/302-GJY-034/images/2017-10-30_License_Agreement.pdf
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <Foundation/Foundation.h>
#import "CBLMockConnectionLifecycleLocation.h"
@class CBLMessagingError;

@protocol CBLMockConnectionErrorLogic <NSObject>

- (BOOL) shouldCloseAtLocation: (CBLMockConnectionLifecycleLocation)location;

- (CBLMessagingError*) createError;

@end

@interface CBLNoErrorLogic : NSObject<CBLMockConnectionErrorLogic>

@end

@interface CBLTestErrorLogic : NSObject<CBLMockConnectionErrorLogic>

- (instancetype) initAtLocation: (CBLMockConnectionLifecycleLocation)location withRecoveryCount: (NSInteger)recoveryCount;

@end

@interface CBLReconnectErrorLogic : NSObject <CBLMockConnectionErrorLogic>

@property (atomic) BOOL isErrorActive;

@end
