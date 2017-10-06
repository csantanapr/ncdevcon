// shows how to handle a Web FORM only allows POST
function main({ name = 'Carlos', handle = 'csantanapr', project = 'OpenWhisk', __ow_method: method }) {
  //Function have access to http request properties
  // __ow_method
  // __ow_headers
  // __ow_path
  // __ow_query (when http-raw)
  // __ow_body  (when http-raw or not JSON)
  if (method !== 'post') {
    return { statusCode: 405, body:'Method Not allow, Only POST' };
  }

  return {
    statusCode: 200,
    headers: {
      'Content-Type': 'text/html'
    },
    body: `
    <html>
    <body>
      <p>Thank you for your input</p>
      Name: ${name}<br>
      Handle: ${handle}<br>
      Project: ${project}<br>
    </body>
    </html>
    `
  };
}

exports.main = main;