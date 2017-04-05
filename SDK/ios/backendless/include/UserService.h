//
//  UserService.h
//  backendlessAPI
/*
 * *********************************************************************************************************************
 *
 *  BACKENDLESS.COM CONFIDENTIAL
 *
 *  ********************************************************************************************************************
 *
 *  Copyright 2012 BACKENDLESS.COM. All Rights Reserved.
 *
 *  NOTICE: All information contained herein is, and remains the property of Backendless.com and its suppliers,
 *  if any. The intellectual and technical concepts contained herein are proprietary to Backendless.com and its
 *  suppliers and may be covered by U.S. and Foreign Patents, patents in process, and are protected by trade secret
 *  or copyright law. Dissemination of this information or reproduction of this material is strictly forbidden
 *  unless prior written permission is obtained from Backendless.com.
 *
 *  ********************************************************************************************************************
 */

#import <Foundation/Foundation.h>

@class BackendlessUser, Fault, UserProperty;
@protocol IResponder;
// FB
@class FBSDKAccessToken;

@interface UserService : NSObject

@property (strong, nonatomic) BackendlessUser *currentUser;
@property (readonly) BOOL isStayLoggedIn;

// switch on/off the persistent user mode
-(BOOL)setStayLoggedIn:(BOOL)value;

// sync methods with fault return  (as exception)
-(BackendlessUser *)registering:(BackendlessUser *)user __attribute__((deprecated("Replaced by the registerUser method")));
-(BackendlessUser *)registerUser:(BackendlessUser *)user;
-(BackendlessUser *)update:(BackendlessUser *)user;
-(BackendlessUser *)login:(NSString *)login password:(NSString *)password;
-(BackendlessUser *)findById:(NSString *)objectId;
-(id)logout;
-(NSNumber *)isValidUserToken;
-(id)restorePassword:(NSString *)login;
-(NSArray<UserProperty*> *)describeUserClass;
-(NSArray<NSString*> *)getUserRoles;
-(BackendlessUser *)loginWithFacebookSDK:(FBSDKAccessToken *)accessToken fieldsMapping:(NSDictionary<NSString*,NSString*> *)fieldsMapping __attribute__((deprecated("Replaced by loginWithFacebookSDK:userId:tokenString:expirationDate:fieldsMapping sync method")));
-(BackendlessUser *)loginWithFacebookSDK:(NSString *)userId tokenString:(NSString *)tokenString expirationDate:(NSDate *)expirationDate fieldsMapping:(id)fieldsMapping;
-(BackendlessUser *)loginWithGoogleSignInSDK:(NSString *)idToken accessToken:(NSString *)accessToken permissions:(NSArray<NSString*> *)permissions fieldsMapping:(NSDictionary<NSString*,NSString*> *)fieldsMapping;
-(id)resendEmailConfirmation:(NSString *)email;

// async methods with responder
-(void)findById:(NSString *)objectId responder:(id <IResponder>)responder;
-(void)describeUserClass:(id <IResponder>)responder;
-(void)loginWithGoogleSignInSDK:(NSString *)idToken accessToken:(NSString *)accessToken permissions:(NSArray<NSString*> *)permissions fieldsMapping:(NSDictionary<NSString*,NSString*> *)fieldsMapping responder:(id<IResponder>)responder;
-(void)resendEmailConfirmation:(NSString *)email responder:(id <IResponder>)responder;

// async methods with block-based callbacks
-(void)registering:(BackendlessUser *)user response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock __attribute__((deprecated("Replaced by the registerUser method")));
-(void)registerUser:(BackendlessUser *)user response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)update:(BackendlessUser *)user response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)login:(NSString *)login password:(NSString *)password response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)findById:(NSString *)objectId response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)logout:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)isValidUserToken:(void(^)(NSNumber *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)restorePassword:(NSString *)login response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)describeUserClass:(void(^)(NSArray<UserProperty*> *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)getUserRoles:(void(^)(NSArray<NSString*> *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)loginWithFacebookSDK:(FBSDKAccessToken *)accessToken fieldsMapping:(NSDictionary<NSString*,NSString*> *)fieldsMapping response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock __attribute__((deprecated("Replaced by loginWithFacebookSDK:userId:tokenString:expirationDate:fieldsMapping async method")));
-(void)loginWithFacebookSDK:(NSString *)userId tokenString:(NSString *)tokenString expirationDate:(NSDate *)expirationDate fieldsMapping:(id)fieldsMapping response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)loginWithGoogleSignInSDK:(NSString *)idToken accessToken:(NSString *)accessToken permissions:(NSArray *)permissions fieldsMapping:(NSDictionary<NSString*,NSString*> *)fieldsMapping response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)resendEmailConfirmation:(NSString *)email response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;

// methods of social easy logins
// Twitter
-(void)easyLoginWithTwitterFieldsMapping:(NSDictionary<NSString*,NSString*> *)fieldsMapping;
-(void)easyLoginWithTwitterFieldsMapping:(NSDictionary<NSString*,NSString*> *)fieldsMapping responder:(id<IResponder>)responder;
-(void)easyLoginWithTwitterFieldsMapping:(NSDictionary<NSString*,NSString*> *)fieldsMapping response:(void(^)(NSNumber *))responseBlock error:(void(^)(Fault *))errorBlock;
// Google+
-(void)easyLoginWithGooglePlusFieldsMapping:(NSDictionary<NSString*,NSString*> *)fieldsMapping permissions:(NSArray<NSString*> *)permissions;
-(void)easyLoginWithGooglePlusFieldsMapping:(NSDictionary<NSString*,NSString*> *)fieldsMapping permissions:(NSArray<NSString*> *)permissions responder:(id<IResponder>)responder;
-(void)easyLoginWithGooglePlusFieldsMapping:(NSDictionary<NSString*,NSString*> *)fieldsMapping permissions:(NSArray<NSString*> *)permissions response:(void (^)(NSNumber *))responseBlock error:(void (^)(Fault *))errorBlock;

// utilites
-(id)handleOpenURL:(NSURL *)url;
-(void)handleOpenURL:(NSURL *)url completion:(void(^)(BackendlessUser *))completion;

// persistent user
-(BOOL)getPersistentUser;
-(BOOL)setPersistentUser;
-(BOOL)resetPersistentUser;

@end
