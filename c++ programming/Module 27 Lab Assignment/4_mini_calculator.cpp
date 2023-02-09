#include <bits/stdc++.h>
using namespace std;

// converting string into number
int getNum( char c ) {
   int value;
   value = c;
   int val = int(value-'0');
   return val;
}

// checking operator
int isOperator( char ch ) {
   if( ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^' )
      return 1;
   return -1;
}

// checking operand
int isOperand( char ch ) {
   if( ch >= '0' && ch <= '9' )
      return 1;
   return -1;
}

// all types of operation
int operation( int a, int b, char sign ) {
   int val;
   if( sign == '+' )
      val = b+a;
   else if( sign == '-' )
      val = b-a;
   else if( sign == '*' )
      val = b*a;
   else if( sign == '/' )
      val = b/a;
   else if( sign == '^' )
      val = pow( b,a );
   else
      val = INT_MIN; //neg infinity

   return val;
}

// getting precision
int prec( char ch ) {
   if( ch == '-' || ch == '+' )
      return 1;
   else if( ch == '*' || ch == '/' )
      return 2;
   else if( ch == '^' )
      return 3;
   else
      return 0;
};

// postfix evaluation function
int evaluation( string str ) {
   stack<int> st2;

   for( int i=0; i<str.size(); i++ ) {
      char ch = str[i];
      // if character is operand push it to stack
      if( isOperand( ch ) > 0 )
         st2.push( getNum( ch ) );
      else if( isOperator( ch ) != -1 ) {
         // if character is not operand take first two items and do math calculation then push it to stack
         int num1 =  st2.top() ;
         st2.pop();
         int num2 = st2.top() ;
         st2.pop();
         st2.push(operation(num1, num2, ch));
      }
   }

   return st2.top();
}

int main() {
   string s;
   cin>>s;

   stack<char> st;
   string ans;
   for( int i=0; i<s.size(); i++ ) {
      char now = s[i];

      if( ( now >= 'a' && now <= 'z' ) || ( now >= 'A' && now <= 'Z' ) || ( now>='0' && now<='9' ) )
         ans+= now;
      else if( now == '(' )
         st.push( now );
      else if( now == ')' ) {
         while( st.top() != '(' ) {
            ans += st.top();
            st.pop();
         }
         st.pop();
      } else {
         while( st.size() && prec( st.top() ) >= prec( now ) ) {
            ans+= st.top();
            st.pop();
         }
         st.push( now );
      }
   }

   while( st.size() ) {
      ans += st.top();
      st.pop();
   }

   cout<<evaluation(ans)<<"\n";
   return 0;
}
