#include <stdio.h>

int main()
{
  int n=5, arr[n], i, max, min;

  for (i = 0; i < n;i++)
  {
    scanf("%d", &arr[i]);
  }

  max = min = arr[0];
  for (i = 0; i < n;i++){
    if(arr[i] > max){
      max = arr[i];
    }
    if(arr[i] < min){
      min = arr[i];
    }
  }

  printf("Max = %d\nMin = %d\n", max, min);

    return 0;
}