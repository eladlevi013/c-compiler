function foo():int{
	function goo(arg-> x, y:int):void{
		x = x + y;
	}

	function goo1(arg-> c:char):char{
    c = 'f';
		return c;
	}

	return 1;
}

function foo1():real
{
  return 3.141;
}

function main():void{}