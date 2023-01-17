#include <bits/stdc++.h>
using namespace std;

class node {
public:
   int data;
   node * nxt;
};

class LinkedList {
public:
   int sz;
   node *head;
   LinkedList()
   {
      head = NULL;
      sz = 0;
   }

   node *CreateNewNode(int val)
   {
      node *newNode = new node;
      newNode->data = val;
      newNode->nxt = NULL;
      return newNode;
   }

   void InsertAtHead(int val)
   {
      sz++;
      node *newNd = CreateNewNode(val);;
      if(head == NULL)
      {
         head = newNd;
         return;
      }
      newNd->nxt = head;
      head = newNd;
   }

   void InsertAfterValue(int availableValue, int insertValue)
   {
      node *a = head;
      while(a != NULL)
      {
         if(a->data == availableValue) break;
         a = a->nxt;
      }
      if(a==NULL){
         cout<<availableValue<<" doesn't exist in linked list\n";
         return;
      }
      sz++;
      node * newNode = CreateNewNode(insertValue);
      newNode->nxt = a->nxt;
      a->nxt = newNode;
   }

   void Traverse()
   {
      node *a = head;
      cout<<"Linked List Data : ";
      while(a!=NULL)
      {
         cout<<a->data<<" ";
         a = a->nxt;
      }
      cout<<"\n";
   }
};

int main()
{
   LinkedList ln;
   ln.InsertAtHead(30);
   ln.InsertAtHead(10);
   ln.InsertAtHead(5);
   ln.Traverse();

   ln.InsertAfterValue(10, 500);
   ln.Traverse();
   return 0;
}
