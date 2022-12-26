#include <stdio.h>

int main()
{
    int a,b,c;

    printf("Provide the length of 3 vertice to find out this 3 vertices will form a triangle or not.\n");
    printf("AB vertice = ");
    scanf("%d", &a);

    printf("BC vertice = ");
    scanf("%d", &b);

    printf("CA vertice = ");
    scanf("%d", &c);

    if (a > 0 && b > 0 && c > 0){

        if(a+b>c && b+c>a && c+a>b){
            printf("Yes");
        }else {
            printf("No");
        }

    }else {
        printf("All vertices must be non-negative number.");
    }


    return 0;
}
