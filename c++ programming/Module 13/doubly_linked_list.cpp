#include <bits/stdc++.h>
using namespace std;

class node {
public:
   int data;
   node *prv;
   node *nxt;
};

class LinkedList {
public:
   node * tail;
   node * head;
   int sz;

   LinkedList()
   {
      tail = NULL;
      head = NULL;
      sz=0;
   }

   void CreateDoublyLL(int val)
   {
      node *newNode = new node;
      newNode->data = val;
      newNode->nxt = NULL;
      newNode->prv = NULL;
      return newNode;
   }
};

int main()
{
   return 0;
}
