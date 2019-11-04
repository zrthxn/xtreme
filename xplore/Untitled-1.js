let impacts = []

let T

let publications
let journals = []

function main() {
  // write your code here.
  // call functions `nextString`, `nextFloat` and `nextInt` 
  // to read the next token of input (ignoring whitespace)
  // Alternatively, you can create your own input parser functions
  // use console.log() to write to stdout

  T = nextInt();
  
  for(let i=0; i<T; i++) {
    var I = JSON.parse(nextString());

    if(i===0) {
      publications = I
    }
    else {
      journals.push( I )
    }
  }

  publications.publications.forEach((publication)=>{
    let { publicationNumber } = publication
    let citations = 0, citable = 0

    for (const { articleCount } of publication.articleCounts) {
      citable += parseInt(articleCount, 10)
    }

    for (const journal of journals) {
      for (const citation of journal.paperCitations.ieee) {
        if(citation.publicationNumber===publicationNumber) {
          if(citation.year=="2017" || citation.year=="2018") {
            citations += 1
          }
        }
      }
    }
    
    impacts.push({
      title: publication.publicationTitle + ':',
      factor: (citations / citable).toFixed(2)
    })
  })

  impacts.sort((a, b)=>{
    if(a.factor !== b.factor)
      return (b.factor - a.factor)
    else 
      return b.title.localeCompare(a.title)
  })

  for (const i of impacts) {
    console.log( i.title, i.factor )
  }
}

// default parsers for JS.
function nextInt() {
  return parseInt(nextString());
}

function nextFloat() {
  return parseFloat(nextString());
}

function nextString() {
  var next_string = "";
  clearWhitespaces();
  while (input_cursor < input_stdin.length && !isWhitespace(input_stdin[input_cursor])) {
      next_string += input_stdin[input_cursor];
      input_cursor += 1;
  }
  return next_string;
}

function nextChar() {
  clearWhitespaces();
  if (input_cursor < input_stdin.length) {
      return input_stdin[input_cursor++];
  } else {
      return '\0';
  }
}

process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_cursor = 0;
process.stdin.on('data', function (data) { input_stdin += data; });
process.stdin.on('end', function () { main(); });

function isWhitespace(character) {
  return ' \t\n\r\v'.indexOf(character) > -1;
}

function clearWhitespaces() {
  while (input_cursor < input_stdin.length && isWhitespace(input_stdin[input_cursor])) {
      // ignore the next whitespace character
      input_cursor += 1;
  }  
}
