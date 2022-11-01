#include <stdio.h>

int main()
{
  long long int n;
  int k, i;
  scanf("%lld %d", &n, &k);

  for (i = 1; i <= k; i++)
  {
    if(n%10 == 0){
      n /= 10;
    }else{
      n--;
    }
  }

  printf("%lld", n);

  return 0;
}