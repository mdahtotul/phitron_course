
/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
string steps_direction = "DURL";

int n, m;
char grid[maxn][maxn];
int visited[maxn][maxn], previous_step[maxn][maxn];

bool is_valid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#');
}

void bfs(pair<int, int> start_pos) {
  queue<pair<int, int>> q;
  q.push({start_pos.first, start_pos.second});
  visited[start_pos.first][start_pos.second] = 1;
  while (!q.empty()) {
    pair<int, int> top = q.front();
    q.pop();
    int x = top.first, y = top.second;
    for (int i = 0; i < 4; ++i) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      if (!is_valid(new_x, new_y) || visited[new_x][new_y]) {
        continue;
      }
      q.push({new_x, new_y});
      visited[new_x][new_y] = 1;
      previous_step[new_x][new_y] = i;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      visited[i][j] = 0;
    }
  }
  pair<int, int> start_pos, end_pos;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'A') {
        start_pos = {i, j};
      }
      else if (grid[i][j] == 'B') {
        end_pos = {i, j};
      }
    }
  }
  bfs(start_pos);
  if (!visited[end_pos.first][end_pos.second]) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
    vector<int> ans;
    while (end_pos != start_pos) {
      int p = previous_step[end_pos.first][end_pos.second];
      ans.push_back(p);
      end_pos.first = end_pos.first - dx[p];
      end_pos.second = end_pos.second - dy[p];
    }
    reverse(ans.begin(), ans.end());
    cout << (int)ans.size() << '\n';
    for (auto& x: ans) {
      cout << steps_direction[x];
    }
    cout << '\n';
  }
  return 0;
}
