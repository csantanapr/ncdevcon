var nano = require('nano');
var db;
function main({ _credentials }) {
  db = db ? db : nano(_credentials.read.url).use('friends');
  return new Promise((resolve) => {
    var response=[];
    db.list({include_docs:true},(err, body)=>{
      if (!err) {
        body.rows.forEach(function(doc) {
          response.push(doc.doc);
        });
        resolve({
          friends:response
        });
      } else {
        resolve({
          statusCode: 500,
          body: err
        });
      }
    });
  });
}
exports.main = main;