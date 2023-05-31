#include <bits/stdc++.h>
using namespace std;

void print(list<int> l)
{
   list<int>::iterator a = l.begin();
   // auto a = l.begin();
   while(a != l.end())
   {
      cout<<*a<<" ";
      a++;
   }
   cout<<"\n";
}

void InsertAtAnyIndex(list<int>&l, int idx, int val){
   auto it = l.begin();
   advance(it, idx);
   l.insert(it, val);
   cout<<"\nInserted at index -> "<<idx<<" value-> "<<val<<"\n";
}

void DeleteAtAnyIndex(list<int>&l, int idx){
   auto it = l.begin();
   advance(it, idx);
   l.erase(it);
   cout<<"\nDeleted index -> "<<idx<<"\n";
}

int main()
{
   list<int> l;

   l.push_front(10);
   l.push_front(20);
   l.push_front(30);
   cout<<"First print\n";
   print(l);
   l.push_back(60);
   l.push_back(50);
   l.push_back(90);
   cout<<"Second print\n";
   print(l);

   cout<<"pop back\n";
   l.pop_back();
   print(l);

   cout<<"pop front\n";
   l.pop_front();
   print(l);

   InsertAtAnyIndex(l, 2, 100);
   print(l);

   DeleteAtAnyIndex(l, 1);
   print(l);
   return 0;
}
