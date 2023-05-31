#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
  if( n <= 2 )
    return 1;

  return fib(n - 1) + fib(n - 2);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  
  cout<<fib(3)<<endl;
  cout<<fib(5)<<endl;
  cout<<fib(7)<<endl;
  return 0;
}