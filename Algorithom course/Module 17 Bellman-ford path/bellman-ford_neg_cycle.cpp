// cses cycle finding problem link: https://cses.fi/problemset/task/1197

#include  <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];
long long dist[N];
int parent[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++)
    dist[i] = INF;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj_list[u].push_back({v, w});
  }

  bool neg_cycle = false;
  int last_updated_node = -1;

  for (int i = 1; i <= n; i++){
    for (int node = 1; node <= n; node++) {
      for(pair<int, int>adj_node: adj_list[node]) {
        int u = node;
        int v = adj_node.first;
        int w = adj_node.second;

        if(dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          parent[v] = u;
          if(i == n) {
            neg_cycle = true;
            last_updated_node = v;
          }
        }
      }
    }
  }

  if(neg_cycle) {
    cout << "Yes\n";
    int selected_node = last_updated_node;
    for (int i = 1; i <= n - 1; i++) {
      selected_node = parent[selected_node];
    }

    int first_node = selected_node;
    vector<int> cycle;
    cycle.push_back(selected_node);

    while(1){
      selected_node = parent[selected_node];
      cycle.push_back(selected_node);
      if(selected_node == first_node)
        break;
    }
    reverse(cycle.begin(), cycle.end());
    for(auto node: cycle)
      cout << node << " ";

  } else {
      cout << "No\n";
  }

  return 0;
}

/*
Input:
--------
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

Output:
--------
Yes
1 2 4 1

Input:
--------
5 7
1 2 3
1 3 2
2 3 1
2 4 -8
4 1 2
2 5 5
4 5 2

Output:
--------
Yes

*/