#include <stdio.h>

int main()
{
   char a[10];
	a[0] = 98;
	a[1] = 97;
	a[2] = 'n';
	a[3] = 'a';
	a[4] = 'n';
	a[5] = 'a';
	a[6] = '\0';

   for(int i=0; i<10; i++)
   {
      printf("%c", a[i]);
   }
   return 0;
}
