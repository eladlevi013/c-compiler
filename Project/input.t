function foo(arg-> x: real): int{
 var a, b: int;
a = 23;
if (a == 23)
b = 10;
else
b = 19;
return b + a+5+6;
}
function main(): void {
var a, b: int;
a = 0;
while(a < 10) {
b = foo(3.14);
a = a + b;
}
}