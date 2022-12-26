#include <bits/stdc++.h>

using namespace std;

int main()
{
   // way 1
   /*
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   string s;
   getline(cin, s);
   cout<<s<<"\n";
   */

   ofstream of1, of2;
   of1.open("1.txt");
   of1<<"hello world from 1\n";

   of2.open("2.txt");
   of2<<"hello world from 2\n";

   ifstream if1, if2;
   if1.open("0.txt");
   int x;
   double y,z;
   if1 >> x >> y >>z;
   cout<<x<<" "<<y<<" "<<z<<"\n";
   of1.close();
   of2.close();
   if1.close();
   return 0;
}
