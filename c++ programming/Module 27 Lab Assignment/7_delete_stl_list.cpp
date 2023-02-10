#include <bits/stdc++.h>
using namespace std;

void printList( list<int> l ) {
   auto it = l.begin();
   while( it != l.end() ) {
      cout<<*it<<" ";
      it++;
   }
   cout<<"\n";
}

void deleteValue( list<int>&l,list<int>cl, int value ) {
   auto it = cl.begin();
   int idx = 0;
   while( it != cl.end() ) {
      if( *it == value )
         break;
      it++;
      idx++;
   }

   auto ite = l.begin();
   advance( ite, idx );
   l.erase( ite );
}

int main() {

   list<int> l;
   l.push_front( 4 );
   l.push_front( 5 );
   l.push_front( 4 );
   l.push_front( 8 );
   l.push_front( 3 );
   l.push_front( 7 );
   printList( l );
   deleteValue( l,l, 4 );
   printList( l );
   return 0;
}
