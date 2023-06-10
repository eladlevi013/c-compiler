function main():void
{
	var x:char*;
	string y[10];
	var z:char;
	
	y = "foobar";
	x = &y[5];
	z = *(x - 5);
	y = "barfoo";
	y[5] = *x;
}