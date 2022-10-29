#include <stdio.h>

//Write a C program to take one positive integer N as input and print all even numbers from 1 to N.
int main()
{
    int N, i;
    scanf("%d", &N);

    for(i=2;i<=N;i+=2)
    {
        printf("%d ", i);
    }
    return 0;
}
