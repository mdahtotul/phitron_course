#include <bits/stdc++.h>
using namespace std;

void printList( list<int> l ) {
   list<int>::iterator ls = l.begin();
   while( ls != l.end() ) {
      cout<<*ls<<" ";
      ls++;
   }
   cout<<"\n";
}

int getValue( list<int> l, int idx ) {
   if( idx >= l.size() || idx<0 )
      return -1;
   auto ls = l.begin();
   int i=0, ans=-1;
   while( ls != l.end() && i<=idx ) {
      if( i==idx )
         ans=l.front();

      l.pop_front();
      i++;
   }
   return ans;
}

bool searchVal( list<int> l, int val) {
   bool flag = false;
   int sz = l.size();
   if( sz<0 )
      return flag;

   auto ls = l.begin();
   int i=0;
   while( ls != l.end() &&  i<sz ) {
      if( val == l.front() )
      {
         flag = true;
         break;
      }

      l.pop_front();
      i++;
   }

   return flag;
}


void deleteZero(list<int>&l, int val){
   l.remove(val);
}

int main() {
   list<int> l;
   l.push_front( 7 );
   l.push_front( 4 );
   l.push_front( 0 );
   l.push_front( 6 );
   l.push_front( 0 );
   l.push_front( 2 );
   l.push_front( 3 );

   printList( l );
   cout<<"List size -> "<<l.size()<<"\n";
   cout<<"Get value -> "<<getValue( l, 4 )<<"\n";
   cout<<"Search value -> ";
   searchVal( l, 9 ) == 1 ? cout<<"true\n" : cout<<"false\n";

   deleteZero(l, 0);
   printList(l);

   return 0;
}
