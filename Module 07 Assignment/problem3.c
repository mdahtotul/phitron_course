#include <stdio.h>


int main()
{
    long long int n, x = 0;
    scanf("%lld", &n);

    while(n>0){
        n= n/10;
        x++;
    }

    printf("%d digits", x);

    return 0;
}
