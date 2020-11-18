const requestOld = require('request');
const util = require('util');

const request = util.promisify(requestOld);

const myArgs = process.argv.slice(2);

if (myArgs.length !== 1) {
  console.log("Invalid number of arguments, use like: './starwars 3'");
  process.exit(1);
}

const movieNum = myArgs[0];

async function main () {
  const rawData = await request(`https://swapi-api.hbtn.io/api/films/${movieNum}/`);

  const data = JSON.parse(rawData.body);

  const characters = [];

  for (let i = 0; i < data.characters.length; i++) {
    characters.push(request(data.characters[i]).then((result) =>
      JSON.parse(result.body)
    ));
  }

  const charactersResult = await Promise.all(characters);

  for (let i = 0; i < charactersResult.length; i++) {
    console.log(charactersResult[i].name);
  }
}

main();
