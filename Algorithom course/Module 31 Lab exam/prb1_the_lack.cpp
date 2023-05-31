// https://codeforces.com/problemset/problem/1829/E
#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int lake[N][N], visited[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int is_valid(int x, int y, int n, int m) {
  return (x >= 0 && x < n && y >= 0 && y < m && lake[x][y] != 0 && !visited[x][y]);
}

int dfs(int x, int y, int n, int m, int ans) {
  visited[x][y] = 1;
  int val = lake[x][y];

  for (int i = 0; i < 4; i++) {
    int new_x = x + dx[i];
    int new_y = y + dy[i];

    if(is_valid(new_x, new_y, n, m)) {
      val += dfs(new_x, new_y, n, m, val);
    }
  }
  return val;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    memset(visited, 0, sizeof(visited));
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> lake[i][j];
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if(is_valid(i, j, n, m)) {
          ans = max(ans, dfs(i, j, n, m, 0));
        }
      }
    }
    cout<<ans << "\n";
  }

  return 0;
}