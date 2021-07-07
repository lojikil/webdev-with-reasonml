
type shirtSize =
    | Small
    | Medium
    | Large
    | XLarge(int)

type t = shirtSize

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

let toFixed = Js.Float.toFixedWithPrecision
