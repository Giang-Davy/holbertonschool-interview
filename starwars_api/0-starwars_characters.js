const request = require('request');

// Get the Movie ID from the command line arguments
const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: node 0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

// URL for the Star Wars API films endpoint
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// Make a request to the API
request(url, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Error: Unable to fetch data (Status Code: ${response.statusCode})`);
    return;
  }

  // Parse the response body
  const filmData = JSON.parse(body);

  // Iterate over the characters list and fetch their names
  const characters = filmData.characters;
  characters.forEach((characterUrl) => {
    request(characterUrl, (charError, charResponse, charBody) => {
      if (charError) {
        console.error(charError);
        return;
      }

      if (charResponse.statusCode === 200) {
        const characterData = JSON.parse(charBody);
        console.log(characterData.name);
      } else {
        console.error(`Error: Unable to fetch character data (Status Code: ${charResponse.statusCode})`);
      }
    });
  });
});
