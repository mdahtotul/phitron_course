#include <stdio.h>

int main()
{

    int n,x=0,sum = 0;

    printf("Find summation from 1 to ");
    scanf("%d", &x);

    for(n=1; n<=x; n++)
    {
        printf("%d square = %d\n",n, n*n);
        sum += n;
    }
        printf("Sum = %d", sum);
}
