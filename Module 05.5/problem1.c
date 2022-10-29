#include <stdio.h>

// Write a C program to take one integer N as input and print from 1 to N.
int main()
{
    int N,i;

    scanf("%d", &N);
    if (N < 0)
    {
        for(i=1;i>=N;i--){
            printf("%d ", i);
        }
    }
    else
    {
        for(i=1;i<=N;i++){
            printf("%d ", i);
        }
    }


    return 0;
}
