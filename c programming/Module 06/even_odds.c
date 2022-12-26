#include <stdio.h>

int main()
{
    long long int n,k,x,half;

    scanf("%lld %lld", &n, &k);

    half = n/2 + (n%2!=0);

    if(k <= half){
        x = (k * 2) - 1;
    } else {
        x = (k - half) * 2;
    }
    printf("%lld", x);

    return 0;
}
