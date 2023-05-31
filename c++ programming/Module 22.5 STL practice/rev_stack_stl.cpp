#include <bits/stdc++.h>
using namespace std;

void printStack( stack<int> s ) {
   // If stack is empty then return
   if ( s.empty() )
      return;

   int x = s.top();
   s.pop();
   printStack( s );

   cout << x << " ";
   s.push( x );
}

int main() {
   stack<int> st;
   st.push( 3 );
   st.push( 4 );
   st.push( 6 );
   st.push( 2 );
   st.push( 5 );
   printStack( st );
   cout<<"\n";

   stack<int> tmp;

   while( st.size() > 0 ) {
      int topVal = st.top();
      st.pop();

      while( tmp.size() > 0 ) {
         if( tmp.top() < topVal )
            break;
         st.push( tmp.top() );
         tmp.pop();
      }
      tmp.push( topVal );
   }
   swap( st, tmp );
   printStack( st );
   return 0;
}

/*
Steps to sort one stack using another step:

Create two stacks for int data. Stack<int> st and Stack<int> tmp;
Push data (5 → 2 → 6 → 4 → 3) at the head of the stack one by one.
Scan all of the elements using a while loop (Loop - 1). Loop will execute if the stack size > 0. In this loop, 3 types of operation will execute.
Operation-1: We will store the top element (int topVal) from the stack in a variable and remove that top element from the stack.
Operation-2: We will use another while loop (Loop - 2) for Stack<int> tmp. Loop will execute if the tmp stack size > 0. In this loop, 2 types of operation will execute.
If the top element of tmp stack < the top element of st stack then do nothing and break the while loop.
Otherwise, push the top element of tmp stack in the st stack and pop that top element from tmp stack
Operation-3: Push the top element of st stack in the tmp stack.
Now swap the tmp stack with the st stack.
Create a void function to print all of the stack elements.

Steps to sort one stack using another step: [3,4,6,2,5]

In step 1:
stack<int> st; stack<int> tmp;
Creating two different stacks.
In step 2:
st.push( 3 );
st.push( 4 );
st.push( 6 );
st.push( 2 );
st.push( 5 );
Push all elements to the stack.
st = [ 3, 4, 6, 2, 5 ];
tmp = [ ];
In step 3:
st = [ 3, 4, 6, 2, 5 ];
tmp = [ ];
Scan every element of the stack and complete step 4 and step 5 and step 6

In step 4:
Store the top value (5) from st stack in the topVal variable and remove that top value from st stack.
st = [ 3, 4, 6, 2 ];
topVal = 5;
tmp = [ ];
In step 5:
Step 5 loop will not execute because tmp stack is empty.
st = [ 3, 4, 6, 2 ];
topVal = 5;
tmp = [ ];
In step 6:
Push the top value (5) in the tmp stack.
st = [ 3, 4, 6, 2 ];
topVal = 5;
tmp = [ 5 ];

Again in step 4:
Store the top value (2) from st stack in the topVal variable and remove that top value from st stack.
st = [ 3, 4, 6 ];
topVal = 2;
tmp = [ 5 ];
Again in step 5:
Step 5 loop will execute because tmp stack is not empty.
Here topVal < top element of tmp stack. So, we will push the top element of tmp stack (5) in the st stack.
st = [ 3, 4, 6, 5 ];
topVal = 2;
tmp = [  ];
Again in step 6:
Push the top value (2) in the tmp stack.
st = [ 3, 4, 6, 5 ];
topVal = 2;
tmp = [ 2 ];

Again in step 4:
Store the top value (5) from st stack in the topVal variable and remove that top value from st stack.
st = [ 3, 4, 6 ];
topVal = 5;
tmp = [ 2 ];
Again in step 5:
Step 5 loop will execute because tmp stack is not empty.
Here topVal > top element of tmp stack. So, we will do nothing.
st = [ 3, 4, 6 ];
topVal = 5;
tmp = [ 2 ];
Again in step 6:
Push the top value (5) in the tmp stack.
st = [ 3, 4, 6 ];
topVal = 5;
tmp = [ 2, 5 ];

Again in step 4:
Store the top value (6) from st stack in the topVal variable and remove that top value from st stack.
st = [ 3, 4 ];
topVal = 6;
tmp = [ 2, 5 ];
Again in step 5:
Step 5 loop will execute because tmp stack is not empty.
Here topVal > top element of tmp stack. So, we will do nothing.
st = [ 3, 4 ];
topVal = 6;
tmp = [ 2, 5 ];
Again in step 6:
Push the top value (6) in the tmp stack.
st = [ 3, 4, 6 ];
topVal = 6;
tmp = [ 2, 5, 6 ];

Again in step 4:
Store the top value (4) from st stack in the topVal variable and remove that top value from st stack.
st = [ 3 ];
topVal = 4;
tmp = [ 2, 5, 6 ];
Again in step 5:
Step 5 loop will execute because tmp stack is not empty.
Here topVal < top element of tmp stack. So, we will push two elements ( 6 → 5) in the st stack.
st = [ 3, 6, 5 ];
topVal = 4;
tmp = [ 2 ];
Again in step 6:
Push the top value (4) in the tmp stack.
st = [ 3, 6, 5 ];
topVal = 4;
tmp = [ 2, 4 ];

Again in step 4:
Store the top value (5) from st stack int= the topVal variable and remove that top value from st stack.
st = [ 3, 6, 5 ];
topVal = 5;
tmp = [ 2, 4 ];
Again in step 5:
Step 5 loop will execute because tmp stack is not empty.
Here topVal > top element of tmp stack. So, we will do nothing but break the loop.
st = [ 3, 6 ];
topVal = 5;
tmp = [ 2, 4 ];
Again in step 6:
Push the top value (4) in the tmp stack.
st = [ 3, 6 ];
topVal = 5;
tmp = [ 2, 4, 5 ];

Again in step 4:
Store the top value (6) from st stack in the topVal variable and remove that top value from st stack.
st = [ 3  ];
topVal = 6;
tmp = [ 2, 4, 5 ];
Again in step 5:
Step 5 loop will execute because tmp stack is not empty.
Here topVal > top element of tmp stack. So, we will do nothing but break the loop.
st = [ 3 ];
topVal = 6;
tmp = [ 2, 4, 5 ];
Again in step 6:
Push the top value (4) in the tmp stack.
st = [ 3 ];
topVal = 5;
tmp = [ 2, 4, 5, 6 ];

Again in step 4:
Store the top value (3) from st stack in the topVal variable and remove that top value from st stack.
st = [  ];
topVal = 3;
tmp = [ 2, 4, 5, 6 ];
Again in step 5:
Step 5 loop will execute because tmp stack is not empty.
Here topVal < top element of tmp stack. So, we will push three elements ( 6 → 5 → 4 ) in the st stack.
st = [ 6, 5, 4 ];
topVal = 3;
tmp = [ 2 ];
Again in step 6:
Push the top value (3) in the tmp stack.
st = [ 6, 5, 4 ];
topVal = 3;
tmp = [ 2, 3 ];

Again in step 4:
Store the top value (4) from st stack in the topVal variable and remove that top value from st stack.
st = [ 6, 5 ];
topVal = 4;
tmp = [ 2, 3 ];
Again in step 5:
Here topVal > top element of tmp stack. So, we will do nothing but break the loop.
st = [ 6, 5 ];
topVal = 4;
tmp = [ 2, 3 ];
Again in step 6:
Push the top value (4) in the tmp stack.
st = [ 6, 5 ];
topVal = 4;
tmp = [ 2, 3, 4 ];

Again in step 4:
Store the top value (5) from st stack in the topVal variable and remove that top value from st stack.
st = [ 6 ];
topVal = 5;
tmp = [ 2, 3, 4 ];
Again in step 5:
Here topVal > top element of tmp stack. So, we will do nothing but break the loop.
st = [ 6 ];
topVal = 5;
tmp = [ 2, 3, 4 ];
Again in step 6:
Push the top value (4) in the tmp stack.
st = [ 6 ];
topVal = 5;
tmp = [ 2, 3, 4, 5 ];

Again in step 4:
Store the top value (6) from st stack in the topVal variable and remove that top value from st stack.
st = [  ];
topVal = 6;
tmp = [ 2, 3, 4, 5 ];
Again in step 5:
Here topVal > top element of tmp stack. So, we will do nothing but break the loop.
st = [  ];
topVal = 6;
tmp = [ 2, 3, 4, 5 ];
Again in step 6:
Push the top value (4) in the tmp stack.
st = [  ];
topVal = 6;
tmp = [ 2, 3, 4, 5, 6 ];
Now st stack is empty so loop (Loop -1) will be terminated and step 7 will begin.

In step 7:
st = [  ];
tmp = [ 2, 3, 4, 5, 6 ];
Now swap the st stack with tmp stack.
st = [ 2, 3, 4, 5, 6 ];
tmp = [  ];

In step 8:
Create a function to print all of the stack elements and print those elements to check sorted st stack.
st = [ 2, 3, 4, 5, 6 ];
At last, return the function.

*/
