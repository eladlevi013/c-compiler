function foo(): int
{
x = 5;
y = &x; 
x = 6; 
z = *y; /* Dereference y, and assign to z the value that y
 points to (which is 6). */
}