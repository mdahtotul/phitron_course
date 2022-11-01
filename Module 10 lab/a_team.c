#include <stdio.h>

int main()
{
  int N, P, V, T, count = 0, i;

  scanf("%d", &N);

  for (i = 0; i < N; i++)
  {
    scanf("%d %d %d", &P, &V, &T);
    if (P + V + T >= 2)
    {
      count++;
    }
  }

  printf("%d\n", count);
  
  return 0;
}