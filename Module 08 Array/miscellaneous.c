#include <stdio.h>

int main()
{
  int n, arr[200001], i, found;
  printf("Total no of input: ");
  scanf("%d", &n);

  for (i = 1; i < n;i++){
    scanf("%d", &found);
    arr[found] = 1;
  }

  printf("Array positions\n");
  for (i = 1; i <= n;i++){
    if(arr[i] == 0){
      printf("Missing number is %d\n", i);
      break;
    }
  }

    return 0; 
}
