// not working for Message Route - CSES Problem Set link: https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;

void printPath(vector<int> stack) {
  cout << stack.size() << endl;
  for(int i = 0; i < stack.size() - 1; i++) {
    cout << stack[i] << " -> ";
  }
  cout << stack[stack.size() - 1] << endl;
}

void DFS(vector<int> adj_list[], int src, int dst, int visited[], vector<int> stack) {
  stack.push_back(src);
  // when src and dst are the same, print the path and break the recursion
  if(src == dst) {
    printPath(stack);
    return;
  }
  visited[src] = 1;
  // check if the src node has any child
  if(!adj_list[src].empty()) {
    // traverse through all the child nodes of the src node
    for(int child: adj_list[src]) {
      // check if the child node is not visited
      if(!visited[child])
        DFS(adj_list, child, dst, visited, stack);
    }
  }
  // pop the last element from the stack
  stack.pop_back();
}

void invokeDFS(vector<int> adj_list[], int src, int dst, int nodes, vector<int> stack) {
  // initialize the visited array to store the visited status of each node
  int visited[nodes + 1];
  // making all the nodes unvisited
  memset(visited, 0, sizeof(visited));
  DFS(adj_list, src, dst, visited, stack);
}

void connectEdge(vector<int> adj_list[], int u, int v) {
  adj_list[u].push_back(v);
  adj_list[v].push_back(u);
}

int main() {
  int nodes, edges;
  cin >> nodes >> edges;

  vector<int> adj_list[nodes + 1], stack;

  for(int i = 0; i < edges; i++) {
    int u, v;
    cin >> u >> v;
    connectEdge(adj_list, u, v);
  }
  invokeDFS(adj_list, 4, 8, nodes, stack);
  return 0;
}

/*
10 8
1 2
1 3
2 4
2 5
2 6
3 7
3 8
3 9
*/