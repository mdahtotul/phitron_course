#include <bits/stdc++.h>
using namespace std;
#define nl '\n';

int findKing (vector<int>& nums, int n, int sum) {
  int sumL = 0;

  for (int i = 0; i<n; i++) {
    // 28 - 11 - 6
    int sumR = sum - sumL - nums[i];

    if(sumL == sumR)
      return i;

    sumL += nums[i];
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin>>t;

  while(t--) {
    int n, sum=0, sumL=0, sumR=0;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
      sum += nums[i];
    }

    int kingga = findKing(nums, n, sum);
    cout << kingga << nl;
  }
  return 0;
}

/*
Input:
3
6
1 7 3 6 5 6
3
1 2 3
3
2 1 -1

Output:
3
-1
0
*/