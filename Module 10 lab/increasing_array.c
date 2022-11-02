#include <stdio.h>

int main()
{
  int n, i, move=0;
  scanf("%d ", &n);

  int arr[200003];
  for (i = 0; i < n; i++)
  {
    scanf("%d ", &arr[i]);
  }

  for (i = 1; i < n; i++)
  {
    if(arr[i] < arr[i-1]){
      move += (arr[i-1] - arr[i]);
      arr[i] = arr[i-1];
    }
  }

  printf("%d", move);

  return 0;
}