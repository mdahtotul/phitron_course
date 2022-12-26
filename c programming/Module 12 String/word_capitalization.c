#include <stdio.h>
#include <string.h>

int main()
{
   int i;
   char w[1000];

   fgets(w, sizeof(w), stdin);

   if(w[0] >= 'a' && w[0] <= 'z')
   {
      w[0] -= 32;
   }

   puts(w);
   return 0;
}
