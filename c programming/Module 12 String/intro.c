#include <stdio.h>

// ensure null value or "/0" in string last position to avoid unwanted bug
int main()
{
   char name[15];
   // char name[15] = "ARIFUL HASAN";
   // char name[] = "ARIFUL HASAN";


   scanf("%s", name);

   printf("My name is %s", name);
   return 0;
}
