#include <stdio.h>

int main()
{
    int N, K, i, j, sum=0;
    scanf("%d %d", &N, &K);

    for(i=1;i<=N;i++)
    {
        for(j=1;j<=K;j++)
        {
            int room_num = (i*100) + j;
            sum += room_num;
        }
    }
    printf("%d", sum);

    return 0;
}
