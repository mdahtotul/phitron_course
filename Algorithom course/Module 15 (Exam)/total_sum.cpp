#include <bits/stdc++.h>
using namespace std;

int get_sum(int arr[], int n, int sum) {
  if(n == 0){
    return sum;
  }
  sum += arr[n - 1];
  return get_sum(arr, n - 1, sum);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  int total = 0;
  total = get_sum(arr, n, total);

  cout << total << "\n";

  return 0;
}