#include <stdio.h>

int main()
{
    int x,y;

    printf("Exam marks ~ ");
    scanf("%d", &x);

    printf("Bonus marks ~ ");
    scanf("%d", &y);

    if (x > 0 && y > 0){
        if(x + y >= 100){
            printf("Yes");
        }else {
            printf("No");
        }
    }else {
        printf("All numbers should be non-negative!");
    }

}
