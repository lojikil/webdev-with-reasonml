let c = 5.0;
let v = 20.0;
let vc = v ** 0.16;
let wc = 13.12 +. (0.6215 *. c) -. (11.37 *. vc) +. (0.3965 *. c *. vc);

Js.log("At temperature " ++ Js.Float.toString(c) ++ "c and windspeed " ++ Js.Float.toString(v) ++ "km/h,");
Js.log("the windchill is " ++ Js.Float.toString(wc));

let discount = (~price=0.0, ~discount=0.0) => {
    price -. (price *. (discount /. 100.0))
}

let fivePercentOff = discount(~discount=5.0)
let halfOff = discount(~discount=50.0)
let tenPercentOff = discount(~discount=10.0)

Js.log("Curried function discounting: 5% off $30 is: $" ++ Js.Float.toString(fivePercentOff(~price=30.0)))
