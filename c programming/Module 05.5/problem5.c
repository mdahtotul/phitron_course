#include <stdio.h>

// Write a C program to take two non-negative integers N and M. Here N and M represents time in hours (24 hours
// format). You need to print from N to M, if you need to start from beginning again, you can do that. See the
// sample input output for more clarification.

int main()
{
    int N,M,i;
    scanf("%d %d", &N, &M);

    if (N < M){

        for(i=N;i<=M;i++)
        {
            printf("%d ", i);
        }
    } else {

        for(i=N;i<=24+M;i++)
        {
            if(i <= 23) {
              printf("%d ", i);
            }else{
                printf("%d ", i - 24);
            }
        }
    }

    return 0;
}
