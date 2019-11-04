var publications
var journals = []

let impacts = []

const readline = require('readline');
var prompt = require('prompt');

const rl1 = readline.createInterface({ input: process.stdin, output: process.stdout })
rl1.once('line',(input) => {
  let T = parseInt(input, 10) - 1
  rl1.close()

  const rl2 = readline.createInterface({ input: process.stdin, output: process.stdout })
  rl2.once('line',(input) => {
    publications = JSON.parse(input)
    rl2.close()

    // function ask() {
    //   prompt.get(['name'], function(err, result) {
    //     if (journals.length===T) {
    //       work()
    //     } else {
    //       journals.push(JSON.parse(result.name))
    //       ask()
    //     }
    //   })
    // }
    // ask()

    const rlx = readline.createInterface({ input: process.stdin, output: process.stdout })
    for(let i=0; i<T; i++) {
      rlx.on('line',(input) => {
        if(journals.length===T) {
          rlx.close()
          work()
        }
        else
          journals.push(JSON.parse(input))
      })
    }
  })
})

function work() {
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
}}