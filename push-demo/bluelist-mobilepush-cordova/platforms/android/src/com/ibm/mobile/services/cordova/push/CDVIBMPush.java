/*
 * IBM Confidential OCO Source Materials
 *
 * Copyright IBM Corp. 2014
 *
 * The source code for this program is not published or otherwise
 * divested of its trade secrets, irrespective of what has
 * been deposited with the U.S. Copyright Office.
 *
 */
package com.ibm.mobile.services.cordova.push;

import java.util.Arrays;
import java.util.List;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.PluginResult;
import org.apache.cordova.PluginResult.Status;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import bolts.Continuation;
import bolts.Task;

import com.ibm.mobile.services.core.internal.IBMLogger;
import com.ibm.mobile.services.push.IBMPush;
import com.ibm.mobile.services.push.IBMPushNotificationListener;
import com.ibm.mobile.services.push.IBMSimplePushNotification;

/** 
 * Cordova plugin for IBMPush
 *  
 */

public class CDVIBMPush extends CordovaPlugin{
	
	private static final String TAG = CDVIBMPush.class.getName();
	
	private IBMPush pushService    = null;
	private String messageCallback = null;	
	
	private static final String ALERT			  = "alert";
	private static final String DEVICEID 		  = "deviceId";
	private static final String PAYLOAD			  = "payload";
	private static final String SUBSCRIPTIONS	  = "subscriptions";
	private static final String TAGNAME 		  = "tagName";
	private static final String TAGS 			  = "tags";
	private static final String URL 			  = "url";
	
	private static String[] validActions = new String[] {"initializeService", "registerDevice", "subscribeTag", "unsubscribeTag", "getTags", "getSubscriptions"};
	
   /**
	* Called when the system is about to start resuming a previous activity. 
	*
	* @param multitasking Flag indicating if multitasking is turned on for app
	*/
	@Override 
	public void onPause(boolean multitasking) {
		super.onPause(multitasking);
		if(pushService != null)
			pushService.hold();	
    }
	
	/**
	* Called when the activity will start interacting with the user. Receives a Push Notification from the Native SDK and calls the 
	* Javascript Callback method to handle notification receipt
	*
	* @param multitasking Flag indicating if multitasking is turned on for app
	*/	
	@Override 
	public void onResume(boolean multitasking) {
		super.onResume(multitasking);		
		listenToPush();
	}
	
	/**
	 * Executes the request.
	 * 
	 * @param action
	 *            Action to execute. 
	 *            Allowed actions: intializeService, register, subscribeTag, unSubscribeTag, getTags, getSubscriptions, isPushSupported
	 * @param args
	 *            JSONArray of arguments to plugin
	 * @param callbackContext
	 *            The callback context used when calling back into JavaScript
	 * @return True if action is valid and false if the action is invalid or fail
	 * 
	 * @throws JSONException
	 */	
	@Override
	public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
			
		boolean result = false;
		IBMLogger.d(TAG, "Received Action " + action);
		
		if (action == null || !Arrays.asList(validActions).contains(action) ) {
			callbackContext.error("Invalid action specified. Action Name :"+action);
			return result;
		}
		
		if (action.equals("initializeService")) {
			return initializeService(args, callbackContext);
		}
		
		if (pushService == null) {
			callbackContext.error("Push Service is not initialized");
			return result;
		}
		
		IBMPushAction pushAction = IBMPushAction.fromString(action);
		
