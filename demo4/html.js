var fs = require('fs');
var indexFile;

function main(args) {
  return new Promise((resolve) => {
    if (!indexFile) {
      loadFile(`${__dirname}/index.html`, resolve)
    } else {
      resolve(html(indexFile));
    }
  });
}

function loadFile(file, resolve) {
  fs.readFile(file, 'utf8', (err, data) => {
    if (err) {
      resolve(error(err));
    } else {
      indexFile = data;
      resolve(html(indexFile));
    }
  });
}
function html(html) {
  return {
    statusCode: 200,
    headers: {
      'Content-Type': 'text/html',
      'Cache-Control': 'max-age=300'
    },
    body: html
  };
}
function error(err) {
  return {
    statusCode: 500,
    body: err.message
  };
}
exports.main = main;