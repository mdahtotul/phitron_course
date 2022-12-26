#include <stdio.h>

int main()
{
    int x;

    printf("Enter a number to know is it even or odd number ~ ");
    scanf("%d", &x);

    if(x%2 == 0){
        printf("%d is a even number", x);
    } else {
        printf("%d is a odd number", x);
    }
}
