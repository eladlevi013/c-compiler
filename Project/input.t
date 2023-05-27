function foo() : int
{
    function goo(arg-> x,y:int) : void
    {
        x=x+y;
    }
    function goo(arg-> c:char): char
    {
        c = 5;
        return c;
    }
    return 1;
}
function foo() : real
{
    return 3.14;
}
function main(): void
{

}