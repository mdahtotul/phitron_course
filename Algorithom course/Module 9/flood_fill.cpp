/*
Problem: https://cses.fi/problemset/task/1192
5 8
########
#..#...#
####.#.#
#..#...#
########

*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 1005;

int maze[mx][mx], visited[mx][mx], level[mx][mx];
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> loc) {
  int x = loc.first;
  int y = loc.second;
  if(x >= 0 && x < n && y >= 0 && y < m) {
    return true;
  }
  return false;
}

bool is_safe(pair<int, int> loc) {
  int x = loc.first;
  int y = loc.second;
  if(maze[x][y] == -1) {
    return false;
  }
  return true;
}

void bfs(pair<int, int> src) {
  queue<pair<int, int>> q;
  visited[src.first][src.second] = 1;

  q.push(src);

  while(!q.empty()) {
    pair<int, int> head = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int new_x = head.first + dx[i];
      int new_y = head.second + dy[i];

      pair<int, int>adj_node = {new_x, new_y};

      if(is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y] == 0) {
        visited[new_x][new_y] = 1;
        q.push(adj_node);
      }
    }
  }
}

pair<int, int> find_unvisited(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(visited[i][j] == 0 && maze[i][j] == 0) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

int main(){
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    string input;
    cin >> input;
    for(int j = 0; j < m; j++){
      if(input[j] == '#') {
        maze[i][j] = -1;
      }
    }
  }

  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < m; j++){
  //     cout << maze[i][j] << "\t";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
  int room;
  while(1) {
    pair<int, int>unvisited_pos = find_unvisited();
    if(unvisited_pos == pair<int, int>(-1, -1))
     break;
    bfs(unvisited_pos);
    room++;
  }

  cout << room << "\n";

  return 0;
}