// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");
var Caml_js_exceptions = require("bs-platform/lib/js/caml_js_exceptions.js");

function shirtSize_of_string(src) {
  console.log("in shirtSize_of_string", src);
  switch (src) {
    case "Large" :
        return /* Large */2;
    case "Medium" :
        return /* Medium */1;
    case "Small" :
        return /* Small */0;
    case "XLarge" :
        return /* XLarge */{
                _0: 1
              };
    case "XXLarge" :
        return /* XLarge */{
                _0: 2
              };
    case "XXXLarge" :
        return /* XLarge */{
                _0: 3
              };
    case "XXXXLarge" :
        return /* XLarge */{
                _0: 4
              };
    default:
      return ;
  }
}

function string_of_shirtSize(src) {
  if (typeof src !== "number") {
    return String(src._0) + "XL";
  }
  switch (src) {
    case /* Small */0 :
        return "Small";
    case /* Medium */1 :
        return "Medium";
    case /* Large */2 :
        return "Large";
    
  }
}

function price(src) {
  if (typeof src !== "number") {
    return 16.00 + (src._0 - 1 | 0) * 0.50;
  }
  switch (src) {
    case /* Small */0 :
        return 11.00;
    case /* Medium */1 :
        return 12.50;
    case /* Large */2 :
        return 14.00;
    
  }
}

function nicePrice(price) {
  return "The price is: $" + price.toString();
}

function displayPrice(src) {
  var result = Belt_Option.map(Belt_Option.map(shirtSize_of_string(src), price), nicePrice);
  console.log(result);
  
}

function toInt(s) {
  var result;
  try {
    result = Caml_format.caml_int_of_string(s);
  }
  catch (raw_exn){
    var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
    if (exn.RE_EXN_ID === "Failure") {
      if (exn._1 === "int_of_string") {
        return ;
      }
      throw exn;
    }
    throw exn;
  }
  return result;
}

function toFloat(s) {
  var result;
  try {
    result = Caml_format.caml_float_of_string(s);
  }
  catch (raw_exn){
    var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
    if (exn.RE_EXN_ID === "Failure") {
      if (exn._1 === "float_of_string") {
        return ;
      }
      throw exn;
    }
    throw exn;
  }
  return result;
}

function toFixed(prim, prim$1) {
  return prim.toFixed(prim$1);
}

exports.shirtSize_of_string = shirtSize_of_string;
exports.string_of_shirtSize = string_of_shirtSize;
exports.price = price;
exports.nicePrice = nicePrice;
exports.displayPrice = displayPrice;
exports.toInt = toInt;
exports.toFloat = toFloat;
exports.toFixed = toFixed;
/* No side effect */
