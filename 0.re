let c = 5.0;
let v = 20.0;
let vc = v ** 0.16;
let wc = 13.12 +. (0.6215 *. c) -. (11.37 *. vc) +. (0.3965 *. c *. vc);

Js.log("At temperature " ++ Js.Float.toString(c) ++ "c and windspeed " ++ Js.Float.toString(v) ++ "km/h,");
Js.log("the windchill is " ++ Js.Float.toString(wc));

// Chapter 2
let discount = (~price=0.0, ~discount=0.0) => {
    price -. (price *. (discount /. 100.0))
}

let fivePercentOff = discount(~discount=5.0)
let halfOff = discount(~discount=50.0)
let tenPercentOff = discount(~discount=10.0)

Js.log("Curried function discounting: 5% off $30 is: $" ++ Js.Float.toString(fivePercentOff(~price=30.0)))

// Chapter 3
type colorSpec =
    | White
	| Black
	| Grey(float)
	| RGB (int, int, int)

let color1 = White
let color2 = Black
let color3 = Grey(0.5)
let color4 = RGB(255,255,255)

let string_of_colorSpec = (cspec:colorSpec) : string => {
  switch(cspec) {
    | White => "white"
    | Black => "black"
    | Grey(x) => Js.Float.toString(x *. 100.0) ++ "% grey"
    | RGB(r, g, b) => "RGB(" ++ string_of_int(r) ++ ", " ++ string_of_int(g) ++ ", " ++ string_of_int(g) ++ ")"
  }
}

Js.log(string_of_colorSpec(color1))
Js.log(string_of_colorSpec(color2))
Js.log(string_of_colorSpec(color3))
Js.log(string_of_colorSpec(color4))
