function main(args) {
  let baseURL=`${process.env.__OW_API_HOST}/api/v1/web/${process.env.__OW_NAMESPACE}/demo3`;
  let template = `
  <html>
  <body>
    <button onclick="loadText()">loadText</button>
    <div id='text'></div>
    <button onclick="loadJSON()">loadJSON</button>
    <div id='json'></div>
    <script type='text/javascript'>
      function loadJSON() {
        var items = document.querySelector('#json');
        fetch('${baseURL}/json').then(function (response) {
          return response.json();
        }).then(function (json) {
          items.innerHTML = JSON.stringify(json);
        });
      }
      function loadText() {
        var result = document.querySelector('#text');
        fetch('${baseURL}/text').then(function (response) {
          return response.text();
        }).then(function (text) {
          result.innerHTML = text;
        });
      }
    </script>
  </body>
  </html>
  `;
  return {
    statusCode: 200,
    headers: {
      'Content-Type': 'text/html'
    },
    body: template
  };
}