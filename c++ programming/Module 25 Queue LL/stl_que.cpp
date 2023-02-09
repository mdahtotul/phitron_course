#include <bits/stdc++.h>
using namespace std;

int main()
{
   queue<int> q;
   q.push(5);
   q.push(10);
   q.push(15);

   cout<<"Queue size -> "<<q.size()<<"\n";
   cout<<"Is queue empty ? -> "<<q.empty()<<"\n";
   cout<<q.front()<<"\n";
   q.pop();
   cout<<q.front()<<"\n";
   q.pop();
   cout<<q.front()<<"\n";
   q.pop();
   cout<<"Is queue empty ? -> "<<q.empty()<<"\n";
   cout<<"\n\n\n";
   queue<char> q1;
   q1.push('a');
   q1.push('b');
   q1.push('c');

   cout<<"Queue size -> "<<q1.size()<<"\n";
   cout<<"Is queue empty ? -> "<<q.empty()<<"\n";
   cout<<q1.front()<<"\n";
   q1.pop();
   cout<<q1.front()<<"\n";
   q1.pop();
   cout<<q1.front()<<"\n";
   q1.pop();

   cout<<"Queue size -> "<<q1.size()<<"\n";
   cout<<"Is queue empty ? -> "<<q.empty()<<"\n";
   return 0;
}
