var nano = require('nano');
var db;
function main({ handle, dbname, _credentials }) {
  db = db ? db : nano(_credentials.read.url).use(dbname);
  return new Promise((resolve) => {
    if(handle){
      get(db, handle, resolve);
    } else {
      list(db, resolve);
    }
  });
}

function list(db, resolve) {
  var response = [];
  db.list({ include_docs: true }, (err, body) => {
    if (!err) {
      body.rows.forEach(function (doc) {
        response.push(doc.doc);
      });
      resolve({
        body: {friends:response}
      });
    } else {
      resolve({
        statusCode: 500,
        body: err
      });
    }
  });
}
function get(db, id, resolve){
  db.get(id, (err, body) => {
    if (!err) {
      resolve({
        body: body
      });
    } else {
      resolve({
        statusCode: 500,
        body: err
      });
    }
  });
}

exports.main = main;