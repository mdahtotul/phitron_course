#include <bits/stdc++.h>

using namespace std;



int called = 0;
int save[100];

int improve_fib(int n)
{
   // Time complexity O(n);
   // Memory complexity O(n);
   if(n==0) return 0;
   if(n==1) return 1;
   if(save[n]!= 0)
      return save[n];

   int x = improve_fib(n-1);
   called++;
   int y = improve_fib(n-2);
   called++;
   save[n] = x+y;
   return x+y;
}
/*
int fib(int n)
{
   // Time complexity O(2^n);
   // Memory complexity O(n);
   if(n==0) return 0;
   if(n==1) return 1;

   int x = fib(n-1);
   called++;
   int y = fib(n-2);
   called++;
   return x+y;
}
*/

int main()
{
   int n;
   cin>>n;
   //cout<<"Fib = "<<fib(n)<<"\n";
   cout<<"Fib = "<<improve_fib(n)<<"\n";
   cout<<"Called = "<<called<<"\n";
   return 0;
}
