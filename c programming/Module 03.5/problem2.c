#include <stdio.h>

int main()
{
    int a,b,c;
    printf("Provide three numbers.\n");
    printf("Number A ~ ");
    scanf("%d", &a);

    printf("Number B ~ ");
    scanf("%d", &b);

    printf("Number C ~ ");
    scanf("%d", &c);

    if(a > b && a > c){
        printf("A is bigger.");
    }else if(b > a && b > c){
        printf("B is bigger.");
    }else if(c > a && c > b){
        printf("C is bigger.");
    }else if(a == b && a > c && b > c){
        printf("A and B both are bigger.");
    }else if(a == c && a > b && c > b){
        printf("A and C both are bigger.");
    }else if(b == c && b > a && c > a){
        printf("B and C both are bigger.");
    }

    return 0;

}
