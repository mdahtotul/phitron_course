#include <stdio.h>

int main()
{
   int T, i, less_60 = 1, less_80 = 2, from_80 = 1;
   scanf("%d", &T);

   int arr[T];
   int time[T];
   char per;


   for(i=0; i<T; i++)
   {
      scanf("%d%c\n", &arr[i], &per);
      time[i] = 0;
   }


   for(i=0; i<T; i++)
   {
      if(arr[i] >= 0 && arr[i] <= 60){
         int charge = (60 - arr[i])*1 + (80-60)*2 + (100-80)*3;
         time[i] = charge;
      } else if(arr[i] > 60 && arr[i] <= 80 ){
         int charge = (80 - arr[i])*2 + (100-80)*3;
         time[i] = charge;
      } else if (arr[i] > 80 && arr[i] <= 100){
         int charge = (100 - arr[i])*3;
         time[i] = charge;
      }
   }

   for(i=0; i<T; i++)
   {
     printf("%d minutes\n", time[i]);
   }

   return 0;
}
