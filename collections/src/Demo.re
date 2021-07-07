let myShirt = ShirtSize.XLarge(1)

let myPrice = ShirtSize.price(myShirt)

Js.log2("Price: ", ShirtSize.toFixed(myPrice, ~digits=2));