		if(pushAction != null) { 			
			switch(pushAction) {
			
				case subscribeTag : 
					return subscribeTag(args, callbackContext);					
					
				case registerDevice : 					
					return register(args, callbackContext);
				
				case unsubscribeTag : 					
					return unsubscribeTag(args, callbackContext);
				
				case getTags :					
					return getTags(callbackContext);
					
				case getSubscriptions: 
					return getSubscriptions(callbackContext);	
			}			
		} 
		return result;
	}
	
	/**
	 * Initialize the Push native SDK
	 * 
	 * @param args
	 *            No Input arguments
	 * 
	 * @param callbackContext
	 *            The callback context used when calling back into JavaScript. 
	 *            
	 * @return True if action is valid and false if the action is invalid or fail
	 */
	private boolean initializeService(JSONArray args,
			final CallbackContext callbackContext) {
		
		try {
			pushService = IBMPush.initializeService();		
			IBMLogger.i(TAG, "Initialized Push Service.");
			callbackContext.success();
		}catch(Exception e) {				
			IBMLogger.e(TAG, "Error while initializing the Push Service:" + e.getMessage());
			callbackContext.error(e.getMessage());
		}			
		return true;
	}
	
	/**
	 * Returns the list of tag that are subscribed by the device for receiving notifications
	 * 
	 * @param args
	 *            No Input arguments
	 * 
	 * @param callbackContext
	 *            The callback context used when calling back into JavaScript. On success, the 
	 *            array of subscribed tags are returned.  
	 * @return True if action is valid and false if the action is invalid or fail
	 */
	 private boolean getSubscriptions(final CallbackContext callbackContext) {
		
		IBMLogger.d(TAG, "Received request for getSubscriptions");
				
		pushService.getSubscriptions().continueWith(new Continuation<List<String>, Void>() {

			@Override
			public Void then(Task<List<String>> task) throws Exception {
				if(task.isFaulted()) {
					IBMLogger.e(TAG, "Error occured while getting subscriptions. " + task.getError().getMessage());
					callbackContext.error(task.getError().getMessage());
					return null;
				}
				List<String> tags = task.getResult();
				IBMLogger.d(TAG, "Retrieved subscriptions successfully.");
				callbackContext.success(getSubscriptionsResponse(tags));
				return null;
			} 			
		});
		
		//Send a intermittent No Result, with keeping callback active
		PluginResult pluginResult = new PluginResult(Status.NO_RESULT);
		pluginResult.setKeepCallback(true);
		callbackContext.sendPluginResult(pluginResult);
		
		return true;
	}

	/**
	 * Returns the list of tags that are created in the backend application
	 * 
	 * @param args
	 *            No Input arguments
	 * 
	 * @param callbackContext
	 *            The callback context used when calling back into JavaScript. On success, the 
	 *            array of subscribed tags are returned.  
	 * @return True if action is valid and false if the action is invalid or fail
	 */
	 private boolean getTags(final CallbackContext callbackContext) {
		
		IBMLogger.d(TAG, "Received request for getTags");
	
		pushService.getTags().continueWith(new Continuation<List<String>, Void>() {

			@Override
			public Void then(Task<List<String>> task) throws Exception {
				if(task.isFaulted()) {
					IBMLogger.e(TAG, "Error occured while getting tags. " + task.getError().getMessage());
					callbackContext.error(task.getError().getMessage());
					return null;
				}
				List<String> tags = task.getResult();
				IBMLogger.d(TAG, "Retrieved tags successfully.");
				callbackContext.success(getTagsResponse(tags));
				return null;
			} 			
		});
		
		//Send a intermittent No Result, with keeping callback active
		PluginResult pluginResult = new PluginResult(Status.NO_RESULT);
		pluginResult.setKeepCallback(true);
		callbackContext.sendPluginResult(pluginResult);
		
		return true;	
	}
	 
	 /**
	 * Subscribe the application to the specified tag
	 * 
	 * @param args
	 *            Input arguments. Expected to receive a single argument of the Tag Name to subscribe
	 * 
	 * @param callbackContext
	 *            The callback context used when calling back into JavaScript. On success, the 
	 *            name of the tag subscribed is returned
	 * @return True if action is valid and false if the action is invalid or fail
	 */
	 private boolean subscribeTag(JSONArray args, final CallbackContext callbackContext) {
			
		if(args == null || args.length() == 0)
			callbackContext.error("The tag name to subscribe is not specified");
		
		String tagName = null; 
		IBMLogger.d(TAG, "Received request for subscribe Tag ");
		try {
			tagName = args.getString(0);		
			
			pushService.subscribe(tagName).continueWith(new Continuation<String, Void>() {

				@Override
				public Void then(Task<String> task) throws Exception {
					if(task.isFaulted()) {
						IBMLogger.e(TAG, "Error occured while subscribing tag. " + task.getError().getMessage());
						callbackContext.error(task.getError().getMessage());
						return null;
					}
					String tagName = task.getResult();
					IBMLogger.d(TAG, "Successfully subscribed to tag " + tagName);
					callbackContext.success(getSubscribeResponse(tagName));
					return null;
				} 			
			});
			
			//Send a intermittent No Result, with keeping callback active
			PluginResult pluginResult = new PluginResult(Status.NO_RESULT);
			pluginResult.setKeepCallback(true);
			callbackContext.sendPluginResult(pluginResult);				
				
		}catch (JSONException e) {	
			IBMLogger.e(TAG, "Error occurred while subscribing tag : " + e.getMessage());
			callbackContext.error(e.getMessage());
		}		
		return true;
	}

	 /**
	 * Unsubscribes the application from the specified tag
	 * 
	 * @param args
	 *            Input arguments. Expected to receive a single argument of the Tag Name to unsubscribe
	 * 
	 * @param callbackContext
	 *            The callback context used when calling back into JavaScript. On success, the 
	 *            name of the tag unsubscribed is returned
	 * @return True if action is valid and false if the action is invalid or fail
	 */
	private boolean unsubscribeTag(JSONArray args, final CallbackContext callbackContext) {
		
		if(args == null || args.length() == 0)
			callbackContext.error("The tag name to unsubscribe is not specified");
		
		String tagName = null; 
		IBMLogger.d(TAG, "Received request for unsubscribe Tag ");
		
		try {
			tagName = args.getString(0);
			
			pushService.unsubscribe(tagName).continueWith(new Continuation<String, Void>() {

				@Override
				public Void then(Task<String> task) throws Exception {
					if(task.isFaulted()) {
						IBMLogger.e(TAG, "Error occured while unsubscribing tag. " + task.getError().getMessage());
						callbackContext.error(task.getError().getMessage());
						return null;
					}
					String tagName = task.getResult();
					IBMLogger.d(TAG, "Successfully unsubscribed to tag " + tagName);
					callbackContext.success(getSubscribeResponse(tagName));
					return null;
				} 			
			});			
			
			PluginResult pluginResult = new PluginResult(Status.NO_RESULT);
			pluginResult.setKeepCallback(true);
			callbackContext.sendPluginResult(pluginResult);							
		} catch (JSONException e) {	
			IBMLogger.e(TAG, "Error occurred while unsubscribing tag : " + e.getMessage());
			callbackContext.error(e.getMessage());
		}
		
		return true;
	}

	 /**
	 * Registers the user with the Push Service
	 * 
	 * @param args
	 *            Input arguments. Expected to get three input arguments, consumerId, device Alias and callback function to be called upon receiving Push Notification 
	 * 
	 * @param callbackContext
	 *            The callback context used when calling back into JavaScript. On success, the 
	 *            deviceId is returned. 
	 * @return True if action is valid and false if the action is invalid or fail
	 */
	private boolean register(JSONArray args, final CallbackContext callbackContext) {
		
		if(args == null || args.length() < 3)
			callbackContext.error("Invalid Request parameters. Specify the consumer id and alias. Also specify the callback function to be called on message notification");
		
		IBMLogger.d(TAG, "Received request for device registration");
		try {
			String consumerId = args.getString(0); 
			String alias = args.getString(1);
			String callbackMethod = args.getString(2); 
			
			if(callbackMethod != null)
				callbackMethod = callbackMethod.trim();
						
			if(callbackMethod == null || callbackMethod.equals("")) 
				callbackContext.error("Failed to register the Callback function to be called on Message notification. Specify valid callback function");
			
			messageCallback = callbackMethod;
			pushService.register(alias, consumerId).continueWith(new Continuation<String, Void>() {

				@Override
				public Void then(Task<String> task) throws Exception {
					if(task.isFaulted()) {
						IBMLogger.e(TAG, "Error occured while device register. " + task.getError().getMessage());
						callbackContext.error(task.getError().getMessage());
						return null;
					}
					String deviceId = task.getResult();
					listenToPush();
					IBMLogger.d(TAG, "Successfully registered the device.");
					callbackContext.success(getRegisterResponse(deviceId));
					return null;
				} 			
			});			
			
			PluginResult pluginResult = new PluginResult(Status.NO_RESULT);
			pluginResult.setKeepCallback(true);
			callbackContext.sendPluginResult(pluginResult);
			
		}catch (Exception e) {		
			IBMLogger.e(TAG, "Error occurred while registering device: " + e.getMessage());
			callbackContext.error(e.getMessage());
		}
		return true;		
	}
	
	private static enum IBMPushAction { 
		registerDevice, 
		subscribeTag, 
		unsubscribeTag, 
		getTags,
		getSubscriptions;
		
		public static IBMPushAction fromString(String actionName) {
			try {
				return valueOf(actionName);
			}catch (Exception e) {
				return null;
			}			
		}
	}
	
	// Helper Methods	
	private JSONObject getRegisterResponse(String deviceId) {
		JSONObject r = new JSONObject(); 
		try {
			r.put(DEVICEID, deviceId); 
		}
		catch (JSONException e){
			e.printStackTrace();
		}
		return r;
	}
	
	private JSONObject getSubscribeResponse(String tagName) {
		JSONObject r = new JSONObject(); 
		try {
			r.put(TAGNAME, tagName); 
		}
		catch (JSONException e){
			e.printStackTrace();
		}
		return r;
	}
	
	private JSONObject getSubscriptionsResponse(List<String> tagName) {
		JSONObject r = new JSONObject(); 
		try {
			JSONArray subscriptionArray = new JSONArray();
			
			for(int i=0; i<tagName.size(); i++)
				subscriptionArray.put(tagName.get(i));
			r.put(SUBSCRIPTIONS, subscriptionArray); 
		}
		catch (JSONException e){
			e.printStackTrace();
		}
		return r;
	}
	
	private JSONObject getTagsResponse(List<String> tagNames) {
		JSONObject r = new JSONObject(); 
		try {
			JSONArray tagArray = new JSONArray();			
			for(int i=0; i<tagNames.size(); i++)
				tagArray.put(tagNames.get(i));
			r.put(TAGS, tagArray); 
		}
		catch (JSONException e){
			e.printStackTrace();
		}
		return r;
	}
	
	private JSONObject getPushMessageResponse(IBMSimplePushNotification msg) {
		JSONObject r = new JSONObject(); 
		String payload = msg.getPayload();
		try {
			
			r.put(ALERT, msg.getAlert());
			r.put(URL, msg.getUrl());
			if(payload != null){
				// Need to always be JSON object in order to not return entire object as string in push message/notification
				r.put(PAYLOAD, new JSONObject(payload));
			} else{
				r.put(PAYLOAD, payload);
			}
		}
		catch (JSONException e){
			e.printStackTrace();
		}
		return r;
	}
	
	private void sendResponseToJavaScript(String s) {
		this.webView.sendJavascript(s);
	}
	
	private void listenToPush() {
		IBMPushNotificationListener notificationListener = new IBMPushNotificationListener() {
			
			@Override
			public void onReceive(IBMSimplePushNotification msg) {				
				
				if(messageCallback != null) 
				{					
					StringBuilder builder = new StringBuilder();
					builder.append(messageCallback);
					builder.append("(");
					builder.append(getPushMessageResponse(msg).toString());
					builder.append(");");
					
					sendResponseToJavaScript(builder.toString());
				}				
			}			
		};
		if(pushService != null)
			pushService.listen(notificationListener);
	}
}