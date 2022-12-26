#include <bits/stdc++.h>

using namespace std;

string erase_first_last(string s)
{
   s.erase(s.begin());
   s.pop_back();
   return s;
}

void erase_first_last2(string &s)
{
   s.erase(s.begin());
   s.pop_back();
   cout<<<"In function s="<<s<<endl;
}

void swapp(int &x, int &y)
{
   int temp;
   temp = x;
   x = y;
   y = temp;
}

int main()
{
   string s;
   getline(cin, s);
   string ans = erase_first_last(s);
   cout<<ans<<endl;
   return 0;
}
