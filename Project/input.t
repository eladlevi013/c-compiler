function foo(arg->x:real):int
{
	var a:int;
	a = 23;
	if(a == 23)
		a = 10;
	else 
		a = 19;
	
	return a;
}

function main():void
{
	var a,b:int;
	var x:int*;
	a = 0;
	while(a < 10)
	{
		b = foo(3.14);
		a = *(x+5);
	}
}