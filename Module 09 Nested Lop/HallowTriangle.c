#include <stdio.h>

int main()
{
  int N = 12, i, j;

    printf("*\n");
    printf("**\n");

    for (i = 1; i <= N-3; i++){
      printf("*");
      for (j = 1; j<= i; j++){
        printf(" ");
      }
      printf("*");
      printf("\n");
    }

    for(j = 1; j <= N; j++){
      printf("*");
    }

    return 0;
}