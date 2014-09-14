//-------------------------------------------------------------------------------
// Copyright 2014 IBM Corp. All Rights Reserved
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//-------------------------------------------------------------------------------

#import "CDVIBMBluemix.h"

// IBMSecurityProvider strings
#define PROVIDER_GOOGLE    @"GOOGLE"
#define PROVIDER_WORKLIGHT @"WORKLIGHT"

// JSON representations for JS
#define JSON_VERSION       @"{version:%@}"
#define JSON_CURRENTUSER   @"{uuid:%@,securityProvider:%@,securityToken:%@}"
#define JSON_CURRENTDEVICE @"{hardwareId:%@,model:%@,platform:%@,platformVersion:%@,name:%@}"

@implementation CDVIBMBluemix

- (void)initialize:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* result = nil;
    NSString* applicationId = [command.arguments objectAtIndex:0];
    NSString* applicationSecret = [command.arguments objectAtIndex:1];
    NSString* applicationRoute = [command.arguments objectAtIndex:2];
    
    if (applicationId && [applicationId length] > 0 && applicationRoute && [applicationRoute length] > 0 && applicationSecret && [applicationSecret length] > 0) {
        @try
        {
            [IBMBluemix initializeWithApplicationId: applicationId
                               andApplicationSecret: applicationSecret
                                andApplicationRoute: applicationRoute];
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        }
        @catch (NSException *exception)
        {
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:exception.description];
        }
    } else {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"The application id to initialize is not specified."];
    }
    
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)setSecurityToken:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* result = nil;
    NSString* token = [command.arguments objectAtIndex:0];
    NSString* providerArg = [command.arguments objectAtIndex:1];
    IBMSecurityProvider provider = IBMSecurityProvider_GOOGLE;  // default
    
    if ([providerArg caseInsensitiveCompare:PROVIDER_WORKLIGHT] == NSOrderedSame){
        provider = IBMSecurityProvider_WORKLIGHT;
    } else {
        provider = IBMSecurityProvider_GOOGLE;
    }
    
    @try
    {
        __weak CDVIBMBluemix* weak_self = self;
        [[IBMBluemix setSecurityToken:token fromProvider:provider] continueWithBlock:^id(BFTask *task) {
            if (task.error){
                CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
                [weak_self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
            } else {
                CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK ];
                [weak_self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
            }
            return nil;
        }];
    }
    @catch (NSException *exception)
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:exception.description];
        [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
    }
}

- (void)clearSecurityToken:(CDVInvokedUrlCommand*)command
{
    __weak CDVIBMBluemix* weak_self = self;
    [[IBMBluemix clearSecurityToken] continueWithBlock:^id(BFTask *task){
        if (task.error){
            CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
            [weak_self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
        } else {
            CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK ];
            [weak_self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
        }
        return nil;
    }];
}

- (void)version:(CDVInvokedUrlCommand*)command
{
    NSString* version = [IBMBluemix version];
    NSString* json = nil;
    
    json = [NSString stringWithFormat:JSON_VERSION,version];
    
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:json];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];    
}

- (void)currentUser:(CDVInvokedUrlCommand*)command
{
    IBMCurrentUser* user = [IBMBluemix currentUser];
    NSString* securityProvider = nil;
    NSString* json = nil;
    
    switch (user.securityProvider){
        case IBMSecurityProvider_WORKLIGHT:
            securityProvider = PROVIDER_WORKLIGHT;
            break;
        case IBMSecurityProvider_GOOGLE:
        default:
            securityProvider = PROVIDER_GOOGLE;
            break;
    }
    
    json = [NSString stringWithFormat:JSON_CURRENTUSER,user.uuid,securityProvider,user.securityToken];
    
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:json];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)currentDevice:(CDVInvokedUrlCommand*)command
{
    IBMCurrentDevice* device = [IBMBluemix currentDevice];
    NSString* json = nil;
    
    json = [NSString stringWithFormat:JSON_CURRENTDEVICE,device.uuid,device.model,device.platform,device.platformVersion,device.name];
    
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:json];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

@end