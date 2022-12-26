#include <stdio.h>

int main()
{
   char name[100];

   fgets(name, sizeof(name), stdin); // alt version of gets and scanf

   for( int i=0; name[i]!= '\0'; i++)
   {
      if(name[i]>='a' && name[i]<='z')
         name[i] -= 32;
   }

   puts(name); // alt version of printf
   return 0;
}
