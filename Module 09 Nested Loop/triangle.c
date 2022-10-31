#include <stdio.h>

int main()
{
  int N = 10, i, j;

  for (i = 1; i <= N;i++){
    for (j = 1; j <= i;j++){
      printf("*");
    }
    printf("\n");
  }

    return 0;
}