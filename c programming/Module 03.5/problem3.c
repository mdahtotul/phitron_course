#include <stdio.h>

int main()
{
    int a;

    printf("Provide number to check even or odd");
    printf("Value ~ ");
    scanf("%d", &a);

    if(a%2==0){
        printf("%d is even number", a);
    }else {
        printf("%d is odd number", a);
    }

    return 0;
}
