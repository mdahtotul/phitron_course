#include <stdio.h>

int main()
{
  int arr[10];

  arr[0] = 3456;
  arr[1] = 456;
  arr[2] = arr[0] - arr[1];

  //arr[3] is not used so it will print garbage value
  printf("%d\n%d\n%d\n%d\n", arr[0], arr[1], arr[2], arr[3]); 

  return 0;
}