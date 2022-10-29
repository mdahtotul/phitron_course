#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    while(n > 1)
    {
        printf("=>%d\n",n);
        if(n%2==0){
            n=n/2;
        }else {
            n=3*n+1;
        }
    }
    printf("==>%d Loop ending condition matched \n",n);
    return 0;
}
