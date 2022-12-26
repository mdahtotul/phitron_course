#include <stdio.h>

int main()
{
  int N = 7, i, j;

  for (i = 1; i <= N; i+=2){
    for (j = 1; j <= N - i;j+=2){
      printf(" ");
    }
    for (j = 1; j <= i; j++){
      printf("*");

    }
    printf("\n");
  }

    return 0;
}