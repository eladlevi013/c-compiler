1)
function main():void
{}

function main():void
{}

2)
function foo1(arg-> x:int):int
{
    var x:int;
    return 0;
}

3)
function foo1(arg-> x:int):int
{
  return 0;
}

function main():void
{
  var y:char;
  var x:real;
  var c:int;
  foo1(c,y,x);
}

4)
function main():void
{
    string str[5] = "kobi1";
    var x=str:int;
}

5)
function main():void
{
    string str[5] = "itamar1";
    var x = str:int;
    if(x=5)
    {
      str = "tamir";
    }
}

6)
function goo():char
{}

function goo(): int
{}

7)
function main(): void {
  foo2(x);
}

8)
function goo(arg-> x:int; arg-> y:real; arg-> f:real):int
{
  return 1;
}

function main():void
{
  var x,y:int;
  var z:int*;
  goo(x,y,z);
}

9)
function goo(arg-> x:int;arg-> y:real;arg-> f:real):int
{
  return 'd';
}

10)
function main() : void
{
  var x=0:int;
  while(x+5)
  {
    x=x+1;
  }
}

11)
function main() : void
{
  string x[5] = "elad";
  x['m'] = 'l';
}

12)
function main() : void 
{
  var x:int;
  x[3] = 'l';
}

13)
function main() : void
{
  var x :int*;
  var y: bool;
  x = &y;
}

14)
function main(arg-> x,y:int;arg-> f:real): void 
{

}

15)
function main():void
{
  y();
}













































1)
function main(): void
{
  var b:int;
  b = 5;
}

function main():void
{
  var a:int;
  a = 4;
}

2)
function main(arg-> x:int):int
{
  var b:int;
  b = 5;
  return 0;
}

3)
function foo():int{
  function goo(arg-> x, y:int):void
  {
    x = x + y;
  }
  function goo(arg-> c:char):char
  {
     c = 'f';
    return c;
  }
  return 1;
}

function foo():real
{
  return 3.15;
}

function main():void {}

4)
function foo(arg-> y:char):int
{
  var x, y:int;
  var x:char;
  return 1; 
}
function main():void {}

5)
function foo(arg->y:char):int
{
  function goo():char
  { 
    return 'c';
  }
  return 1;
}

function main():void{
  foo();
  foo('c');
  goo();
  foo1();
}

6)
function foo(arg-> y:char):int
{
  var p:int*;
  *p = t;
  t = 5;
  y = 'f';
  return 1;
}
function main():void {}

7)
function foo(arg-> x, y:int;arg-> z:char): int
{
  return 1;
}

function main():void
{
  foo();
  foo(2, 3);
  foo(2, 3, 't');
}

8)
function foo(arg->x, y:int*;arg-> z:real*):int
{
  return 1;
}

function main():void{
  var r, t:int;
  var q:real;
  foo(&r, &t, &q);
  foo(r, t, q);
}

9)
function foo(arg->x:int;arg-> y:char):int
{
  if (x > 5)
  {
    return x;
  }
  if(y == 'g')
  {
    return y;
  }
  return 3.5;
}

function goo():char* 
{
  return "hello";
}

function main():void {}

10)
function foo(arg->x:int ;arg->y:char):int
{
  return 3;
}

function goo(): int*
{
  var x:int*;
  *x = 5;
  return x;
}

function main():void{
  var x:int;
  var y:char;
  var ptr:int*;
  x = foo(x, '$');
  y = foo(x, '$');
  x = goo();
  ptr = goo();
}

11)
function main():void{
  var x:int;
  var y = true:bool;
  if(x > 5)
  {
    x = 4;
  }
  if(y)
  {
    if(x + 3)
    {
      x = 6;
    }
  }
  if (false)
    y = false;
  if('g')
  {
    x = 4;
  }
}

12)
function main():void{
  var x = 3:int; 
  var y = true:bool; 
  while (y){
    x = 4;
  }

  while (x == 4){
    x = 4;
  }
  while (true && y)
    y = false;
  while ('g'){
    x = 4;
  }
  while(5 + x)
  {
    y = true;
  }
}

12b)
function main():void{
  var x = 3:int;
  var y = true:bool;
  do {
    x = 4;
  } while (y);
  do {
    x = 4;
  } while (x == 4);
  do{
    y = false; 
  } while (true && y);
  do {
    x = 4;
  } while ('g');

  do{
    y = true;
  } while(5 + x);
}

12c.
function main():void{
  var i:int;
  var x = 0:int;
  var y = true:bool;
  for(i = 0; i < 10;i = i + 1){
    x = x + 5;
  }

  for (i = 'f';i < 10;i = i + 1)
  {
    x = x + 6;
  }

  for (i = 0; i ;i = i + 1){
    x = x + 7;
  }

  for(i=0;i< 10;i = y)
  {
    x = x + 8;
  }

  for (i = 0;i < 10 && y || false; i = i + 1)
  {
    x = x + 5;
  }
}

13)
function main(): void
{
  string s[10];
  string s1['d'];
  var x = 2:int;
  var y = 'd':char;
  s[x] = 'g';
  s[x + 5] = y;
  s[y] = 'v';
  s[3.5] = 'z';
  s[4] = s['d'];
  s[2] = s[3];
}

14)
function main(): void
{
  string s[10];
  var x=2:int;
  var y:real*;
  s[x] = 'g';
  x[4] = 4;
  y[x] = 'r';
}

15)
function main(): void
{
  string s[10];
  var x = 2:int;
  var r = 3.5:real;
  var y = null:real*;
  var z = 2:bool;
  var z1 = true:bool;
  s[x] = 'g';
  s[4] = 4;
  z1 = 3.15;
  x = null;
  *y = 3.5;
  y = &r;
  y = null;
  y = &z1;
}

16)
function main(): void
{
  var x = 2:int;
  var r = 3.5:real;
  var c = 'g':char;
  x = x + 1;
  r = 3.15 - x;
  r = c * 8;
  x = c / 2;
}

16)
function main(): void
{
  var x = 2:int;
  var r= true:bool;
  r = (r == false) && (x > 4);
  r = (x || 4);
}


16)
function main(): void
{
  var x = 2:int;
  var y = 3.5:real;
  var r = true:bool;
  r = x > 2;
  r = 5<9;
  r = (x <= y);
  r = (r >= false);
}

16)
function main(): void
{
  var x = 2:int;
  string s[10]= "hello";
  var y = null:int*;
  var r = true:bool;
  r = x == 2;
  r = 5 != 9;
  r = s[1] == s[5];
  r = x == true;
  r = y != x;
  r = *y == x;
}

16)
function main(): void
{
  var x = 2:int;
  string s[10]= "hello";
  var y:int*;
  var r= true:bool;
  x = |s|;
  r = |s|;
  *y = |s| + 5;
  r = true;
  r = !x;
}

17)
function main(): void
{
  var x = 2:int;
  var y = null:real*;
  var t = null:char*;
  y = y - x;
  t= t + 2 + 3;
  t = t - 3.5;
  y = y * x;
}

18)
function main():void
{
  var x = 2:int;
  var y = null:int;
  string s[10] = "hello";
  var p:char*;
  p = &s[5];
  y = &x;
  s[4] = &y;
  p = &s;
}

19)
function main(): void
{
  var x:int;
  var y:int*;
  var t:char*;
  var z:char;
  *y = 9;
  x = *z;
  y = *(x - 5);
  *t = 'y';
  x = *(y - 5);
}
