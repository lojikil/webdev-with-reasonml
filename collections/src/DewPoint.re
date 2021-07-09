
let relative_humidity = ((temp:float, humidity:float)) : float => {
    temp -. ((100.0 -. humidity) /. 5.0)
}

let arrayTake = (src, n) => {
    switch(src) {
        | _ when (n <= Belt.Array.length(src)) => Some(Belt.Array.slice(src, ~offset=0, ~len=n))
        | _ => None
    }
}

let arrayDrop = (src, n) => {
    switch(src) {
        | _ when (n <= Belt.Array.length(src)) => Some(Belt.Array.slice(src, ~offset=n, ~len=-1))
        | _ => None
    }
}

let arraySplitAt = (src, n) => {
    switch(src) {
        | _ when (n <= Belt.Array.length(src)) => Some((Belt.Array.slice(src, ~offset=0, ~len=n), Belt.Array.slice(src, ~offset=n, ~len=-1)))
        | _ => None
    }
}

let h = (3.0, 55.7)
let g = (39.0, 70.0)

Js.log(relative_humidity(h))
Js.log(relative_humidity(g))

let f = [|(3.0, 55.7), (39.0, 70.0), (33.0, 90.0)|]
let j = Belt.Array.map(f, relative_humidity)

Js.log(j)

let dpmin = Belt.Array.reduce(j, 0.0, min)
let dpmax = Belt.Array.reduce(j, 0.0, max)
let dpavg = Belt.Array.reduce(j, 0.0, (x, y) => x +. y) /. float_of_int(Belt.Array.length(f))

Js.log2("minimum dew point:", dpmin)
Js.log2("maximum dew point:", dpmax)
Js.log2("average dew point:", dpavg)
