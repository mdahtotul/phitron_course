// cses counting room problem link: https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int maze[N][N], visited[N][N];
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool is_valid(pair<int, int> pos) {
  int x = pos.first;
  int y = pos.second;
  if(x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != -1)
    return true;
  else
    return false;
}

void bfs(pair<int, int>src) {

  queue<pair<int, int>> q;

  visited[src.first][src.second] = 1;
  q.push(src);

  while (!q.empty()) {
    pair<int, int> head = q.front();
    q.pop();

    int x = head.first;
    int y = head.second;
    for (int i = 0; i < 4; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];
      if(visited[new_x][new_y] == 0 && is_valid({new_x, new_y})) {
        visited[new_x][new_y] = 1;
        q.push({new_x, new_y});
      }
    }
  }
}

pair<int, int> find_unvisited() {
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++) {
      if(is_valid({i, j}) && visited[i][j] == 0 && maze[i][j] == 0) {
        return {i, j};
      }
    }
  }

  return {-1, -1};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++){
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      if (str[j] == '#')
        maze[i][j] = -1;
    }
  }

  int room = 0;
  while(1) {
    pair<int, int> unvisited_pos = find_unvisited();
    if(unvisited_pos == pair<int, int>(-1, -1))
      break;

    bfs(unvisited_pos);
    room++;
  }

  cout<<room;

  return 0;
}

/*
5 8
########
#..#...#
####.#.#
#..#...#
########
*/