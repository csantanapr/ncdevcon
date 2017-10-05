function main(args) {
  let items = [
    { name: 'Carlos', handle: 'csantanpr', project: 'OpenWhisk' },
    { name: 'Raymond', handle: 'raymondcamden', project: 'Cats' },
    { name: 'Simon', handle: 'macdonst', project: 'PhoneGap' }
  ];
  return {
    statusCode: 200,
    headers: {
      'Content-Type': 'application/json',
      'Cache-Control': 'max-age=60'
    },
    body: { items: items }
  };
}
