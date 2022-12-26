#include<stdio.h>

int main()
{

    int num,max,min;
    
    scanf("%d ", &num);
    max=min=num;

    for(int i=0; i<3; i++)
    {
        scanf("%d", &num);
        if(max<num)
            max=num;
        else if(min>num)
            min=num;

    }
    printf("Largest = %d\nSmallest = %d", max, min);
    return 0;

}
