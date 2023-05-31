#include <bits/stdc++.h>
using namespace std;

/**
   @TimeComplexity - O(n^2)
   @SpaceComplexity - O(n^2)
*/

void dfs( int** matrix, int n, int src, int* vis ) {
   cout<<src<<"\n";
   vis[src] = 1;
   for( int i=0; i<n; i++ ) { // TC: O(n) ; SC: o(n)
      if( matrix[src][i] == 1 ) {
         if( vis[i] ) {
            continue;
         }
         dfs( matrix, n, i, vis );
      }
   }
}

int main() {
   int nodes; // TC: O(1) ; SC: o(1)
   cout<<"Nodes : ";
   cin>>nodes;
   int edges; // TC: O(1) ; SC: o(1)
   cout<<"Edges : ";
   cin>>edges;

   int** matrix = new int*[nodes];
   for( int i=0; i<nodes; i++ ) { // TC: O(n^2) ; SC: o(n^2)
      matrix[i] = new int[nodes];
      for( int j=0; j<nodes; j++ ) {
         matrix[i][j] = 0;
      }
   }

   cout<<"\nProvide edge connection a & b\n";
   for( int i=0; i<edges; i++ ) { //O(E)
      int u, v;
      cin>>u>>v;
      matrix[u][v] = 1;
      matrix[v][u] = 1;
   }

   for( int i=0; i<nodes; i++ ) { //O(n^2)
      for( int j=0; j<nodes; j++ ) {
         cout<<matrix[i][j]<<" ";
      }
      cout<<"\n";
   }
   int* visited_arr = new int[nodes];
   for( int j=0; j<nodes; j++ ) { // TC: O(n) ; SC: o(n)
      visited_arr[j] = 0;
   }

   dfs( matrix, nodes, 2, visited_arr ); // 0 1 2 3 4 5

   delete matrix;
   delete visited_arr;
   return 0;
}


/*

0----1----2----3
     |    |
     |    |
     5----4

   6 6

   0 1
   2 3
   1 5
   2 4
   5 4
   1 2
*/

