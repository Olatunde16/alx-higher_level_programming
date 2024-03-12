#!/usr/bin/node
const args = process.argv.slice(2).map(Number);

if (process.argv.length <= 3) {
    console.log(0);
} else {
    const sortedArgs = args.sort((a, b) => b - a);
    console.log(sortedArgs[1]);
}
