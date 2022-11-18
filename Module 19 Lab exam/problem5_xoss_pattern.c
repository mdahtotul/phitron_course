#include <stdio.h>

int main()
{
    int N, i=0, j=0;
    scanf("%d", &N);

    for(i=1; i<=N; i++)
    {
        if(i == 1)
        {
            for(j=1; j<=N; j++)
                printf("%d", j);
        }
        else if (i == N)
        {
            for(j=1; j<=N; j++)
                printf("%d", N);
        }
        else if (i != 1 && i != N)
        {
            printf("%d", i);

            for(j=1; j<=N-2;j++)
            {
               printf(" ");
            }
            printf("%d", N);
        }
        printf("\n");


    }
    return 0;
}
