#include <stdio.h>

int main()
{
  int N, i, j, arr[N];
  scanf("%d", &N);

  for ( i = 0; i < N; i++)
  {
    scanf("%d ", &arr[i]);
  }

  // for (i = 0; i < N; i++){
  //   for(j = i+1; j < N; j++){
  //     if(arr[i] > arr[j]){
  //       int temp = arr[i];
  //       arr[i] = arr[j];
  //       arr[j] = temp;
  //       printf("1st %d , 2nd %d \n", arr[i], arr[j]);
  //     }
  //   }
  // }

  return 0;
}
