#include <stdio.h>



void foo(char* p, int x) 
{
    printf("p is \"%s\" and x is %d\n", p, x);


}

int main() 
{
    printf("Hello World!\n");
    char* a = "Hello",* b = "World!";
    printf("%s %s\n", a,b);
    foo("ccc", 10);
    foo("p", 0);



}