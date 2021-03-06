// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Belt_Array = require("bs-platform/lib/js/belt_Array.js");

function relative_humidity(param) {
  return param[0] - (100.0 - param[1]) / 5.0;
}

var h = [
  3.0,
  55.7
];

var g = [
  39.0,
  70.0
];

console.log(relative_humidity(h));

console.log(relative_humidity(g));

var f = [
  [
    3.0,
    55.7
  ],
  [
    39.0,
    70.0
  ],
  [
    33.0,
    90.0
  ]
];

var j = Belt_Array.map(f, relative_humidity);

console.log(j);

var dpmin = Belt_Array.reduce(j, 0.0, (function (prim, prim$1) {
        if (prim < prim$1) {
          return prim;
        } else {
          return prim$1;
        }
      }));

var dpmax = Belt_Array.reduce(j, 0.0, (function (prim, prim$1) {
        if (prim > prim$1) {
          return prim;
        } else {
          return prim$1;
        }
      }));

var dpavg = Belt_Array.reduce(j, 0.0, (function (x, y) {
        return x + y;
      })) / f.length;

console.log("minimum dew point:", dpmin);

console.log("maximum dew point:", dpmax);

console.log("average dew point:", dpavg);

exports.relative_humidity = relative_humidity;
exports.h = h;
exports.g = g;
exports.f = f;
exports.j = j;
exports.dpmin = dpmin;
exports.dpmax = dpmax;
exports.dpavg = dpavg;
/*  Not a pure module */
