#include <stdio.h>

int main()
{
   long long int N, hand_shakes;
   scanf("%lld", &N);

   hand_shakes = (N*(N-1))/2;

   printf("%lld", hand_shakes);

   return 0;
}
