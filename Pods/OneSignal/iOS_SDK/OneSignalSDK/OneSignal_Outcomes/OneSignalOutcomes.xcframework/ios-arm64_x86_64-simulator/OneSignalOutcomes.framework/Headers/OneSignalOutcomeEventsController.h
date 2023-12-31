/**
 Modified MIT License
 
 Copyright 2019 OneSignal
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 1. The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 2. All copies of substantial portions of the Software may only be used in connection
 with services provided by OneSignal.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */


#import "OSSessionManager.h"
#import "OSOutcomeEventsFactory.h"
#import "OSInAppMessageOutcome.h"
#import "OSOutcomeEvent.h"
#import "OSFocusInfluenceParam.h"

@interface OneSignalOutcomeEventsController : NSObject

- (instancetype _Nonnull)initWithSessionManager:(OSSessionManager * _Nonnull)sessionManager
                           outcomeEventsFactory:(OSOutcomeEventsFactory *_Nonnull)outcomeEventsFactory;

- (void)clearOutcomes;
- (void)cleanUniqueOutcomeNotifications;

- (void)addOutcome:(NSString * _Nonnull)name;
- (void)addUniqueOutcome:(NSString * _Nonnull)name;
- (void)addOutcomeWithValue:(NSString * _Nonnull)name value:(NSNumber * _Nonnull)value;

- (void)sendClickActionOutcomes:(NSArray<OSInAppMessageOutcome *> *_Nonnull)outcomes
                          appId:(NSString * _Nonnull)appId
                     deviceType:(NSNumber * _Nonnull)deviceType;

- (void)sendSessionEndOutcomes:(NSNumber* _Nonnull)timeElapsed
                         appId:(NSString * _Nonnull)appId
            pushSubscriptionId:(NSString * _Nonnull)pushSubscriptionId
                   onesignalId:(NSString * _Nonnull)onesignalId
               influenceParams:(NSArray<OSFocusInfluenceParam *> * _Nonnull)influenceParams
                     onSuccess:(OSResultSuccessBlock _Nonnull)successBlock
                     onFailure:(OSFailureBlock _Nonnull)failureBlock;

@end
