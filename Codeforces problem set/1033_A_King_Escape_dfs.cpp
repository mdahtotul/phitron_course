// https://codeforces.com/problemset/problem/1033/A
#include <bits/stdc++.h>
using namespace std;

const int N = 1002;
int chess[N][N];
int n;
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

bool is_valid(int x, int y) {
  return (x > 0 && x <= n && y > 0 && y <= n && chess[x][y] != -1 && chess[x][y] == 0);
}

void dfs(int x, int y) {
  chess[x][y] = 1;
  for (int i = 0; i < 8; i++) {
    int new_x = x + dx[i];
    int new_y = y + dy[i];
    if(is_valid(new_x, new_y))
      dfs(new_x, new_y);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  int  ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;

  for (int i = 0; i < 8; i++) {
    chess[ax+dx[i]][ay+dy[i]] = -1;
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      // set diagonal elements to -1
      if(i-j == ax-ay || i+j == ax+ay || i == ax || j == ay) {
        chess[i][j] = -1;
      }
    }
  }

  dfs(bx, by);


  if(chess[cx][cy] == 1) 
    cout<<"YES\n";
  else
    cout<<"NO\n";

  return 0;
}

/*
8
4 4
1 3
3 1
*/