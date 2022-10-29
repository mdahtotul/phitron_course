#include<stdio.h>
int main()
{
    int n,i,p;
    printf("enter an input :");
    scanf("%d",&n);
    p=1;
    for(i=2; i<=n/2; i++)
    {
        if(n%i == 0)
        {
            p=0;
            break;
        }
    }
    if(p == 1 && n>1)
    {
        printf("%d is prime number",n);
    }
    else
    {
        printf("%d is composite number",n);
    }
    return 0;
}
