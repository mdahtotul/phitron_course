#include <stdio.h>

int main()
{
    int x,y;
    printf("Please enete two inputs ~ ");
    scanf("%d %d", &x, &y);
    if(x > y){
        printf("x is large!");
    }else if (x < y){
        printf("y is large!");
    }else{
        printf("Both are equal.");
    }
}
