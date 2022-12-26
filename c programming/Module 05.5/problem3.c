#include <stdio.h>

// Write a C program to 2 positive integers N and M as input and print all numbers from 1 to N that are divisible by M.
int main()
{
    int M, N, i;

    scanf("%d %d", &N, &M);

    for(i=1;i<=N;i++){
            if (i%M==0)
            {
                printf("%d ", i);
            }
    }

    return 0;
}

