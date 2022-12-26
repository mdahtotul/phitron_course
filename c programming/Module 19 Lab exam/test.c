#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n+5],even[n],odd[n];

    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(a[j] > a[j-1])
            {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }

    int p=0;
    for(int i=0; i<n; i++)
    {
        if(a[i] % 2 == 0)
        {
            even[p] = a[i];
            p++;
        }
    }

    int q=0;
    for(int i=0; i<n; i++)
    {
        if(a[i] % 2 != 0)
        {
            odd[q] = a[i];
            q++;
        }
    }

    int x=0,y=0;
    x = even[0];
    for(int i=1; i<p; i++)
    {
        if(even[i] != x)
        {
            y = even[i];
            break;
        }
    }

    int s=0,r=0;

    if(q > 1)
    {

        s = odd[0];
        for(int i=1; i<q; i++)
        {
            if(odd[i] != s)
            {
                r = odd[i];
                break;
            }
        }
    }
    printf("%d %d %d %d", x, y, s, r);

    int ans1 = (x+y);
    int ans2 = (s+r);

    if( ans1 >= ans2 )
    {
        printf("%d\n",ans1);
    }

    else printf("%d\n",ans2);


    return 0;
}
