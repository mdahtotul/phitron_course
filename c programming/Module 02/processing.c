#include <stdio.h>

int main()
{
    int a, b;

    printf("Enter first number ~ ");
    scanf("%d", &a);

    printf("Enter second number ~ ");
    scanf("%d", &b);

    int sum;
    sum = a + b;
    printf("The sum of two number is %d ", sum);

    return 0;
}
