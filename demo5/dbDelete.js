var nano = require('nano');
var db;
function main({ handle, dbname, _credentials }) {
  db = db ? db : nano(_credentials.write.url).use(dbname);
  return new Promise((resolve) => {
    if(handle){
      console.log(`DEBUG: handle passed ${handle}`)
      deleteFromDB(db, handle, resolve);
    } else {
      resolve({
        statusCode: 400,
        body: "Missing parameter handle"
      });
    }
  });
}

function deleteFromDB(db, id, resolve){
  db.get(id, (err, body) => {
    console.log(`DEBUG: after db.get body ${JSON.stringify(body)}`)
    console.log(`DEBUG: after db.get err ${JSON.stringify(err)}`)
    if (!err) {
      db.destroy(id,body._rev,(err, body)=>{
        console.log(`DEBUG: after db.destroy body ${JSON.stringify(body)}`)
        console.log(`DEBUG: after db.destroy err ${JSON.stringify(err)}`)
        if(!err){
          resolve({
            body:body
          })
        } else {
          resolve({
            statusCode:500,
            body: err
          });
        }
      });
    } else {
      resolve({
        statusCode: 404,
        body: "item not found"
      });
    }
  });
}

exports.main = main;