function foo(arg-> x, y, z: int; arg-> f: real): void
{
    if (x > y) 
    {
        x = x + y;
    }
    else
    {
        y = x + y + z;
        z = y * 2;
        f = z;
    }
}

function goo(): char
{
    return 'a';
}
