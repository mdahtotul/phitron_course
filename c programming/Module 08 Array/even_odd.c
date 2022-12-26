#include <stdio.h>

int main()
{
  int n=5, arr[n], i, c_even=0, c_odd=0;

  for (i = 0; i < n;i++){
    scanf("%d", &arr[i]);
  }

  for (i = 0; i < n;i++){
    if(arr[i] % 2 == 0){
      c_even++;
    } else {
      c_odd++;
    }
  }
  printf("Total even numbers available %d\nTotal odd numbers available %d\n", c_even, c_odd);

    return 0;
}