#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int maze[N][N], visited[N][N], level[N][N], steps[N][N];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
string dir = "DURL";

bool is_valid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != -1);
}

bool bfs(pair<int,int> src){
  queue<pair<int, int>> q;
  q.push(src);
  visited[src.first][src.second] = 1;
  level[src.first][src.second] = 0;

  while(!q.empty()) {
    pair<int, int> head = q.front();
    q.pop();

    for (int i = 0; i < 4; i++){
      int new_x = head.first + dx[i];
      int new_y = head.second + dy[i];
      if (maze[new_x][new_y] == 'A')
        return true;
      if(is_valid(new_x, new_y) && !visited[new_x][new_y]) {
        visited[new_x][new_y] = 1;
        steps[new_x][new_y] = i;
        level[new_x][new_y] = level[head.first][head.second] + 1;
        q.push({new_x, new_y});
      }
    }
  }

  return false;
}

int main () {
  cin >> n >> m;
  pair<int, int> src, dst;
  memset(level, -1, sizeof(level));

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      if(str[j] == '#' || str[j] == 'M') {
        maze[i][j] = -1;
      } else if(str[j] == 'A') {
        src = {i, j};
      } 

    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(is_valid(i, j) && !visited[i][j]) {
        // this condition is to check if the current cell is on the border of the maze or not
        if((i == 0 && j <= m) || (i == n-1 && j <= m) || (j == 0 && i <= n) || (j == m-1 && i <= n)) {
          bool found = bfs({i, j});
          if(found) {
            dst = {i, j};
          } else {
            dst = {-1, -1};
          }
        }
      }
    }
  }

  if(level[src.first][src.second] == -1) {
    cout << "NO";
  } else {
    cout << "YES" << "\n";
    cout << level[src.first][src.second] << "\n";
    vector<int> ans;
    while(src != dst) {
      int pos = steps[src.first][src.second];
      // cout << "Position: " << pos << "\n";
      ans.push_back(pos);
      src.first = src.first + dx[pos];
      src.second = src.second + dy[pos];
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
      cout << dir[i];
    }
      cout << "\n";
  };

  
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout<<steps[i][j]<<"\t";
  //   }
  //   cout << "\n";
  // }
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