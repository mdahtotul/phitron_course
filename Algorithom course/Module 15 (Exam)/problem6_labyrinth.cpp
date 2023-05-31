#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

char maze[N][N], steps[N][N];
int visited[N][N], level[N][N];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<char> path;

bool is_valid(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m) {
    if(maze[x][y] == '#' || maze[x][y] == 'M') 
      return false;
    else
      return true;
  }
  return false;
}
// this condition is to check if the current cell is on the border of the maze or not
bool is_border_cell(int i, int j) {
  if((i == 0 && j <= m) || (i == n-1 && j <= m) || (j == 0 && i <= n) || (j == m-1 && i <= n))
    return true;
  else
    return false;
}

void printPath(pair<int, int> src, int x, int y) {
  int run = level[src.first][src.second] + 1;
  while(run--) {
    cout << steps[x][y] << "";
    if(steps[x][y] == 'R') {
      y++;
    } else if(steps[x][y] == 'L') {
      y--;
    } else if(steps[x][y] == 'U') {
      x--;
    } else if(steps[x][y] == 'D') {
      x++;
    }
  }
}

bool bfs(pair<int, int> src, pair<int, int> dst){
  queue<pair<int, int>> q;
  q.push(dst);
  visited[dst.first][dst.second] = 1;
  level[dst.first][dst.second] = 0;

  while(!q.empty()) {
    pair<int, int> head = q.front();
    q.pop();

    int row = head.first;
    int col = head.second;
    for (int i = 0; i < 4; i++){
      int x = row + dx[i];
      int y = col + dy[i];
      if(is_valid(x, y) && !visited[x][y]) {
        if(i == 3) {
          steps[x][y] = 'R';
        } else if(i == 2) {
          steps[x][y] = 'L';
        } else if(i == 1) {
          steps[x][y] = 'D';
        } else if(i == 0) {
          steps[x][y] = 'U';
        }

        visited[x][y] = 1;
        level[x][y] = level[row][col] + 1;
        q.push({x, y});
      }

      if(maze[x][y] == 'A') {
        return true;
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;
  pair<int, int> src, dst;
  memset(level, -1, sizeof(level));

  for (int i = 0; i < n; i++){
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      maze[i][j] = str[j];
      if(str[j] == 'A') {
        src = {i, j};
      }
    }
  }

  bool src_found = false;

  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < m; j++) {
      if(is_valid(i, j) && is_border_cell(i, j) && !visited[i][j]) {
        src_found = bfs(src, {i, j});
      }
    }
  }

  if(level[src.first][src.second] == -1)
    cout << "NO\n";
  else {
    cout << "YES\n";
    cout << level[src.first][src.second] << "\n";
    printPath(src, src.first, src.second);
  }
  cout << "\n";

  return 0;
}

/*
Input:
5 8
..######
#M..A..#
#.#.M#.#
#M#..#..
..#.####

Output:
YES
5
RRDDR
*/