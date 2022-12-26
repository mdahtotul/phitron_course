#include <stdio.h>

int main()
{
  int n, k, i, advancers=0;
  int arr[52];

  scanf("%d %d", &n, &k);

  for(i=1; i<=n; i++){
    scanf("%d", &arr[i]);
  }

  for (i=1; i <= n; i++){
    if(arr[i] > 0 && arr[i] >= arr[k]){
      advancers++;
    }
  }

  printf("%d", advancers);

  return 0;
}