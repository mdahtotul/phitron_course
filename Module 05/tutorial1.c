#include <stdio.h>

int main()
{
    int i, n, w, sum = 0;

    printf("Total number of passengers: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        printf("Passenger %d weight ~ ", i);
        scanf("%d", &w);

        sum += w;
    }
    printf("Total weight of %d passengers is %d", n, sum);
}
