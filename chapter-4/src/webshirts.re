module D = Webapi.Dom;
module Doc = Webapi.Dom.Document;
module Elem = Webapi.Dom.Element;

type shirtSize =
    | Small
    | Medium
    | Large
    | XLarge(int)

let shirtSize_of_string = (src:string) : option(shirtSize) => {
    Js.log2("in shirtSize_of_string", src)
    switch(src) {
        | "Small" => Some(Small)
        | "Medium" => Some(Medium)
        | "Large" => Some(Large)
        | "XLarge" => Some(XLarge(1))
        | "XXLarge" => Some(XLarge(2))
        | "XXXLarge" => Some(XLarge(3))
        | "XXXXLarge" => Some(XLarge(4))
        | _ => None
    }
}

let string_of_shirtSize = (src:shirtSize) : string => {
    switch(src) {
        | Small => "Small"
        | Medium => "Medium"
        | Large => "Large"
        | XLarge(n) => string_of_int(n) ++ "XL"
    }
}

let price = (src:shirtSize) : float => {
    Js.log2("in price, shirt size is:", string_of_shirtSize(src))
    switch(src) {
        | Small => 11.00
        | Medium => 12.50
        | Large => 14.00
        | XLarge(n) => 16.00 +. (float_of_int(n - 1) *. 0.50)
    }
}

let nicePrice = (price:float) : string => {
    "The price is: $" ++ Js.Float.toString(price)
}

let displayPrice = (src:string) : unit => {
    let result = shirtSize_of_string(src) -> Belt.Option.map(price) -> Belt.Option.map(nicePrice)
    Js.log(result)
}

Js.log("here, found calculate!")
let calcButton = Doc.getElementById("calculate", D.document);

let getValue = (element: option(Elem.t)) : option(string) => {
    element -> Belt.Option.map(_, Elem.unsafeAsHtmlElement) -> Belt.Option.map(_, D.HtmlElement.value)
}

let toInt = (s:string): option(int) => {
    switch(int_of_string(s)) {
        | result => Some(result)
        | exception(Failure("int_of_string")) => None
    }
}

let calculater = (_: Dom.event) : unit => {
    
    Js.log("here, clicked calculate")
    let quantity = getValue(Doc.getElementById("quantity", D.document)) -> Belt.Option.flatMap(_, toInt)

    switch(quantity) {
        | Some(x) => Js.log2("quantity has value: ", string_of_int(x))
        | None => Js.log("whoa, quantity has no value")
    }

    let unitPrice = getValue(Doc.getElementById("size", D.document)) -> Belt.Option.flatMap(_, shirtSize_of_string) -> Belt.Option.map(_, price)

    switch(unitPrice) {
        | Some(x) => Js.log2("unitPrice has value: ", Js.Float.toString(x))
        | None => Js.log("whoa, unitPrice has no value")
    }

    let totalPrice = switch(unitPrice, quantity) {
        | (Some(uPrice), Some(qty)) => Some(uPrice *. float_of_int(qty))
        | (_, _) => None
    }

    switch(totalPrice) {
        | Some(x) => Js.log2("totalPrice has value: ", Js.Float.toString(x))
        | None => Js.log("whoa, totalPrice has no value")
    }

    let priceString = switch(totalPrice) {
        | Some(total) => Js.Float.toFixedWithPrecision(total, ~digits=2)
        | None => ""
    }

    /*switch(priceString) {
        | None => Js.log("whoa, quantity has no value")
        | _ => Js.log("price string isn't none")
    }*/

    let _ = Doc.getElementById("price", D.document) -> Belt.Option.map(_, Elem.setInnerText(_, priceString))
}

switch(calcButton) {
    | Some(element) => D.EventTarget.addEventListener("click", calculater, Elem.asEventTarget(element))
    | None => ()
};

