module D = Webapi.Dom;
module Doc = Webapi.Dom.Document;
module Elem = Webapi.Dom.Element;

let getValue = (element: option(Dom.element)) : option(string) => {
    element -> Belt.Option.map(_, Elem.unsafeAsHtmlElement) -> Belt.Option.map(_, D.HtmlElement.value)
}

let toInt = (s:string): option(int) => {
    switch(int_of_string(s)) {
        | result => Some(result)
        | exception(Failure("int_of_string")) => None
    }
}

let toFloat = (s:string): option(float) => {
    switch(float_of_string(s)) {
        | result => Some(result)
        | exception(Failure("float_of_string")) => None
    }
}

let payment = (~principal:float, ~apr, ~years, ()) => {
    let r = apr /. 12.0 /. 100.0
    let n = float_of_int(years * 12)
    let powerTerm = (1.0 +. r) ** n
    principal *. (r *. powerTerm) /. (powerTerm -. 1.0)
}

let calculatePayments = (_:Dom.event) : unit => {
    Js.log("in calculatePayments!")
    let p = getValue(Doc.getElementById("principal", D.document)) -> Belt.Option.flatMap(_, toFloat)
    let a = getValue(Doc.getElementById("apr", D.document)) -> Belt.Option.flatMap(_, toFloat)
    let y = getValue(Doc.getElementById("years", D.document)) -> Belt.Option.flatMap(_, toInt)
    let r = switch(p, a, y) {
        | (Some(z), Some(x), Some(w)) => payment(~principal=z, ~apr=x, ~years=w, ())
        | (_,_,_) => -1.0
    }
    let s = Js.Float.toString(r)
    let _ = Doc.getElementById("payment", D.document) -> Belt.Option.map(_, Elem.setInnerText(_, s));
}

let addOnChange = (dst:option(Elem.t)) : unit => {
    Js.log("in addOnChange")
    switch(dst) {
        | Some(x) => D.EventTarget.addEventListener("onchange", calculatePayments, Elem.asEventTarget(x))
        | None => ()
    }
}

let principal = Doc.getElementById("principal", D.document)
let apr = Doc.getElementById("apr", D.document)
let years = Doc.getElementById("years", D.document)
let button = Doc.getElementById("docalc", D.document)
Js.log("here")
addOnChange(principal)
addOnChange(apr)
addOnChange(years)
switch(button) {
    | Some(b) => D.EventTarget.addEventListener("click", calculatePayments, Elem.asEventTarget(b))
    | None => ()
}
