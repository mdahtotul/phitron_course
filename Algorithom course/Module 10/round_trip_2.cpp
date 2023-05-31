// Round Trip II problem set link : https://cses.fi/problemset/task/1678

/*
Input:
4 5
1 3
2 1
2 4
3 2
3 4

Output:
4
2 1 3 2

Input:
4 4
1 3
2 1
2 4
3 4

Output:
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> adj_list[N];

int visited[N];

// using dfs to detect cycle
bool dfs(int node) {
  visited[node] = 1;

  for(int child: adj_list[node]) {
    /*
      - visited[child] == 0 means that the child is not visited yet (unexplored node)
      - visited[child] == 1 means that the child is visited but not finished (paused node)
      - visited[child] == 2 means that the child is visited and finished (done node)
    */
    if(visited[child] == 0) {
      bool got_cycle = dfs(child);
      if(got_cycle) {
        return true;
      }
    } else if(visited[child] == 1) {
      return true;
    }
  }

  visited[node] = 2;
  return false;
}

int main(){
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v); //  u -> v
  }

  bool cycle_exists = false;

  for (int i = 1; i <= n; i++){
    if(visited[i] == 0) {
      bool got_cycle = dfs(i);
      if(got_cycle) {
        cycle_exists = true;
        break;
      }
    }
  }

  if(cycle_exists) {
    cout << "Cycle Exists!" << endl;
  } else {
    cout << "Cycle Not Found" << endl;
  }

  return 0;
}

/*
5 5
0 1
1 2
2 3
3 4
4 1

*/