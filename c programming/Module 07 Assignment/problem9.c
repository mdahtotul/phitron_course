#include <stdio.h>

int main()
{
    int i, n;
    scanf("%d", &n);

    printf("The factors of %d are: ", n);

    for(i=1;i<=n;i++){
        if(n%i==0 && i==n) {
            printf("%d.", i);
        }else if(n%i==0 && i!=n){
            printf("%d, ", i);
        }
    }

    return 0;
}
