#include <stdio.h>

int main()
{
  int N = 12, i, j;

  for(i = 1; i <= N; i++){
    printf("#");
  }
  printf("\n");

  for (i = 1; i <= N - 2; i++){
    printf("#");
    for (j = 1; j <= N - 2; j++){
      printf(" ");
    }
    printf("#");
    printf("\n");
  }

  for (i = 1; i <= N; i++)
  {
    printf("#");
  }

  return 0;
}