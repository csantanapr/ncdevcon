// shows how to handle a Web FORM only allows POST and uses Promises
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

  return new Promise((resolve) => {
    var body;
    body = {
      name: name,
      handle: handle,
      project: project,
      method: method
    }
    resolve(html(body));
  })

}
function html({ name, handle, project }) {
  let html = `
  <html>
  <body>
  <p>Thank you for your input</p>
  name: ${name}<br>
  handle: ${handle}<br>
  project: ${project}<br>
  </body>
  </html>
  `;
  return {
    headers: {
      'Content-Type': 'text/html'
    },
    body: html
  };
}
exports.main = main;