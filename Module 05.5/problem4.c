#include <stdio.h>

// Write a C program to take one positive integer N as input and print all divisors of N.

int main()
{
    int N,i=1;
    scanf("%d", &N);

    for(i;i<=N;i++)
    {
        if(N%i==0){
            printf("%d ", i);
        }
    }

    return 0;
}
