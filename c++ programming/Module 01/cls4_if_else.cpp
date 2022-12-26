#include <bits/stdc++.h>

using namespace std;

int main()
{
   bool x = false;
   bool y = false;

   x && y ? cout<<"Both true" : x == true ? cout<<"X true" : y == true ? cout<<"Y true": cout<<"Both false";
   return 0;
}
