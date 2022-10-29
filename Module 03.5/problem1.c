#include <stdio.h>

int main()
{
    int a, b;

    printf("Provide two input to check bigger number.\n");
    printf("Number A ~ ");
    scanf("%d", &a);

    printf("Number B ~ ");
    scanf("%d", &b);

    if(a < b){
        printf("B is bigger");
    } else if (a > b){
        printf("A is bigger");
    } else {
        printf("They are equal");
    }

    return 0;
}
