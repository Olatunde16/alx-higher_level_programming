#!/usr/bin/node
const list = require('./100-data.js').list;
function customMap(arr, callback) {
    const mappedArr = [];
    for (let i = 0; i < arr.length; i++) {
        mappedArr.push(callback(arr[i], i, arr));
    }
    return mappedArr;
}

console.log(list);
console.log(customMap(list, (item, index) => item * index));
