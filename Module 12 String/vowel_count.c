#include <stdio.h>

int main()
{
   char str[1000];

   //gets(str);
   fgets(str, sizeof(str), stdin);

   int i, counter = 0;

   while(str[i]!='\n')
   {
      if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ){
         counter++;
      }

      i++;
   }

   printf("Total vowel = %d", counter);

   return 0;
}
