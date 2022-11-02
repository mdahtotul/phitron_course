#include <stdio.h>

int main()
{
  int a[] = {3, 1, 9, 8, 4, 6, 7, 2};
  int N = sizeof(a) / sizeof(a[0]);
  int i, j, idx_min, temp;

  for (i = 0; i < N - 1; i++)
  {
    idx_min = i;
    for (j = i + 1; j < N; j++)
    {
      if(a[j] < a[idx_min]){
        idx_min = j;
      }
    }
    if(idx_min != i)
    {
      temp = a[i];
      a[i] = a[idx_min];
      a[idx_min] = temp;
    }
  }
   

  for(i = 0; i < N; i++){
    printf("%dth position = %d\n",i, a[i]);
  }

  return 0;
}