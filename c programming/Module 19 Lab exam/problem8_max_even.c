#include <stdio.h>

int main()
{
    int N, i, e_max1=0, e_max2=0, o_max1=0, o_max2=0, e_sum=0, o_sum=0;
    scanf("%d", &N);

    int a[20];
    for(i=0; i<N; i++)
    {
        scanf("%d ", &a[i]);
    }

    for(i=0; i<N; i++)
    {
        if(a[i] > e_max1 && a[i]%2 == 0)
        {
            e_max1 = a[i];
        }
        if(a[i] > o_max1 && a[i]%2 == 1)
        {
            o_max1 = a[i];
        }

    }


    for(i=0; i<N; i++)
    {
        if(e_max2<a[i] && a[i] != e_max1 && a[i]%2==0)
        {
            e_max2 = a[i];
        }
        else if(o_max2<a[i] && a[i] != o_max1 && a[i]%2==1)
        {
            o_max2 = a[i];
        }

    }

    e_sum = e_max1 + e_max2;
    o_sum = o_max1 + o_max2;

    /*
    if (e_sum < e_max1 && e_max1 > o_max1)
        printf("%d", e_max1);
    else if (o_sum < o_max1 && o_max1 > e_max1)
        printf("%d", o_max1);
    */
    if(e_sum >= o_sum)
        printf("%d", e_sum);
    else
        printf("%d", o_sum);


    return 0;
}
