function goo() : int*
{
    var x:int*;
    *x = 5;
    return x;
}

function main(): void
{
    var ptr:int*;
    ptr = goo();
}