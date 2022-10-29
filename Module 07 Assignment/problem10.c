#include <stdio.h>

int main()
{
    int n, i, x=0;
    scanf("%d", &n);

    for(i=1;i<=n;i++){
        if(i!= 1 && i!=n && n%i==0) x = 1;
    }

    if(x==0){
        printf("Prime");
    }else {
        printf("Composite");
    }


    return 0;
}
