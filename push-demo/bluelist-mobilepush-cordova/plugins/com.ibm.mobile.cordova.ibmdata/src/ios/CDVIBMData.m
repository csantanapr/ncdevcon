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

#import "CDVIBMData.h"

@interface CDVIBMData ()

@property (nonatomic) IBMData* data;

@end

@implementation CDVIBMData

- (void)initializeService:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* result = nil;

    [IBMData initializeService];
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK ];
    _data = [IBMData service];

    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)createObject:(CDVInvokedUrlCommand*)command
{
    
    NSString* className = [command.arguments objectAtIndex:0];
    NSMutableDictionary* attributes = nil;
    
    if([command.arguments count] >1) {
        attributes = [command.arguments objectAtIndex:1];
    }
    
    IBMDataObject *dataObject = [IBMDataObject objectOfClass:className];
    
    NSArray* keys = [attributes allKeys];
    for (NSString* key in keys) {
        [dataObject setObject:[attributes objectForKey:key] forKey:key];
    }
    
    [[dataObject save] continueWithBlock:^id(BFTask *task) {
        [self processTask:task forCommand:command];
        return nil;
    }];
    
}

- (void)updateObject:(CDVInvokedUrlCommand*)command
{
   
    NSMutableDictionary* objectForUpdate = [command.arguments objectAtIndex:0];
    NSMutableDictionary* meta = [objectForUpdate objectForKey:@"_meta"];
    NSMutableDictionary* attributes = [objectForUpdate objectForKey:@"attributes"];
    
    NSString* objectId = [meta objectForKey:@"objectId"];
    
    [[[IBMQuery queryForObjectId:objectId] find]continueWithBlock:^id(BFTask *task) {
        if(task.error){
            CDVPluginResult* pluginResult = nil;
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[[task error] debugDescription ]];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
            
        } else{
            
            IBMDataObject *dataObject = [task.result objectAtIndex:0];
            NSArray* keys = [attributes allKeys];
            for (NSString* key in keys) {
                [dataObject setObject:[attributes objectForKey:key] forKey:key];
            }
            
            [[dataObject save] continueWithBlock:^id(BFTask *task) {
                [self processTask:task forCommand:command];
                return nil;
            }];
        
        }
        return nil;
    }];
    
}

- (void)deleteObject:(CDVInvokedUrlCommand*)command
{
    
    NSMutableDictionary* objectForUpdate = [command.arguments objectAtIndex:0];
    NSMutableDictionary* meta = [objectForUpdate objectForKey:@"_meta"];
    
    NSString* objectId = [meta objectForKey:@"objectId"];
    
    [[[IBMQuery queryForObjectId:objectId] find]continueWithBlock:^id(BFTask *task) {
        if(task.error){
            CDVPluginResult* pluginResult = nil;
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[[task error] debugDescription ]];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
            
        } else{
            
            [[[task.result objectAtIndex:0] delete] continueWithBlock:^id(BFTask *task) {
                [self processTask:task forCommand:command];
                return nil;
            }];
            
        }
        return nil;
    }];
    
}

-(void) processTask: (BFTask *) task forCommand: (CDVInvokedUrlCommand *) command
{
    
    CDVPluginResult* pluginResult = nil;
    
    if(task.error){

        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[[task error] debugDescription ]];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        
    } else{
        
        IBMDataObject *response = task.result;
        NSMutableDictionary *result = [[NSMutableDictionary alloc] init];
        NSMutableDictionary *object_meta = [[NSMutableDictionary alloc] init];
        NSMutableDictionary *object_attributes = [[NSMutableDictionary alloc] init];
        
        [object_meta setObject:[response className] forKey:@"className"];
        [object_meta setObject:[response version] forKey:@"version"];
        [object_meta setObject:[response objectId] forKey:@"objectId"];
        
        NSArray* keys = [response allKeys];
        
        for (NSString* key in keys) {
            [object_attributes setObject:[response objectForKey:key] forKey:key];
        }
        
        [result setObject:object_meta forKey:@"_meta"];
        [result setObject:object_attributes forKey:@"attributes"];
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:result];
        
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
