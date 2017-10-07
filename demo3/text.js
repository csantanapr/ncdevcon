function main(args) {
  let template = `
    <div>
      The date is ${new Date()}
    </div>
  `;
  return {
    statusCode: 200,
    headers: {
      'Content-Type': 'text/plain',
      'Cache-Control': 'max-age=60'
    },
    body: template
  };
}
