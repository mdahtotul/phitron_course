#include <stdio.h>


int main()
{
  int min1, min2, i, n=7, a[n];

  printf("Provide %d numbers to find the second smallest number:\n", n);
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
  }

  if(a[0] < a[1])
  {
    min1 = a[0];
    min2 = a[1];
  }
  else
  {
    min1 = a[1];
    min2 = a[0];
  }

  for (i = 2; i < n; i++){
    if(a[i] < min1) {
      min2 = min1;
      min1 = a[i];
    }else if(a[i] < min2 && a[i] > min1) {
      min2 = a[i];
    }
    
  }
  printf("The second smallest element is %d", min2);

  return 0;
}
