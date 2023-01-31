#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>

int print(int n)
{
    if(n==0)
        return 0;
    print(n-1);
    cout<<n<<" ";
}
int main(){
  print(5);

    return 0;
}
