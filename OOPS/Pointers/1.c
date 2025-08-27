#include <stdio.h>
// 1. Write a program that will have an integer variable and a pointer (say, p) pointing to it. Also have a
// pointer to pointer pointing to p. Take the value for the integer variable and print it using p, and pp.
int main()
{
    int x;
    int *p;
    int **pp;

    p = &x;
    pp = &p;
    
    printf("Enter an integer: ");
    scanf("%d", &x);

    printf("Value using pointer p: %d\n", *p);
    printf("Value using pointer to pointer pp: %d\n", **pp);
    return 0;
}