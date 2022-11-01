#include <stdio.h>

int main()
{
    int a[105];
  int n, i, even = 0, odd = 0, imposter ;
  scanf("%d ", &n);

    for (i = 0; i < n; i++)
    {
      scanf("%d ", &a[i]);
    }

    for(i=0; i<n; i++){
      if(a[i]%2 == 0){
        even++;
      }else{
        odd++;
      }
    }

    if(even == 1){
      for(i=0; i<n; i++){
        if(a[i]%2 == 0){
          imposter = i;
        }
      }
    } else if(odd == 1) {
      for(i=0; i<n; i++){
        if(a[i]%2 == 1){
          imposter = i;
        }
      }
    }

  printf("%d", imposter+1);

  return 0;
}
