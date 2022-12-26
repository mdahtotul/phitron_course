#include <stdio.h>

int main()
{
    int a, b, temp, gcd, x, y, lcm;
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

    lcm = (x*y) / gcd;
    printf("The LCM of %d and %d is %d", x, y, lcm);
    return 0;
}
