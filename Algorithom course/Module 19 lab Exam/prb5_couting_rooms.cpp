#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int maze[N][N], vis[N][N];

int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool is_valid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != -1);
}

int bfs(pair<int, int> src) {
  queue<pair<int, int>> q;
  int length = 1;
  vis[src.first][src.second] = 1;
  q.push(src);
  while(!q.empty()) {
    pair<int, int> head = q.front();
    q.pop();

    int a = head.first;
    int b = head.second;

    for (int i = 0; i < 4; i++) {
      int x = a + dx[i];
      int y = b + dy[i];
      if(is_valid(x, y) && !vis[x][y]) {
        vis[x][y] = 1;
        length++;
        q.push({x, y});
      }
    }
  }
  return length;
}

pair<int, int> find_unvisited() {
  for (int i = 0; i < n; i++){
    for (int j = 0; j<m; j++) {
      if(is_valid(i, j) && !vis[i][j] && maze[i][j] == 0){
        return {i, j};
      }
    }
  }

  return {-1, -1};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      if(str[j] == '#')
        maze[i][j] = -1;
    }

  }
  int room = 0;
  int room_len = 0;
  while(1) {
    pair<int, int> unvis_pos = find_unvisited();
    if(unvis_pos == pair<int,int>(-1,-1))
      break;
    int ans;
    ans = bfs(unvis_pos);
    room_len < ans ? room_len = ans : ans;
    room++;
  }

  cout << "Rooms - " << room << "\n";
  cout << "Length of the longest room - " << room_len << "\n";
  return 0;
}
/*
Input:
------
5 8
########
#..#...#
#.##.#.#
.#.#...#
#.######

Output:
--------
Rooms - 5
Length of the longest room - 8
*/