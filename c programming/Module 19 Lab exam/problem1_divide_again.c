#include <stdio.h>

int main()
{
    long long int N, amount=-1;
    scanf("%lld", &N);

    if(N % 3 == 0)
    {
        amount = N/3;
    }

    printf("%lld", amount);

    return 0;
}
