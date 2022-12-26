#include <bits/stdc++.h>

using namespace std;

int x, y, z;

int func(int a, int b)
{
   return a+b;
}
namespace Info {
   int x = 10;
   int y = 5;
   int func(int a, int b)
   {
      return a*b;
   }
}

int main()
{
   cout << Info::func(Info::x, Info::y) << "\n";

   return 0;
}
