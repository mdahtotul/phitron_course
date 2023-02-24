#include <bits/stdc++.h>
using namespace std;

void print( deque<int> d ) {
   for( int i=0; i<d.size(); i++ ) {
      cout<<d[i]<<" ";
   }
   cout<<"\n";
}

void _sort( int arr[],int n,int maxx ) {
   int frq[maxx];
   for(int i=0; i<=maxx; i++) {
      frq[i] = 0;
   }
   for(int i=0; i<n; i++)
      frq[arr[i]] = 1;

   deque<int> dq;
   for(int i=0; i<=maxx; i++) {
      if(frq[i] > 0)
         dq.push_back(i);
   }

   print(dq);
}

int main() {
   int n;
   cin>>n;

   int a[n];
   int Inf = numeric_limits<int>::infinity();
   int maxx = Inf*-1;
   for( int i=0; i<n; i++ ) {
      int val;
      cin>>val;
      a[i] = val;
      if( maxx < val )
         maxx = val;
   }

   _sort( a, n, maxx );
   return 0;
}
