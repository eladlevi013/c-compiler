function main():void
{
	var x:int;
	var p,t:int*;
	var r:int*;
	
	x = *p;
	*p = x;
	p = t;
	*t = *p;
}