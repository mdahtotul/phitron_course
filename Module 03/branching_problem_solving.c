#include <stdio.h>

int main()
{
    int melon;
    printf("Please enter the wait of the melon ~ ");
    scanf("%d", &melon);
    if (melon%2 == 0 && melon!= 2){
        printf("Possible");
    }else{
        printf("Impossible");
    }

    return 0;
}
