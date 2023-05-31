// https://leetcode.com/problems/candy/

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;

class Solution {
public:
    int candy(vector<int>& ratings) {
      int n = ratings.size(), sum = 0;
      vector<int> candies(n, 1);

      for (int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i-1]) {
          candies[i] = candies[i-1] + 1;
        }
      }

      for (int j = n - 2; j >= 0; j--) {
        if(ratings[j] > ratings[j+1]) {
          candies[j] = max(candies[j], candies[j+1] + 1);
        }
      }

      for (int i = 0; i < n; i++)
        sum += candies[i];
      
      return sum;
    }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  Solution s;
  // vector<int> ratings = {1, 0, 2};
  // vector<int> ratings = {1, 2, 2};
  vector<int> ratings = {1, 3, 2, 2, 1};

  cout << s.candy(ratings) << endl;
  return 0;
}