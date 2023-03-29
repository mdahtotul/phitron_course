// not working for Message Route - CSES Problem Set link: https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj_list[], int src, int lv, int par, int level[], int parent[]) {
  level[src] = lv;
  parent[src] = par;

  for(int child: adj_list[src]) {
    if(child != par)
      dfs(adj_list, child, lv + 1, src, level, parent);
  }
}

int LCA(int src, int dst, int level[], int parent[]) {
  // if src node is at deeper level than the dst node, swap them
  if(level[src] > level[dst])
    swap(src, dst);
  // find the difference in the level of the src and dst node
  int diff = level[dst] - level[src];
  // move the dst node to the same level as the src node
  while (diff != 0) {
    dst = parent[dst];
    diff--;
  }
  // if the src and dst node are the same, return the src node
  if(src == dst)
    return src;
  // finding the lowest common ancestor of the src and dst node
  while (src != dst) {
    src = parent[src];
    dst = parent[dst];
  }

  return src;
}

void printPath(vector<int> adj_list[], int root, int dst, int nodes) {
  // initialize the level array to store the level of each node
  int level[nodes + 1];
  // initialize the parent array to store the parent of each node
  int parent[nodes + 1];
  // running dfs to find the level and parent of each node
  dfs(adj_list, 1, 0, -1, level, parent);
  // finding the lowest common ancestor of the root and the destination node
  int lca = LCA(root, dst, level, parent);
  // stores path between the root and the destination node
  vector<int> path;
  // traversing from the root to the lca node
  while (root != lca) {
    path.push_back(root);
    root = parent[root];
  }
  // sending root to the path vector
  path.push_back(root);

  vector<int> temp;
  // traversing from the destination node to the lca node
  while (dst != lca) {
    temp.push_back(dst);
    dst = parent[dst];
  }

  // reversing the path to get actual path
  reverse(temp.begin(), temp.end());
  
  for (int x : temp) 
    path.push_back(x);

  for (int i = 0; i < path.size() - 1; i++)
    cout << path[i] << " -> ";

  cout << path[path.size() - 1] << endl;
}

void connectEdge(vector<int> adj_list[], int u, int v) {
  adj_list[u].push_back(v);
  adj_list[v].push_back(u);
}

int main() {
  int nodes, edges;
  cin >> nodes >> edges;

  vector<int> adj_list[nodes + 1]; // initialize the adjacency list

  for (int i = 0; i < edges; i++) {
    int u, v;
    cin >> u >> v; // store the edges of the graph
    connectEdge(adj_list, u, v);
  }

  // travel from the root node to the destination node
  int root = 1;
  int dst = nodes;

  // remember to change the root and destination node according to input
  printPath(adj_list, root, dst, nodes);

  return 0;
}

/*
Input:
8 7
1 2
1 7
2 3
2 6
3 4
3 8
3 5

Output: (root 4 and dst 7)
4 -> 3 -> 2 -> 1 -> 7
*/