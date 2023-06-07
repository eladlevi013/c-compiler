function foo(arg-> x:int; arg-> a:real; arg-> b:char): int
{
  return 5;
}


function main():void{
  string s[10];
  var x = 0:int;
    var y= 3.14 :real;
   var z = 'z':char;
  x = foo(x,y,z);
}