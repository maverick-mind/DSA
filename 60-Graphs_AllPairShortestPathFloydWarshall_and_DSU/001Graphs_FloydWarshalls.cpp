/*

note : nodes are numbered from 1 to n

floyd-warshall's algorithm

e.g.

input :

4 5
1 2 8
1 3 1
1 4 5
2 4 2
3 4 3

output :

0 6	1 4
6 0	5 2
1 5	0 3
4 2	3 0

*/


#include<bits/stdc++.h>
using namespace std;
 

// INFINITY can be defined as a macro by <cmath> / C math headers on implementations that provide it. for ex : #include <cmath>  cout << INFINITY; // may work and represent positive floating-point infinity.

// const int INFINITY = 1e9; // can potentially cause a macro conflict, depending on your environment.

const int INF = 1e9 ; // e notations are double by default

 
int main() 
{
    int n ; // number of vertices 
    int m ; // number of edges 

    cin >> n >> m ;

    vector<vector<int>> edges ; // edge list representation of a graph
    // edge list representation should be used when we think , there is a need to access edge more efficiently 
    
    // edge[0] : node i
    // edge[1] : node j
    // edge[2] : edge weight

    for (int i = 0; i < m; i++)
    {
        int u ; // node u
        int v ; // node v
        int edgeWeight ;

        cin >> u >> v >> edgeWeight ;

        edges.push_back({u , v , edgeWeight}) ;
        // edges.push_back({v , u , edgeWeight}) ; // for undirected graph : either insert both 
        // OR insert one edge and fill dp as : dp[u][v][0] = edgeWeight ; 
                                             //dp[v][u][0] = edgeWeight ; 
    }

    cout<<endl;


    // now traverse to all the edges , and fill the dp matrix 
    // for undirected graph : dp[u][v][0] = edgeWeight ; 
    //                        dp[v][u][0] = edgeWeight ; // comment this out if the graph is directed

    vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(n+1 , vector<int>(n+1 , INT_MAX))) ; // // INT_MAX will help to know , if there is no paths between 2 nodes 

    for (int i = 1; i < n+1; i++)
    {
        dp[i][i][0] = 0 ; // distance between vertex i and itself is : 0
    }

    // for (int k = 0; k <= n; k++) // k is the number of intermediate nodes 
    // {   // between [i and j] in their shortest path , 
        // also the value(labelling) of intermediate node should not exceed k

        // initially , k is 0 , it means no intermediate nodes between [i,j] , so node [i and j] should be directly connected through an edge
        
    // }

    // initialisation : k is 0 , it means no intermediate nodes between [i,j] , so node [i and j] should be directly connected through an edge


    
    // for(auto [i , j , edgeWeight] : edge)
    // { // vector does not support structured binding 
    //   // Structured bindings require a compile-time known structure, such as array, tuple, pair, or a struct.

    //   vector<array<int, 3>> v(n); // this will work
    //   for (auto [i, j, k] : v) { 
    //       cout << i << " " << j << " " << k;
    //   }
    // }


    for(vector<int>  edge : edges)
    {
        int i = edge[0] ;
        int j = edge[1] ;
        int edgeWeight = edge[2] ;


        // go to the [i][j][0]th cell of the dp and initialise it with edgeWeight because between [i and j] there exist a shortest path with 0 intermediate vertices.

        dp[i][j][0] = min(dp[i][j][0] , edgeWeight) ; // min() ensures we are considering minimum weight edges among all the parallel edges between node i and j
        dp[j][i][0] = min(dp[j][i][0] , edgeWeight) ; // comment this out if the graph is directed
    }

/* 
Shortest i → j using vertices 1...k
        =
min(
    shortest i → j using vertices 1...k-1,

    shortest i → k using vertices 1...k-1
    +
    shortest k → j using vertices 1...k-1
)

*/

    // time: O(n^3)
    // space : O(n^3)
    for (int k = 1; k < n + 1; k++)
    {
        for(int i = 1 ; i < n + 1 ; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                dp[i][j][k] = min(dp[i][j][k-1] , dp[i][k][k-1] + dp[k][j][k-1]) ;
            }
        }
    }

    // the final answer would be in dp[][][n]

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cout<<dp[i][j][n]<<" ";
        }cout<<endl;
    }

    return 0 ;
}       