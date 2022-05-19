#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    string name = get_string("What's your name?\n"); // get string
    printf("hello, %s\n", name);  // print string
}
