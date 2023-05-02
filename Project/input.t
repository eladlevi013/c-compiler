function foo_3(): int 
{

var x: char*;
string y[10];
var z: char;
y = "foobar";
x = &y[5]; 
z = *(x - 5); 
y = "barfoo"; 
}