#include <iostream>

using namespace std;

int main()
{
   int x = 10;
   int *y = &x;

   cout<<x<<endl;
   cout<<*y<<endl;
   cout<<y<<endl;
   cout<<"New"<<endl;
   x=100;
   cout<<x<<endl;
   cout<<*y<<endl;
   cout<<y<<endl;
   return 0;
}
