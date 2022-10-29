#include <stdio.h>

int main()
{
    int n,h,i,x,sum=0;
    scanf("%d %d", &n, &h);

    for(i=1;i<=n;i++){
        scanf("%d", &x);
        sum = sum + 1 + (x > h);
    }

    printf("%d", sum);

    return 0;
}
