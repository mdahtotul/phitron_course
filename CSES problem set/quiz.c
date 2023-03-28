#include<stdio.h>
int main()
{
    int a=0,i=0;
    printf("4");
    for (i=0; i<5; i++)
    {
        a+=1;
        if (i==3)
            break;
    }
    printf("%d\n",a);
    return 0;
}
