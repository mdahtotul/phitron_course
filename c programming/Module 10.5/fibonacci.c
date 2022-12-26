#include <stdio.h>

int main()
{
  int N, i, arr[N];
  scanf("%d ", &N);

  arr[1] = 0;
  arr[2] = 1;
  for (i = 1; i <= N; i++){
    arr[i+2] = arr[i+1] + arr[i];
  }

  for (i = 1; i <= N; i++){
    printf("%d ", arr[i]);
  }

    return 0;
}