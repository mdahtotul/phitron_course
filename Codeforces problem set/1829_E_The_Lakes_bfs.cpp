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

int bfs(int x, int y, int n, int m, int ans) {
  queue<pair<int, int>> q;
  q.push({x, y});

  while(!q.empty()) {
    pair<int, int> head = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int new_x = head.first + dx[i];
      int new_y = head.second + dy[i];

      if(is_valid(new_x, new_y, n, m)) {
        int new_ans = ans + lake[new_x][new_y];
        ans = max(ans, new_ans);
        visited[new_x][new_y] = 1;
        q.push({new_x, new_y});
      }
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    memset(visited, 0, sizeof(visited));
    memset(lake, 0, sizeof(lake));
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> lake[i][j];
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if(is_valid(i, j, n, m)) {
          ans = max(ans, bfs(0, 0, n, m, ans));
        }
      }
    }
    cout<< ans << "\n";

  }

  return 0;
}
/*
5
3 3
1 2 0
3 4 0
0 0 5
1 1
0
3 3
0 1 1
1 0 1
1 1 1
5 5
1 1 1 1 1
1 0 0 0 1
1 0 5 0 1
1 0 0 0 1
1 1 1 1 1
5 5
1 1 1 1 1
1 0 0 0 1
1 1 4 0 1
1 0 0 0 1
1 1 1 1 1
*/