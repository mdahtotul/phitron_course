#include <iostream>
using namespace std;
#define nl '\n';

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;

  int k = 0;
  for (int i = 1; i <= n*2; i+=2) {
    for (int j = n - i / 2; j > 1; j--) {
      cout << " ";
    }
    for (int j = 1; j<=i; j++) {
      k % 2 == 0 ? cout << ">" : cout << "<";
    }
    k++;
    cout << nl;
  }

  for (int i = (n * 2) - 3; i >= 1; i -= 2){
    for (int j = n - i / 2; j > 1; j--) {
      cout << " ";
    }
    for (int j = 1; j<=i; j++) {
      k % 2 == 0 ? cout << ">" : cout << "<";
    }
    k++;
    cout << nl;
  }

  return 0;
}