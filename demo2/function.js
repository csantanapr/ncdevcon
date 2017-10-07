// web action returning text Conten-type:text/html statusCode:200
function main({name}) {
  var msg = 'you did not tell me who you are.';
  if (name) {
    msg = `Hello ${name}!`
  }
  return {body: `<html><body><h3>${msg}</h3></body></html>`}
}