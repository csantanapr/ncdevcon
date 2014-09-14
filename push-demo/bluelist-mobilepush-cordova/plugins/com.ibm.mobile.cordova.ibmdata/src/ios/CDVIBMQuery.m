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

#import "CDVIBMQuery.h"

@implementation CDVIBMQuery

- (void)queryForObjectId:(CDVInvokedUrlCommand*)command
{
    NSString* objectId = [command.arguments objectAtIndex:0];
    
    [[[IBMQuery queryForObjectId:objectId] find]continueWithBlock:^id(BFTask *task) {
        [self processTask:task forCommand:command];
        return nil;
    }];
    
}

- (void)queryForClass:(CDVInvokedUrlCommand*)command
{
    NSString* className = [command.arguments objectAtIndex:0];
    
    [[[IBMQuery queryForClass:className] find]continueWithBlock:^id(BFTask *task) {
        [self processTask:task forCommand:command];
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
        
        NSArray *objects = task.result;
        NSMutableArray* resultObjects = [[NSMutableArray alloc] init];
        
        for (IBMDataObject* object in objects) {
            
            NSMutableDictionary *resultObject = [[NSMutableDictionary alloc] init];
            NSMutableDictionary *object_meta = [[NSMutableDictionary alloc] init];
            NSMutableDictionary *object_attributes = [[NSMutableDictionary alloc] init];
            
            [object_meta setObject:[object className] forKey:@"className"];
            [object_meta setObject:[object version] forKey:@"version"];
            [object_meta setObject:[object objectId] forKey:@"objectId"];
            
            NSArray* keys = [object allKeys];
            
            for (NSString* key in keys) {
                [object_attributes setObject:[object objectForKey:key] forKey:key];
            }
            
            [resultObject setObject:object_meta forKey:@"_meta"];
            [resultObject setObject:object_attributes forKey:@"attributes"];
            
            [resultObjects addObject:resultObject];
        }
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:resultObjects];
        
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
