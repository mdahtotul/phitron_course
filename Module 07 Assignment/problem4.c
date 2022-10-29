#include <stdio.h>


int main()
{
    long long int n, x = 0;
    scanf("%lld", &n);

    while(n>0){
        int mod_val = n%10;
        n= n/10;

        x = x + mod_val;
    }

    printf("%d digits", x);

    return 0;
}
