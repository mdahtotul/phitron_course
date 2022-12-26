#include <stdio.h>

int main()
{
    int x;
    printf("Enter a value ~ ");
    scanf("%d", &x);

    if(x%2==0){
        printf("%d value is an even number", x);
    }else{
        printf("%d value is an number", x);
    }
    return 0;
}
