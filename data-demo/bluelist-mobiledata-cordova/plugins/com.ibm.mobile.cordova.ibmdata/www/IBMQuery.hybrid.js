var cordova = require('cordova'),
    exec = require('cordova/exec');

var IBMQuery = {
		queryForClass : function(className, successCallback, failureCallback) {
	    	 exec(successCallback, failureCallback, "IBMQuery", "queryForClass", [className]);
	    },
		queryForObjectId : function(objectId, successCallback, failureCallback) {
			 exec(successCallback, failureCallback, "IBMQuery", "queryForObjectId", [objectId]);
		}
};
module.exports = IBMQuery;