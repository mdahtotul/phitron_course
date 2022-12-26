#include <stdio.h>

int main()
{
    int a;

    printf("Provide to total marks to find out the grade.\n");
    printf("Marks ~ ");
    scanf("%d", &a);

    if(100 >= a && a >= 80){
        printf("Grade A+");
    }else if (80 > a && a >= 70){
        printf("Grade A");
    }else if (70 > a && a >= 60){
        printf("Grade A-");
    }else if (60 > a && a >= 50){
        printf("Grade B");
    }else if (50 > a && a >= 40){
        printf("Grade C");
    }else if (40 > a && a >= 33){
        printf("Grade D");
    }else if (33 > a && a >= 0){
        printf("Grade F");
    }else {
        printf("Invalid marks. Please provide marks between 0 to 100");
    }

    return 0;
}
