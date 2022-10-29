#include <stdio.h>

int main()
{
    int a, b, temp, gcd, x, y;
    scanf("%d %d", &a, &b);
    x=a;
    y=b;

    if(b > a){
        temp= a;
        a = b;
        b = temp;
    }

    while(b>0){
        temp = a;
        a=b;
        b = temp%b;
        gcd = a;
    }
    printf("The GCD of %d and %d is %d", x, y, gcd);
    return 0;
}
