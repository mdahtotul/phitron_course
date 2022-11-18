#include<stdio.h>
int main()
{
    int array[2][3]= {{10,20,30},{40,50,60}},i=1,j=0;
    array[i][j]=array[j][i];
    printf("%d,%d",array[i][j],array[j+1][i+1]);

    return 0;
}
