#!/usr/bin/node
const dict = require('./101-data');

const usersByOccurrence = {};

for (const userId in dict) {
    const occurrence = dict[userId];
    if (!usersByOccurrence[occurrence]) {
        usersByOccurrence[occurrence] = [];
    }
    usersByOccurrence[occurrence].push(userId);
}

console.log(usersByOccurrence);
