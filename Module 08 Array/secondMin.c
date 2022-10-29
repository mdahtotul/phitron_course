// find second minimum value in an array
// selection sorting
#include <stdio.h>

int main()
{
  int n=4, i,j, index_min, temp;
  int arr[] = {5, 87, 92, 57, 45};
  // for (i = 0;i < n; i++){
  //   scanf("%d", &arr[i]);
  // }

  for (i = 0; i < n -1; i++){
    index_min = i;
    for (j = i + 1; j < n; j++){
      if(arr[j]< arr[index_min]){
        index_min = j;
      }
    }

    if(index_min != i){
      temp = arr[i];
      arr[i] = index_min;
      arr[index_min] = temp;
    }
  }

  printf("Second minimum value = %d\n", arr[0]);
  return 0;
}