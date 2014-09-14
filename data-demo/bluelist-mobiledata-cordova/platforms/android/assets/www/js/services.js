angular.module('starter.services', [])

/**
 * A simple example service that returns some data.
 */
.factory('Friends', function() {
  // Might use a resource here that returns a JSON array

  // Some fake testing data
  var friends = [
    { id: 0, name: 'Scruff McGruff' },
    { id: 1, name: 'G.I. Joe' },
    { id: 2, name: 'Miss Frizzle' },
    { id: 3, name: 'Ash Ketchum' }
  ];

  return {
    all: function() {
      return friends;
    },
    get: function(friendId) {
      // Simple index lookup
      return friends[friendId];
    }
  };
})
/**
 * A simple example service that returns some data.
 */
.factory('ListService', function($rootScope, $q, $cacheFactory) {

    // Use an internal Cache for storing the List and map the operations to manage that from
    // Mobile Cloud SDK Calls
    var cache = $cacheFactory('');
    var options = {
        handleAs: 'JSON'
    };

    return {

        // Return all the Objects for a Given Class
        allCloud: function() {

            // get the Data Service
            var data = $rootScope.dataService;

            // Create a Defer as this is an async operation
            defer = $q.defer();

            // Clear the Cache with a new set
            cache.remove('items');

            // Retreive a Query instance of type "Item" and issue a find() action on it
            // to retreive all the items (NO PAGING)
            var query = data.Query.ofType("Item");
            query.find().done(function(list) {

                // Place the Items in the Cache
                cache.put('items', list);

                // return the Cache
                defer.resolve(cache.get('items'));

            },function(err){
                console.log(err);
                defer.reject(err);
            });

            // Get the Objects for a particular Type
            return defer.promise;

        },

        // Return the Cached List
        allCache: function() {

            // Return the Cached Items
            return cache.get('items');

        },

        add: function(name) {

            // Manage Defer on the Save
            var defer = $q.defer();

            // get the Data Service
            var data = $rootScope.dataService;

            // Create a new Item instance and then save it to the cloud
            var item = data.Object.ofType("Item", {"name":name});

            // add the Item to the Cache but we need to replace it when we
            // get a saved copy back
            var items = cache.get('items');

            // Check we have some items
            if (items) {
                cache.get('items').push(item);
            } else {
                defer.reject('no items defined');
            }

            // Save the Class in the Bluemix Cloud
            item.save().then(function(saved) {

                // Replace the Item
                items.forEach(function(item, i) { if (item.get('name') == saved.get('name')) items[i] = saved;});
                defer.resolve(saved);

            },function(err) {
                defer.reject(err);
            });

            // Return a promise for the async operation of save
            return defer.promise;

        },

        put: function(item) {

            // Create a deferred
            var defer = $q.defer();
            //Save the Item containing new attributes
            item.save().done(function(saved) {
                defer.resolve(saved);
            },function(err){
                defer.reject(err);
            });

            // Return a promise for the async operation of save
            return defer.promise;

        },

        del: function(item) {

            var defer = $q.defer();
            //Delete the Item containing new attributes
            item.del().done(function(deleted) {
                // Validated it was deleted
                var isDeleted = deleted.isDeleted();
                if (deleted.isDeleted()) {
                    // Remove the Item from the Cache
                    var items = cache.get('items');
                    items.splice(items.indexOf(item), 1);
                    defer.resolve(deleted);
                } else {
                    defer.reject(new Error("Try to deleted but it is not deleted"));
                }
            },function(err){
                defer.reject(err);
            });

            // Remove it
            return defer.promise;

        }
    };

});
