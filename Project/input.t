function foo(arg-> y:char):int
{
    function goo():char
    {
        return 'c';
    }
    return 1;
}

function main():void
{
    foo();
    foo('c');
    goo();
    foo1();
}
