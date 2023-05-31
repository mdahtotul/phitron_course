// Labyrinth CSES problem set link: https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int maze[N][N], visited[N][N], level[N][N];
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<char> direction = {'R', 'L', 'D', 'U'};

bool is_valid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != -1);
}

void dfs( pair<int, int> root) {
  int x = root.first, y = root.second;
  visited[root.first][root.second] = 1;

  for (int i = 0; i < 4; i++) {
    int new_x = x + dx[i];
    int new_y = y + dy[i];
    if (maze[new_x][new_y] == 'B')
      break;

    if (is_valid(new_x, new_y) && visited[new_x][new_y] == 0)
    {
      visited[new_x][new_y] = 1;
      level[new_x][new_y] = level[x][y] + 1;
      dfs({new_x, new_y});
    }
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> m;

  pair<int, int> src, dst;
  memset(level, -1, sizeof(level));

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      if(str[j] == '#')
        maze[i][j] = -1;
      else if (str[j] == 'A')
        src = {i, j};
      else if (str[j] == 'B')
        dst = {i, j};
    }
  }
  level[src.first][src.second] = 0;
  dfs(src);


  if(level[dst.first][dst.second] == -1)
    cout << "NO" << "\n";
  else {
    cout << "YES" << "\n";
    cout << level[dst.first][dst.second] << "\n";
  }


    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     cout << maze[i][j] << "\t ";
    //   }
    //   cout << "\n";
    // }

    return 0;
}

/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/
