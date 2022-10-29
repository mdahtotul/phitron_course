#include <stdio.h>

int main()
{
    int x,a,b;
    printf("Value of x ~ ");
    scanf("%d", &x);

    printf("Value of a ~ ");
    scanf("%d", &a);

    printf("Value of b ~ ");
    scanf("%d", &b);

    if(x%2==0){
        printf("x is even. So, a + b = %d", a+b);
    }else{
        printf("x is odd. So, a - b = %d", a-b);
    }
    return 0;
}
