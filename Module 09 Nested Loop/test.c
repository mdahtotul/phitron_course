#include<stdio.h>
int main()
{
    char arr[2]= {'a','b'},i,j;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%c",arr[j]);
        }
        char ch=arr[0];
        arr[0]=arr[1];
        arr[1]=ch;
    }
    return 0;
}