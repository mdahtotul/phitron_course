#include <bits/stdc++.h>

using namespace std;

// Memory complexity O(n);
class Array {
private:
   int *arr;
   int cap;
   int sz;

   void increase_capacity()
   {
      cap = cap * 2;
      int *tmp = new int[cap];
      for(int i=0; i<sz; i++)
         tmp[i] = arr[i];

      delete [] arr;
      arr = tmp;
   }
   void decrease_capacity()
   {
      cap = cap / 2;
      int *tmp = new int[cap];
      for(int i=0; i<sz; i++)
         tmp[i] = arr[i];

      delete [] arr;
      arr = tmp;
   }
public:
   Array()
   {
      arr = new int[1];
      cap = 1;
      sz = 0;
   }
   // Time complexity of PUSH_BACK O(1);
   void PUSH_BACK(int x)
   {
      if(cap == sz)
         increase_capacity(); // Time complexity nlogn and it is not concerned

      arr[sz] = x;
      sz++;
   }
   // Time complexity O(sz);
   void Print()
   {
      for(int i=0; i<sz; i++)
         cout<<arr[i]<<" ";

      cout<<"\n";
   }
   // Time complexity O(1);
   int GET_SIZE()
   {
      return sz;
   }
   // Time complexity O(1);
   int GET_ELEMENT(int idx)
   {
      if(idx>=sz)
      {
         cout<<"Error "<<idx<<" is out of bound\n";
         return -1;
      }
      return arr[idx];
   }
   // Time complexity O(sz)
   void INSERT(int pos, int x)
   {
      if(cap==sz)
         increase_capacity();

      for(int i=sz-1; i>=pos; i--)
      {
         arr[i+1] = arr[i];
      }
      arr[pos] = x;
      sz++;
   }

   void POP_BACK()
   {
      if(sz==0)
      {
         cout<<"Current size is 0\n";
         return;
      }
      sz--;
   }

   void ERASE(int pos)
   {
      if(pos>=sz)
      {
         cout<<"Position doesn't exist\n";
         return;
      }
      for(int i=pos+1; i<sz; i++)
         arr[i-1] = arr[i];
      sz--;
      if(sz == cap/2)
         decrease_capacity();
   }
};

int main()
{
   Array a;
   a.PUSH_BACK(10);
   a.PUSH_BACK(20);
   a.PUSH_BACK(30);
   a.PUSH_BACK(40);
   a.PUSH_BACK(50);

   a.INSERT(1, 5);
   a.Print();

   a.POP_BACK();
   a.Print();
   a.POP_BACK();
   a.Print();
   a.ERASE(1);
   a.Print();


   cout<<a.GET_SIZE()<<"\n";

   for(int i=0; i<a.GET_SIZE(); i++)
      cout<<a.GET_ELEMENT(i)<<"\n";
   return 0;
}
