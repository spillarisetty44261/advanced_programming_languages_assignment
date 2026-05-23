// JavaScript: Type System Demo - Implicit Coercion

// Variables have no fixed type
let x = 10;
console.log("Value:", x, "| Type:", typeof x);

x = "hello";
console.log("Value:", x, "| Type:", typeof x);

x = true;
console.log("Value:", x, "| Type:", typeof x);

// IMPLICIT COERCION - JavaScript auto-converts types
console.log("\n--- Implicit Coercion Examples ---");

// Number + String = String (number gets coerced to string)
console.log(5 + "5");        // "55" not 10

// String - Number = Number (string gets coerced to number)
console.log("10" - 3);       // 7

// Boolean + Number = Number (true = 1)
console.log(true + 1);       // 2

// Boolean + String = String
console.log(true + " story"); // "true story"

// Comparison coercion
console.log(0 == false);     // true  (loose equality coerces)
console.log(0 === false);    // false (strict equality does not coerce)