var nano = require('nano');
var db;
function main({ name='Carlos', handle='csantanapr-1', project='OpenWhisk', dbname, _credentials }) {
  db = db ? db : nano(_credentials.write.url).use(dbname);
  return new Promise((resolve) => {
    let doc = {_id:handle, name,project}
    db.get(doc._id,(err, body)=>{
      if(!err){
        //doc already in db let's update
        doc._rev = body._rev;
      }
      db.insert(doc,(err, body)=>{
        if(!err){
          resolve({
            body:body
          });
        } else {
          resolve({
            statusCode: 500,
            body: err
          });
        }
      });
    });
  });
}
exports.main = main;