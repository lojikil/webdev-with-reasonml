let rec isPalindrome = (s:string) : bool => {
    let len = Js.String.length(s)
    if(len <= 1) {
        true
    } else if (Js.String.get(s, 0) != Js.String.get(s, len - 1)) {
        false
    } else {
        isPalindrome(Js.String.slice(~from=1, ~to_=len - 1, s))
    }
}

/*

// Ah, apparently you can't match partitions of a string
// like you can with lists; I was thinking that you could do
// | x ++ ... ++ x => 
// with lists you can do:
// | [x, ..., x] it looks like
let rec isPalindromeMatch = (s:string) : bool => {

}
*/

Js.log(Belt.Array.map([|"civic", "deed", "runner"|], isPalindrome))

let rec sumUntilNegative = (items:list(int), total:int):int => {
    switch(items) {
        | [] => total
        | [x, ..._] when x < 0 => total
        | [x, ...xs] => sumUntilNegative(xs, total + x)
    }
}

// this is pretty interesting syntax; you can only use `fun` for
// single argument matching, but it can match tuples, so you can
// simply turn your arguments into a tuple to be passed in
let rec sumUntilNegative2 = fun
    | ([], total) => total
    | ([x, ..._], total) when x < 0 => total
    | ([x, ...xs], total) => sumUntilNegative2((xs, total + x));

Js.log(sumUntilNegative([1,2,3,4,5], 0));
Js.log(sumUntilNegative2(([1,2,3,4,5], 0)));

let rec myTakeWhile = (src:list('a), f:('a => bool)): list('a) => {
    switch(src) {
        | [] => []
        | [x, ...xs] when f(x) => Belt.List.concat([x], myTakeWhile(xs, f))
        | _ => []
    }
}

let rec myDropWhile = (src:list('a), f:('a => bool)): list('a) => {
    switch(src) {
        | [] => []
        | [x, ...xs] when f(x) => myDropWhile(xs, f)
        | _ => src
    }
}

let data = [2,6,42,5,7,20,3]
let isEven = (n) => { (n mod 2) == 0}

let taken = myTakeWhile(data, isEven)
let dropped = myDropWhile(data, isEven)
Js.log2("taken: ", taken)
Js.log2("dropped: ", dropped)
