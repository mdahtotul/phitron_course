#include <stdio.h>

int main()
{
    int a[] = {12, 7, 9, 3, 15, 2, 6, 5};
    int N = sizeof(a)/sizeof(a[0]);

    int i,j, temp;

    for(i=0; i<N-1; i++)
    {
        for(j=i; j<N; j++)
        {

            if(a[j] < a[i])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    for(i=0; i<N; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

